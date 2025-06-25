import { ref, computed, onMounted } from 'vue';
import { 
  getFriends,
  getPendingRequests,
  sendFriendRequest as sendFriendRequestAPI,
  acceptFriendRequest as acceptFriendRequestAPI,
  declineFriendRequest as declineFriendRequestAPI,
  removeFriend as removeFriendAPI,
  getFriendsOnlineStatus,
  type Friendship, 
  type FriendRequest, 
  type ApiResponse 
} from '../services/friendsAPI';

export function useFriends() {
  // État réactif
  const friends = ref<Friendship[]>([]);
  const pendingRequests = ref<FriendRequest[]>([]);
  const friendsOnlineStatus = ref<{ [userId: number]: { username: string; is_online: boolean; last_seen: Date | null } }>({});
  const isLoading = ref(false);
  const error = ref<string | null>(null);

  // Fonction pour obtenir l'ID de l'ami depuis une friendship
//   const getFriendUserId = (friendship: Friendship, currentUserId: number): number => {
//     return friendship.user_id1 === currentUserId ? friendship.user_id2 : friendship.user_id1;
//   };

  // Computed properties - Maintenant basé sur le vrai statut en ligne
  const onlineFriends = computed<Friendship[]>(() => {
    // On a besoin de l'ID de l'utilisateur actuel pour déterminer l'ami
    // Pour l'instant, on va utiliser une approche simplifiée
    return friends.value.filter(friendship => {
      // Chercher dans friendsOnlineStatus par username
      const friendUsername = friendship.friend.username;
      const statusEntry = Object.values(friendsOnlineStatus.value).find(
        status => status.username === friendUsername
      );
      return statusEntry?.is_online || false;
    });
  });

  const offlineFriends = computed<Friendship[]>(() => {
    return friends.value.filter(friendship => {
      const friendUsername = friendship.friend.username;
      const statusEntry = Object.values(friendsOnlineStatus.value).find(
        status => status.username === friendUsername
      );
      return !statusEntry?.is_online;
    });
  });

  const onlineFriendsCount = computed(() => onlineFriends.value.length);
  const totalFriendsCount = computed(() => friends.value.length);
  const pendingRequestsCount = computed(() => pendingRequests.value.length);

  // Méthodes
  const loadFriends = async () => {
    isLoading.value = true;
    error.value = null;
    
    try {
      const response = await getFriends();
      if (response.success) {
        friends.value = response.data || [];
        // Charger le statut en ligne après avoir chargé les amis
        await loadOnlineStatus();
      } else {
        error.value = response.error || 'Erreur lors du chargement des amis';
      }
    } catch (err: any) {
      error.value = err.message || 'Erreur lors du chargement des amis';
    } finally {
      isLoading.value = false;
    }
  };

  const loadPendingRequests = async () => {
    try {
      const response = await getPendingRequests();
      if (response.success) {
        pendingRequests.value = response.data || [];
      }
    } catch (err: any) {
      // Erreur silencieuse lors du chargement des demandes
    }
  };

  const loadOnlineStatus = async () => {
    try {
      const response = await getFriendsOnlineStatus();
      if (response.success && response.data) {
        friendsOnlineStatus.value = response.data.friends_status;
      }
    } catch (err: any) {
      console.warn('Failed to load online status:', err);
    }
  };

  const acceptRequest = async (requestId: number): Promise<ApiResponse> => {
    try {
      const response = await acceptFriendRequestAPI(requestId);
      if (response.success) {
        // Supprimer la demande de la liste
        pendingRequests.value = pendingRequests.value.filter(req => req.friendship_id !== requestId);
        // Recharger la liste des amis
        await loadFriends();
      }
      return response;
    } catch (err: any) {
      return {
        success: false,
        error: err.message || 'Erreur lors de l\'acceptation'
      };
    }
  };

  const rejectRequest = async (requestId: number): Promise<ApiResponse> => {
    try {
      const response = await declineFriendRequestAPI(requestId);
      if (response.success) {
        // Supprimer la demande de la liste
        pendingRequests.value = pendingRequests.value.filter(req => req.friendship_id !== requestId);
      }
      return response;
    } catch (err: any) {
      return {
        success: false,
        error: err.message || 'Erreur lors du rejet'
      };
    }
  };

  const removeFriendship = async (friendshipId: number): Promise<ApiResponse> => {
    try {
      const response = await removeFriendAPI(friendshipId);
      if (response.success) {
        // Supprimer l'ami de la liste
        friends.value = friends.value.filter(friendship => friendship.friendship_id !== friendshipId);
      }
      return response;
    } catch (err: any) {
      return {
        success: false,
        error: err.message || 'Erreur lors de la suppression'
      };
    }
  };

  const sendRequest = async (username: string): Promise<ApiResponse> => {
    try {
      return await sendFriendRequestAPI(username);
    } catch (err: any) {
      return {
        success: false,
        error: err.message || 'Erreur lors de l\'envoi de la demande'
      };
    }
  };

  const refreshData = async () => {
    await Promise.all([
      loadFriends(),
      loadPendingRequests()
    ]);
  };

  // Initialisation
  onMounted(() => {
    refreshData();
  });

  return {
    // État
    friends,
    pendingRequests,
    friendsOnlineStatus,
    isLoading,
    error,
    
    // Computed
    onlineFriends,
    offlineFriends,
    onlineFriendsCount,
    totalFriendsCount,
    pendingRequestsCount,
    
    // Méthodes
    loadFriends,
    loadPendingRequests,
    loadOnlineStatus,
    acceptFriendRequest: acceptRequest,
    rejectFriendRequest: rejectRequest,
    removeFriend: removeFriendship,
    sendFriendRequest: sendRequest,
    refreshData
  };
}