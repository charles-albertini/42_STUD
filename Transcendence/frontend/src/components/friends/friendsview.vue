<template>
  <div class="friends-page">
    <!--         <FriendReques          <FriendCard          <FriendCard 
            v-for="friendship in offlineFriends" 
            :key="friendship.friendship_id"           v-for="friendship in onlineFriends" 
            :key="friendship.friendship_id"rd 
          v-for="request in pendingRequests" 
          :key="request.friendship_id"der avec statistiques -->
    <div class="friends-header">
      <div class="header-content">
        <h1 class="page-title">
          <i class="fas fa-users"></i>
          Mes Amis
        </h1>
        <div class="friends-stats">
          <div class="stat-item">
            <span class="stat-number">{{ totalFriendsCount }}</span>
            <span class="stat-label">Amis</span>
          </div>
          <div class="stat-item online">
            <span class="stat-number">{{ onlineFriendsCount }}</span>
            <span class="stat-label">En ligne</span>
          </div>
        </div>
      </div>
      <div class="header-actions">
        <!-- Bouton Accueil -->
        <router-link to="/Home2" class="nav-link friends-link">
          <i class="fas fa-home"></i>
          <span>Accueil</span>
        </router-link>
        
        <button @click="showAddFriend = true" class="btn-primary">
          <i class="fas fa-user-plus"></i>
          Ajouter un ami
        </button>
      </div>
    </div>

    <!-- Messages d'erreur -->
    <div v-if="error" class="error-message">
      <i class="fas fa-exclamation-triangle"></i>
      {{ error }}
      <button @click="loadFriends" class="btn-retry">Réessayer</button>
    </div>

    <!-- Loading state -->
    <div v-if="isLoading" class="loading-container">
      <div class="loading-spinner">
        <i class="fas fa-spinner fa-spin"></i>
        <span>Chargement des amis...</span>
      </div>
    </div>

    <!-- Demandes d'amis en attente -->
    <div v-if="pendingRequestsCount > 0" class="friend-requests-section">
      <h2 class="section-title">
        <i class="fas fa-inbox"></i>
        Demandes d'amis ({{ pendingRequestsCount }})
      </h2>
      <div class="requests-grid">
        <FriendRequestCard 
          v-for="request in pendingRequests"
          :key="request.friendship_id"
          :request="request"
          @accept="handleAcceptRequest"
          @reject="handleRejectRequest"
        />
      </div>
    </div>

    <!-- Liste des amis -->
    <div v-if="!isLoading" class="friends-content">
      <!-- Amis en ligne -->
      <div v-if="onlineFriends.length > 0" class="friends-section">
        <h2 class="section-title online">
          <i class="fas fa-circle"></i>
          En ligne ({{ onlineFriendsCount }})
        </h2>
        <div class="friends-grid">
          <FriendCard 
            v-for="friendship in onlineFriends"
            :key="friendship.friendship_id"
            :friendship="friendship"
            :is-online="true"
            @remove="handleRemoveFriend"
            @view-profile="handleViewProfile"
          />
        </div>
      </div>

      <!-- Amis hors ligne -->
      <div v-if="offlineFriends.length > 0" class="friends-section">
        <h2 class="section-title offline">
          <i class="fas fa-circle"></i>
          Hors ligne ({{ offlineFriends.length }})
        </h2>
        <div class="friends-grid">
          <FriendCard 
            v-for="friendship in offlineFriends"
            :key="friendship.friendship_id"
            :friendship="friendship"
            :is-online="false"
            @remove="handleRemoveFriend"
            @view-profile="handleViewProfile"
          />
        </div>
      </div>

      <!-- État vide -->
      <div v-if="totalFriendsCount === 0 && !isLoading" class="empty-state">
        <div class="empty-content">
          <i class="fas fa-user-friends"></i>
          <h3>Aucun ami pour le moment</h3>
          <p>Commencez à construire votre réseau d'amis Pong !</p>
          <button @click="showAddFriend = true" class="btn-primary">
            Ajouter votre premier ami
          </button>
        </div>
      </div>
    </div>

    <!-- Modal d'ajout d'ami -->
    <AddFriendModal 
      v-if="showAddFriend"
      @close="showAddFriend = false"
      @friend-added="handleFriendAdded"
    />

    <!-- Notifications toast -->
    <div v-if="notification" class="notification" :class="notification.type">
      <i :class="notification.icon"></i>
      <span>{{ notification.message }}</span>
      <button @click="notification = null" class="close-btn">
        <i class="fas fa-times"></i>
      </button>
    </div>

    <!-- Bouton Retour à l'accueil en bas de page -->
    <div class="footer-home-btn">
      <router-link to="/home2" class="btn-home-gold">
        <i class="fas fa-home"></i>
        Retour à l'accueil
      </router-link>
    </div>

  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue';
