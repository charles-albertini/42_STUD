import { fetchWithAuth } from './api';

// Interfaces adapted to match backend responses
export interface User {
  user_id: number;
  username: string;
  display_name?: string;
  email?: string;
  avatar?: string;
  is_online?: boolean;
  last_seen?: string;
}

export interface Friendship {
  friendship_id: number;
  user_id1: number;
  user_id2: number;
  status: 'pending' | 'accepted'| 'none';
  creation_date: string;
  friend: {
    username: string;
  };
}

export interface FriendRequest {
  friendship_id: number;
  sender: {
    username: string;
  };
  creation_date: string;
  status: 'pending' | 'accepted' | 'rejected';
}

export interface ApiResponse<T = any> {
  success: boolean;
  data?: T;
  error?: string;
}

// Get user's friends list
export const getFriends = async (): Promise<ApiResponse<Friendship[]>> => {
  try {
    const response = await fetchWithAuth('/profile/friendList');
    return {
      success: true,
      data: response.friends || []
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to fetch friends'
    };
  }
};

// Get pending friend requests (sent BY the current user)
export const getPendingRequests = async (): Promise<ApiResponse<FriendRequest[]>> => {
  try {
    const response = await fetchWithAuth('/profile/friendRequest/pending');
    return {
      success: true,
      data: response.pending_requests || []
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to fetch friend requests'
    };
  }
};

// Send friend request
export const sendFriendRequest = async (username: string): Promise<ApiResponse<void>> => {
  try {
    await fetchWithAuth(`/profile/friendRequest/${username}`, {
      method: 'POST'
    });
    return {
      success: true
    };
  } catch (error) {
    
    // Gestion spécifique des erreurs
    let errorMessage = 'Échec de l\'envoi de la demande d\'ami';
    
    if (error instanceof Error) {
      const message = error.message.toLowerCase();
      
      if (message.includes('already friends') || message.includes('déjà ami')) {
        errorMessage = 'Vous êtes déjà ami avec cet utilisateur';
      } else if (message.includes('already sent') || message.includes('déjà envoyé')) {
        errorMessage = 'Demande d\'ami déjà envoyée';
      } else if (message.includes('not found') || message.includes('non trouvé')) {
        errorMessage = 'Utilisateur non trouvé';
      } else if (message.includes('declined') || message.includes('refusé')) {
        errorMessage = 'Cet utilisateur a refusé votre demande précédente';
      } else if (message.includes('requête invalide') || message.includes('bad request')) {
        errorMessage = 'Impossible d\'envoyer la demande. Vérifiez le nom d\'utilisateur.';
      } else if (message.includes('erreur serveur') || message.includes('internal server')) {
        errorMessage = 'Erreur du serveur. Veuillez réessayer plus tard.';
      } else {
        errorMessage = error.message;
      }
    }
    
    return {
      success: false,
      error: errorMessage
    };
  }
};

// Accept friend request
export const acceptFriendRequest = async (friendship_id: number): Promise<ApiResponse<void>> => {
  try {
    const response = await fetchWithAuth('/profile/friendRequest/accept', {
      method: 'PATCH',
      body: JSON.stringify({ friendship_id })
    });
    return {
      success: true,
      data: response
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to accept friend request'
    };
  }
};

// Decline friend request
export const declineFriendRequest = async (friendship_id: number): Promise<ApiResponse<void>> => {
  try {
    const response = await fetchWithAuth('/profile/friendRequest/decline', {
      method: 'PATCH',
      body: JSON.stringify({ friendship_id })
    });
    return {
      success: true,
      data: response
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to decline friend request'
    };
  }
};

// Remove friend
export const removeFriend = async (friendship_id: number): Promise<ApiResponse<void>> => {
  try {
    const response = await fetchWithAuth('/profile/friendRequest/delete', {
      method: 'PATCH',
      body: JSON.stringify({ friendship_id })
    });
    return {
      success: true,
      data: response
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to remove friend'
    };
  }
};

// Get incoming friend requests (received BY the current user)
// Note: This endpoint doesn't exist in the backend yet, so we'll return empty for now
export const getIncomingRequests = async (): Promise<ApiResponse<FriendRequest[]>> => {
  try {
    // This would be a new endpoint like '/profile/friendRequest/incoming'
    // For now, return empty array since the backend doesn't have this endpoint
    return {
      success: true,
      data: []
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to fetch incoming requests'
    };
  }
};

// Search users - CORRIGÉ avec debugging
export const searchUsers = async (query: string): Promise<ApiResponse<User[]>> => {
  try {
    console.log('🔍 Searching for user:', query);
    console.log('🔗 URL:', `/profile/user/${query}`);
    
    const response = await fetchWithAuth(`/profile/user/${query}`);
    
    console.log('📦 Response received:', response);
    
    // If user found, return as array
    if (response && response.username) {
      const userData = {
        user_id: 0, // ✅ Valeur par défaut car user_id n'est pas dans la réponse publique
        username: response.username,
        display_name: response.username, // ✅ Utiliser username comme display_name
        email: response.email_adress, // ✅ Attention: c'est email_adress dans votre backend
        avatar: response.avatar,
        is_online: false // ✅ Valeur par défaut
      };
      
      console.log('✅ User data formatted:', userData);
      
      return {
        success: true,
        data: [userData]
      };
    }
    
    console.log('❌ No user found or invalid response');
    return {
      success: true,
      data: []
    };
  } catch (error) {
    console.error('🚨 Error in searchUsers:', error);
    
    // If it's a 404 or 500 (user not found), just return empty results
    if (error instanceof Error) {
      const message = error.message.toLowerCase();
      if (message.includes('404') || message.includes('500') || message.includes('not found')) {
        console.log('🔍 User not found (404/500), returning empty results');
        return {
          success: true,
          data: []
        };
      }
    }
    
    console.error('💥 Real error occurred:', error);
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to search users'
    };
  }
};

// Get friends' online status
export const getFriendsOnlineStatus = async (): Promise<ApiResponse<{
  friends_status: { [userId: number]: { username: string; is_online: boolean; last_seen: Date | null } };
  total_friends: number;
  online_friends: number;
}>> => {
  try {
    const response = await fetchWithAuth('/profile/friends/online-status');
    return {
      success: true,
      data: response
    };
  } catch (error) {
    return {
      success: false,
      error: error instanceof Error ? error.message : 'Failed to fetch online status'
    };
  }
};

// Aliases for backward compatibility
export const rejectFriendRequest = declineFriendRequest;