<template>
  <div class="friend-card" :class="{ 'online': isOnline }">
    <div class="avatar-container">
      <div class="avatar default-avatar">
        <div class="avatar-placeholder">
          {{ displayName.charAt(0).toUpperCase() }}
        </div>
      </div>
      <div class="status-indicator" :class="{ 'online': isOnline, 'offline': !isOnline }"></div>
    </div>
    <div class="friend-info">
      <h3 class="friend-name">{{ displayName }}</h3>
      <span class="friend-username">@{{ friendship.friend.username }}</span>
      <div class="friend-status">
        <i :class="statusIcon"></i>
        <span>{{ statusText }}</span>
      </div>
    </div>
    <div class="friend-actions">
      <!-- Bouton Profil -->
      <button 
        @click="$emit('view-profile', friendship)" 
        class="btn-action btn-profile"
        title="Voir le profil"
      >
        <i class="fas fa-user"></i>
        <span class="btn-text">Profil</span>
      </button>

      <!-- Bouton Supprimer -->
      <button 
        @click="showConfirmModal = true" 
        class="btn-action btn-remove"
        title="Supprimer l'ami"
      >
        <i class="fas fa-user-minus"></i>
        <span class="btn-text">Supprimer</span>
      </button>
    </div>

    <!-- Modal de confirmation -->
    <div v-if="showConfirmModal" class="modal-overlay" @click="showConfirmModal = false">
      <div class="confirm-modal" @click.stop>
        <div class="modal-header">
          <i class="fas fa-exclamation-triangle"></i>
          <h3>Confirmer la suppression</h3>
        </div>
        
        <div class="modal-body">
          <p>Êtes-vous sûr de vouloir supprimer <strong>{{ displayName }}</strong> de vos amis ?</p>
          <p class="warning-text">Cette action est irréversible.</p>
        </div>
        
        <div class="modal-actions">
          <button @click="showConfirmModal = false" class="btn-cancel">
            <i class="fas fa-times"></i>
            Annuler
          </button>
          <button @click="handleConfirmRemove" class="btn-confirm">
            <i class="fas fa-trash"></i>
            Supprimer
          </button>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { computed, ref } from 'vue';
import type { Friendship } from '../../services/friendsAPI';

// Props
const props = defineProps<{
  friendship: Friendship;
  isOnline: boolean;
}>();

// Émissions
const emit = defineEmits<{
  'view-profile': [friendship: Friendship];
  'remove': [friendshipId: number];
}>();

// État local
const showConfirmModal = ref(false);

// Computed
const displayName = computed(() => 
  props.friendship.friend.username
);

const statusIcon = computed(() => 
  props.isOnline ? 'fas fa-circle' : 'fas fa-circle'
);

const statusText = computed(() => 
  props.isOnline ? 'En ligne' : 'Hors ligne'
);

// Méthodes
const handleConfirmRemove = () => {
  emit('remove', props.friendship.friendship_id);
  showConfirmModal.value = false;
};

// Pas besoin de lifecycle hooks maintenant
</script>

<style scoped>
.friend-card {
  display: flex;
  align-items: center;
  gap: 1rem;
  padding: 1.25rem;
  background: rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(10px);
  border-radius: 1.2rem;
  border: 1.5px solid #2d5a3d;
  box-shadow: 0 6px 32px rgba(40, 87, 42, 0.18);
  transition: all 0.3s cubic-bezier(.4,2,.6,1);
  position: relative;
  min-height: 100px;
  box-sizing: border-box;
}

.friend-card:hover {
  transform: translateY(-3px) scale(1.02);
  box-shadow: 0 12px 32px rgba(40, 87, 42, 0.28);
  border-color: #d4af37;
}

.avatar-container {
  position: relative;
  flex-shrink: 0;
}

