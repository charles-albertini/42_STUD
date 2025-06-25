<template>
  <div class="user-search-card">
    <!-- Avatar -->
    <div class="user-avatar-container">
      <div class="user-avatar default-avatar">
        <div class="avatar-placeholder">
          {{ displayName.charAt(0).toUpperCase() }}
        </div>
      </div>
      <div v-if="user.is_online" class="online-indicator"></div>
    </div>

    <!-- Informations utilisateur -->
    <div class="user-info">
      <h3 class="user-name">{{ displayName }}</h3>
      <p class="user-username">@{{ user.username }}</p>
      <div class="user-status">
        <i :class="user.is_online ? 'fas fa-circle online' : 'fas fa-circle offline'"></i>
      </div>
    </div>

    <!-- Action d'ajout -->
    <div class="user-actions">
      <button 
        @click="handleAddFriend"
        :disabled="isAdding"
        class="btn-add-friend"
        :class="{ 'adding': isAdding }"
      >
        <i v-if="!isAdding" class="fas fa-user-plus"></i>
        <i v-else class="fas fa-spinner fa-spin"></i>
        <span class="btn-text">{{ isAdding ? 'Envoi...' : 'Ajouter' }}</span>
      </button>
    </div>
  </div>
</template>

<script setup lang="ts">
import { computed } from 'vue';
import type { User } from '../../services/friendsAPI';

// Props
const props = defineProps<{
  user: User;
  isAdding: boolean;
}>();

// Émissions
const emit = defineEmits<{
  'add-friend': [user: User];
}>();

// Computed
const displayName = computed(() => 
  props.user.display_name || props.user.username
);

// Méthodes
const handleAddFriend = () => {
  if (!props.isAdding) {
    emit('add-friend', props.user);
  }
};
</script>

<style scoped>
.user-search-card {
  display: flex;
  align-items: center;
  gap: 1rem;
  padding: 1rem;
  background: rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(10px);
  border-radius: 0.75rem;
  border: 1px solid rgba(255, 255, 255, 0.1);
  transition: all 0.3s ease;
  cursor: pointer;
}

.user-search-card:hover {
  transform: translateY(-2px);
  box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
  border-color: rgba(212, 175, 55, 0.3);
}

.user-avatar-container {
  position: relative;
  flex-shrink: 0;
}

.user-avatar {
  width: 50px;
  height: 50px;
  border-radius: 50%;
  border: 2px solid rgba(255, 255, 255, 0.2);
  transition: border-color 0.3s ease;
  display: flex;
  align-items: center;
  justify-content: center;
  overflow: hidden;
}

.user-avatar img {
  width: 100%;
  height: 100%;
  object-fit: cover;
}

.user-avatar.default-avatar {
  background: linear-gradient(135deg, #17a2b8, #138496);
}

.avatar-placeholder {
  font-size: 1.2rem;
  font-weight: bold;
  color: white;
  text-align: center;
}

.user-search-card:hover .user-avatar {
  border-color: rgba(212, 175, 55, 0.5);
}

.online-indicator {
  position: absolute;
  bottom: 2px;
  right: 2px;
  width: 12px;
  height: 12px;
  border-radius: 50%;
  background-color: #28a745;
  border: 2px solid rgba(0, 0, 0, 0.8);
  box-shadow: 0 0 6px rgba(40, 167, 69, 0.6);
}

.user-info {
  flex: 1;
  min-width: 0;
}

.user-name {
  font-size: 1rem;
  font-weight: 600;
  color: #f8f9fa;
  margin: 0 0 0.25rem 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.user-username {
  font-size: 0.85rem;
  color: #adb5bd;
  margin: 0 0 0.25rem 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.user-status {
  display: flex;
  align-items: center;
  gap: 0.4rem;
  font-size: 0.75rem;
  color: #6c757d;
}

.user-status i {
  font-size: 0.5rem;
}

.user-search-card:hover .user-status {
  color: #28a745;
}

.user-actions {
  flex-shrink: 0;
}

.btn-add-friend {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.6rem 1rem;
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 600;
  font-size: 0.85rem;
  text-transform: uppercase;
  letter-spacing: 0.5px;
  min-width: 100px;
  justify-content: center;
}

.btn-add-friend:hover:not(:disabled) {
  transform: translateY(-2px);
  box-shadow: 0 6px 15px rgba(212, 175, 55, 0.4);
}

.btn-add-friend:disabled {
  opacity: 0.7;
  cursor: not-allowed;
  transform: none;
}

.btn-add-friend.adding {
  background: linear-gradient(135deg, #6c757d, #5a6268);
  color: #f8f9fa;
}

.btn-text {
  font-size: 0.8rem;
}

.user-status i.online {
  color: #28a745;
}

.user-status i.offline {
  color: #6c757d;
}

</style>