import { useRouter } from 'vue-router';
import { useFriends } from '@/composable/useFriends';
import FriendCard from './FriendCard.vue';
import FriendRequestCard from './FriendRequestCard.vue';
import AddFriendModal from './AddFriendModal.vue';

const router = useRouter();

// Utilisation du composable
const {
  onlineFriends,
  offlineFriends,
  pendingRequests,
  onlineFriendsCount,
  totalFriendsCount,
  pendingRequestsCount,
  isLoading,
  error,
  loadFriends,
  acceptFriendRequest,
  rejectFriendRequest,
  removeFriend
} = useFriends();

// État local
const showAddFriend = ref(false);
const notification = ref<{
  type: 'success' | 'error' | 'info';
  message: string;
  icon: string;
} | null>(null);

// Gestionnaires d'événements
const handleAcceptRequest = async (requestId: number) => {
  const result = await acceptFriendRequest(requestId);
  showNotification(
    result.success ? 'success' : 'error',
    result.success ? 'Demande acceptée avec succès' : (result.error || 'Erreur lors de l\'acceptation'),
    result.success ? 'fas fa-check' : 'fas fa-times'
  );
};

const handleRejectRequest = async (requestId: number) => {
  const result = await rejectFriendRequest(requestId);
  showNotification(
    result.success ? 'info' : 'error',
    result.success ? 'Demande rejetée' : (result.error || 'Erreur lors du rejet'),
    result.success ? 'fas fa-times' : 'fas fa-exclamation'
  );
};

const handleRemoveFriend = async (friendshipId: number) => {
  const result = await removeFriend(friendshipId);
  showNotification(
    result.success ? 'info' : 'error',
    result.success ? 'Ami supprimé' : (result.error || 'Erreur lors de la suppression'),
    result.success ? 'fas fa-user-minus' : 'fas fa-times'
  );
};

const handleViewProfile = (friendship: any) => {
  router.push(`/profile/${friendship.friend.username}`);
};

const handleFriendAdded = () => {
  showNotification('success', 'Demande d\'ami envoyée !', 'fas fa-paper-plane');
  loadFriends();
};

const showNotification = (type: 'success' | 'error' | 'info', message: string, icon: string) => {
  notification.value = { type, message, icon };
  setTimeout(() => {
    notification.value = null;
  }, 5000);
};

onMounted(() => {
});

</script>

<style scoped>
.friends-page {
  min-height: 100vh;
  background: linear-gradient(135deg, #1a472a 0%, #2d5a3d 50%, #1a472a 100%);
  color: #f8f9fa;
  padding: 2rem;
}

.friends-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 2rem;
  padding: 1.5rem;
  background: rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(10px);
  border-radius: 1rem;
  border: 1px solid rgba(212, 175, 55, 0.3);
}

.header-content {
  display: flex;
  align-items: center;
  gap: 2rem;
}

.header-actions {
  display: flex;
  align-items: center;
  gap: 1rem;
}