.avatar {
  width: 68px;
  height: 68px;
  border-radius: 50%;
  border: 3px solid #d4af37;
  display: flex;
  align-items: center;
  justify-content: center;
  overflow: hidden;
  background: linear-gradient(135deg, #d4af37, #c19b2e);
}

.avatar-placeholder {
  font-size: 2.1rem;
  font-weight: bold;
  color: #1a1a1a;
  text-align: center;
}

.status-indicator {
  position: absolute;
  bottom: 2px;
  right: 2px;
  width: 16px;
  height: 16px;
  border-radius: 50%;
  border: 2px solid rgba(0, 0, 0, 0.8);
  transition: background-color 0.3s ease;
}

.status-indicator.online {
  background-color: #28a745;
  box-shadow: 0 0 8px rgba(40, 167, 69, 0.6);
}

.status-indicator.offline {
  background-color: #6c757d;
}

.friend-info {
  flex: 1;
  min-width: 0;
  display: flex;
  flex-direction: column;
  align-items: flex-start;
  justify-content: center;
  gap: 0.2rem;
}

.friend-name {
  font-size: 1.25rem;
  font-weight: 700;
  color: #fff;
  margin: 0 0 0.1rem 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
  letter-spacing: 0.5px;
}

.friend-username {
  font-size: 1.05rem;
  color: #ffe082;
  font-weight: 500;
  margin-bottom: 0.1rem;
  margin-top: -0.1rem;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.friend-status {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  font-size: 0.92rem;
  color: #b6e7c9;
  font-weight: 500;
}

.friend-status i {
  font-size: 0.7rem;
}

.friend-card.online .friend-status {
  color: #7fff9e;
}

.friend-actions {
  display: flex;
  flex-direction: column;
  align-items: stretch;
  gap: 0.75rem;
  flex-shrink: 0;
  min-width: 120px;
}

.btn-action {
  display: flex;
  align-items: center;
  justify-content: center;
  gap: 0.5rem;
  padding: 0.6rem 1rem;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
  transition: all 0.3s ease;
  font-size: 0.85rem;
  font-weight: 600;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  white-space: nowrap;
}

.btn-text {
  font-size: 0.8rem;
}

.btn-profile {
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
}

.btn-profile:hover {
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(212, 175, 55, 0.4);
  background: linear-gradient(135deg, #ffe082, #d4af37);
}

.btn-remove {
  background: linear-gradient(135deg, #dc3545, #c82333);
  color: white;
}

.btn-remove:hover {
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(220, 53, 69, 0.4);
  background: linear-gradient(135deg, #e74c3c, #dc3545);
}

/* Styles simplifiés - plus besoin du menu d'options */

/* Modal de confirmation */
.modal-overlay {
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.7);
  backdrop-filter: blur(5px);
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: 1000;
  animation: fadeIn 0.3s ease;
}

.confirm-modal {
  background: rgba(26, 26, 26, 0.95);
  backdrop-filter: blur(20px);
  border: 1px solid rgba(212, 175, 55, 0.3);
  border-radius: 1rem;
  padding: 2rem;
  max-width: 400px;
  width: 90%;
  box-shadow: 0 20px 40px rgba(0, 0, 0, 0.5);
  animation: slideUp 0.3s ease;
}

.modal-header {
  display: flex;
  align-items: center;
  gap: 1rem;
  margin-bottom: 1.5rem;
  color: #ff6b6b;
}

.modal-header i {
  font-size: 1.5rem;
}

.modal-header h3 {
  margin: 0;
  color: #f8f9fa;
  font-size: 1.3rem;
  font-weight: 600;
}

.modal-body {
  margin-bottom: 2rem;
  color: #adb5bd;
  line-height: 1.6;
}

.modal-body p {
  margin: 0 0 1rem 0;
}

.modal-body strong {
  color: #d4af37;
  font-weight: 600;
}

.warning-text {
  font-size: 0.9rem;
  color: #ff6b6b;
  font-style: italic;
}

.modal-actions {
  display: flex;
  gap: 1rem;
  justify-content: flex-end;
}

.btn-cancel {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: rgba(255, 255, 255, 0.1);
  border: 1px solid rgba(255, 255, 255, 0.2);
  border-radius: 0.5rem;
  color: #adb5bd;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 600;
}

.btn-cancel:hover {
  background: rgba(255, 255, 255, 0.2);
  color: #f8f9fa;
  transform: translateY(-2px);
}

.btn-confirm {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1.5rem;
  background: linear-gradient(135deg, #dc3545, #c82333);
  border: none;
  border-radius: 0.5rem;
  color: white;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 600;
}

.btn-confirm:hover {
  background: linear-gradient(135deg, #e74c3c, #dc3545);
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(220, 53, 69, 0.4);
}

@keyframes fadeIn {
  from {
    opacity: 0;
  }
  to {
    opacity: 1;
  }
}

@keyframes slideUp {
  from {
    opacity: 0;
    transform: translateY(30px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

/* Responsive adjustments for fullscreen */
@media (min-width: 1200px) {
  .friend-card {
    min-height: 110px;
  }
  
  .friend-actions {
    min-width: 130px;
  }
  
  .btn-action {
    padding: 0.7rem 1.1rem;
    font-size: 0.9rem;
  }
}

@media (max-width: 768px) {
  .friend-card {
    flex-direction: column;
    align-items: flex-start;
    gap: 1rem;
    padding: 1rem;
  }
  
  .friend-info {
    width: 100%;
  }
  
  .friend-actions {
    flex-direction: row;
    width: 100%;
    justify-content: space-between;
  }
  
  .btn-action {
    flex: 1;
    padding: 0.75rem;
  }
}
</style>