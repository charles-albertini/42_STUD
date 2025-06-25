<template>
  <div class="friend-request-card" :class="{ 'processing': isProcessing }">
    <!-- Avatar -->
    <div class="avatar-container">
      <div class="avatar default-avatar">
        <div class="avatar-placeholder">
          {{ displayName.charAt(0).toUpperCase() }}
        </div>
      </div>
    </div>

    <!-- Informations de la demande -->
    <div class="request-info">
      <h3 class="user-name">{{ displayName }}</h3>
      <p class="user-username">@{{ request.sender.username }}</p>
    </div>

    <!-- Actions -->
    <div class="request-actions">
      <button 
        @click="handleAccept"
        :disabled="isProcessing"
        class="btn-accept"
        title="Accepter"
      >
        <i class="fas fa-check"></i>
        <span class="btn-text">Accepter</span>
      </button>
      <button 
        @click="handleReject"
        :disabled="isProcessing"
        class="btn-reject"
        title="Rejeter"
      >
        <i class="fas fa-times"></i>
        <span class="btn-text">Rejeter</span>
      </button>
    </div>

    <!-- Overlay de traitement -->
    <div v-if="isProcessing" class="processing-overlay">
      <i class="fas fa-spinner fa-spin"></i>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, computed } from 'vue';
import type { FriendRequest } from '../../services/friendsAPI';

// Props
const props = defineProps<{
  request: FriendRequest;
}>();

// Émissions
const emit = defineEmits<{
  'accept': [requestId: number];
  'reject': [requestId: number];
}>();

// État local
const isProcessing = ref(false);

// Computed
const displayName = computed(() => 
  props.request.sender.username
);

// Méthodes
const handleAccept = async () => {
  if (isProcessing.value) return;
  
    isProcessing.value = true;
  try {
    emit('accept', props.request.friendship_id);
  } finally {
    // Le composant parent gérera la mise à jour de l'état
    setTimeout(() => {
      isProcessing.value = false;
    }, 1000);
  }
};

const handleReject = async () => {
  if (isProcessing.value) return;
  
  isProcessing.value = true;
  try {
    emit('reject', props.request.friendship_id);
  } finally {
    setTimeout(() => {
      isProcessing.value = false;
    }, 1000);
  }
};
</script>

<style scoped>
.friend-request-card {
  display: flex;
  align-items: center;
  gap: 1rem;
  padding: 1.5rem;
  background: rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(10px);
  border-radius: 1rem;
  border: 1px solid rgba(255, 193, 7, 0.3);
  transition: all 0.3s ease;
  position: relative;
  overflow: hidden;
}

.friend-request-card:hover {
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(0, 0, 0, 0.3);
  border-color: rgba(255, 193, 7, 0.5);
}

.friend-request-card::before {
  content: '';
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  height: 3px;
  background: linear-gradient(90deg, #ffc107, #fd7e14);
}

.avatar-container {
  flex-shrink: 0;
}

.avatar {
  width: 60px;
  height: 60px;
  border-radius: 50%;
  border: 3px solid rgba(255, 193, 7, 0.5);
  transition: border-color 0.3s ease;
  display: flex;
  align-items: center;
  justify-content: center;
  overflow: hidden;
}

.avatar img {
  width: 100%;
  height: 100%;
  object-fit: cover;
}

.avatar.default-avatar {
  background: linear-gradient(135deg, #ffc107, #fd7e14);
}

.avatar-placeholder {
  font-size: 1.5rem;
  font-weight: bold;
  color: #1a1a1a;
  text-align: center;
}

.friend-request-card:hover .avatar {
  border-color: rgba(255, 193, 7, 0.8);
}

.request-info {
  flex: 1;
  min-width: 0;
}

.user-name {
  font-size: 1.1rem;
  font-weight: 600;
  color: #f8f9fa;
  margin: 0 0 0.25rem 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.user-username {
  font-size: 0.9rem;
  color: #adb5bd;
  margin: 0 0 0.5rem 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.request-actions {
  display: flex;
  gap: 0.75rem;
  flex-shrink: 0;
}

.btn-accept,
.btn-reject {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 1rem;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 600;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  font-size: 0.8rem;
  position: relative;
  overflow: hidden;
}

.btn-accept {
  background: linear-gradient(135deg, #28a745, #20c997);
  color: white;
}

.btn-accept:hover:not(:disabled) {
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(40, 167, 69, 0.4);
}

.btn-reject {
  background: linear-gradient(135deg, #dc3545, #c82333);
  color: white;
}

.btn-reject:hover:not(:disabled) {
  transform: translateY(-2px);
  box-shadow: 0 6px 20px rgba(220, 53, 69, 0.4);
}

.btn-accept:disabled,
.btn-reject:disabled {
  opacity: 0.6;
  cursor: not-allowed;
  transform: none;
}

.btn-text {
  display: inline;
}

.processing-overlay {
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.7);
  display: flex;
  align-items: center;
  justify-content: center;
  color: #ffc107;
  font-size: 1.5rem;
  backdrop-filter: blur(2px);
}

</style>