.page-title {
  font-size: 2rem;
  font-weight: bold;
  color: #d4af37;
  margin: 0;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.friends-stats {
  display: flex;
  gap: 1.5rem;
}

.stat-item {
  text-align: center;
}

.stat-number {
  display: block;
  font-size: 1.5rem;
  font-weight: bold;
  color: #d4af37;
}

.stat-item.online .stat-number {
  color: #28a745;
}

.stat-label {
  display: block;
  font-size: 0.8rem;
  color: #adb5bd;
  text-transform: uppercase;
  letter-spacing: 0.5px;
}

.btn-primary {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  border: none;
  border-radius: 0.5rem;
  font-weight: 600;
  cursor: pointer;
  transition: all 0.3s ease;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  margin: 0 0.5rem;
}

.btn-primary:hover {
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(212, 175, 55, 0.4);
  background: linear-gradient(135deg, #ffe082, #d4af37);
}
.btn-secondary {
  background: transparent;
  color: #d4af37;
  border: 2px solid #d4af37;
  border-radius: 0.5rem;
  padding: 0.5rem 1rem;
  font-weight: 600;
  cursor: pointer;
  margin: 0 0.5rem;
  transition: all 0.2s;
}
.btn-secondary:hover {
  background: #d4af37;
  color: #1a1a1a;
  transform: translateY(-2px);
}

.nav-link.friends-link {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: rgba(212, 175, 55, 0.1);
  border: 1px solid rgba(212, 175, 55, 0.3);
  border-radius: 0.5rem;
  color: #d4af37;
  text-decoration: none;
  font-weight: 600;
  transition: all 0.3s ease;
  position: relative;
}

.nav-link.friends-link:hover {
  background: rgba(212, 175, 55, 0.2);
  border-color: rgba(212, 175, 55, 0.5);
  transform: translateY(-2px);
}

.notification-badge {
  background: #dc3545;
  color: white;
  font-size: 0.7rem;
  padding: 0.25rem 0.5rem;
  border-radius: 50%;
  font-weight: bold;
  min-width: 1.2rem;
  text-align: center;
}
.btn-retry {
  padding: 0.5rem 1.2rem;
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  border: none;
  border-radius: 0.5rem;
  font-weight: 600;
  cursor: pointer;
  font-size: 0.9rem;
  margin-left: 1rem;
  transition: all 0.2s;
}
.btn-retry:hover {
  background: linear-gradient(135deg, #ffe082, #d4af37);
  color: #1a1a1a;
}

.error-message {
  display: flex;
  align-items: center;
  gap: 1rem;
  padding: 1rem;
  background: rgba(220, 53, 69, 0.2);
  border: 1px solid rgba(220, 53, 69, 0.5);
  border-radius: 0.5rem;
  color: #ff6b6b;
  margin-bottom: 1rem;
}

.loading-container {
  display: flex;
  justify-content: center;
  padding: 3rem;
}

.loading-spinner {
  display: flex;
  flex-direction: column;
  align-items: center;
  gap: 1rem;
  color: #d4af37;
  font-size: 1.1rem;
}

.friend-requests-section {
  margin-bottom: 2rem;
}

.section-title {
  font-size: 1.2rem;
  font-weight: 600;
  color: #d4af37;
  margin-bottom: 1rem;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.section-title.online {
  color: #28a745;
}

.section-title.offline {
  color: #6c757d;
}

.section-title i {
  font-size: 0.8rem;
}

.requests-grid,
.friends-grid {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  gap: 1rem;
  margin-bottom: 2rem;
}

.empty-state {
  display: flex;
  justify-content: center;
  align-items: center;
  min-height: 300px;
}

.empty-content {
  text-align: center;
  color: #6c757d;
}

.empty-content i {
  font-size: 4rem;
  color: #495057;
  margin-bottom: 1rem;
}

.empty-content h3 {
  color: #adb5bd;
  margin-bottom: 0.5rem;
}

.empty-content p {
  margin-bottom: 1.5rem;
}

.notification {
  position: fixed;
  top: 2rem;
  right: 2rem;
  display: flex;
  align-items: center;
  gap: 0.75rem;
  padding: 1rem 1.5rem;
  border-radius: 0.5rem;
  color: white;
  font-weight: 500;
  z-index: 1000;
  animation: slideIn 0.3s ease;
}

.notification.success {
  background: rgba(40, 167, 69, 0.9);
  border: 1px solid #28a745;
}

.notification.error {
  background: rgba(220, 53, 69, 0.9);
  border: 1px solid #dc3545;
}

.notification.info {
  background: rgba(23, 162, 184, 0.9);
  border: 1px solid #17a2b8;
}

.close-btn {
  background: none;
  border: none;
  color: white;
  cursor: pointer;
  padding: 0.25rem;
  border-radius: 0.25rem;
}

.close-btn:hover {
  background: rgba(255, 255, 255, 0.2);
}

@keyframes slideIn {
  from {
    transform: translateX(100%);
    opacity: 0;
  }
  to {
    transform: translateX(0);
    opacity: 1;
  }
}

.btn-home-da, .btn-add-da {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: linear-gradient(135deg, #1a472a, #2d5a3d);
  color: #fff;
  border: none;
  border-radius: 0.5rem;
  font-weight: 600;
  cursor: pointer;
  transition: all 0.3s ease;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  margin: 0 0.5rem;
  box-shadow: 0 2px 8px rgba(40, 87, 42, 0.10);
}
.btn-home-da:hover, .btn-add-da:hover {
  background: linear-gradient(135deg, #2d5a3d, #1a472a);
  color: #fff;
  transform: scale(1.07);
  box-shadow: 0 4px 15px rgba(40, 87, 42, 0.18);
}

/* Style pour le bouton doré en bas de page */
.btn-home-gold {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  border: none;
  border-radius: 0.5rem;
  font-weight: 600;
  cursor: pointer;
  transition: all 0.3s ease;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  margin: 2.5rem auto 0 auto;
  box-shadow: 0 2px 8px rgba(212, 175, 55, 0.10);
  justify-content: center;
  min-width: 220px;
}
.btn-home-gold:hover {
  background: linear-gradient(135deg, #ffe082, #d4af37);
  color: #1a1a1a;
  transform: scale(1.07);
  box-shadow: 0 4px 15px rgba(212, 175, 55, 0.18);
}

.footer-home-btn {
  width: 100%;
  display: flex;
  justify-content: center;
  align-items: center;
  position: fixed;
  left: 0;
  bottom: 0;
  z-index: 10;
  background: none;
  padding-bottom: 2.5rem;
  pointer-events: none;
}
.footer-home-btn .btn-home-gold {
  pointer-events: auto;
}
</style>