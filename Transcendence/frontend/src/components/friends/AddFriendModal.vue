<template>
  <div class="modal-overlay" @click="handleOverlayClick">
    <div class="modal-container" @click.stop>
      <!-- Header du modal -->
      <div class="modal-header">
        <h2 class="modal-title">
          <i class="fas fa-user-plus"></i>
          Ajouter un ami
        </h2>
        <button @click="$emit('close')" class="btn-close">
          ✗
        </button>
      </div>

      <!-- Contenu du modal -->
      <div class="modal-content">
        <!-- Barre de recherche -->
        <div class="search-section">
          <div class="search-input-group">
            <i class="fas fa-search search-icon"></i>
            <input
              v-model="searchQuery"
              @keyup.enter="handleSearchClick"
              type="text"
              placeholder="Rechercher un utilisateur par nom..."
              class="search-input"
              :disabled="isSearching"
            />
            <button 
              @click="handleSearchClick"
              :disabled="isSearching || searchQuery.length < 2"
              class="search-button"
              title="Rechercher"
            >
              <span v-if="!isSearching">✓</span>
              <i v-else class="fas fa-spinner fa-spin"></i>
            </button>
          </div>
          <p class="search-hint">
            Tapez au moins 2 caractères puis cliquez sur "Rechercher" ou appuyez sur Entrée
          </p>
        </div>

        <!-- Messages d'erreur/succès -->
        <div v-if="error" class="error-message">
          <i class="fas fa-exclamation-triangle"></i>
          {{ error }}
        </div>
        
        <div v-if="successMessage" class="success-message">
          <i class="fas fa-check-circle"></i>
          {{ successMessage }}
        </div>

        <!-- Résultats de recherche -->
        <div v-if="searchResults.length > 0" class="search-results">
          <h3 class="results-title">Utilisateurs trouvés ({{ searchResults.length }})</h3>
          <div class="results-list">
            <UserSearchCard
              v-for="user in searchResults"
              :key="user.user_id"
              :user="user"
              :is-adding="addingUserId === user.user_id"
              @add-friend="handleAddFriend"
            />
          </div>
        </div>

        <!-- Message si aucun résultat -->
        <div v-else-if="hasSearched && !isSearching && searchResults.length === 0" class="empty-results">
          <i class="fas fa-search"></i>
          <h3>Aucun utilisateur trouvé</h3>
          <p>Aucun utilisateur ne correspond à votre recherche "{{ lastSearchQuery }}"</p>
        </div>

        <!-- Instructions -->
        <div v-if="!hasSearched && !isSearching" class="instructions">
          <div class="instruction-item">
            <i class="fas fa-info-circle"></i>
            <div>
              <h4>Comment ajouter un ami ?</h4>
              <ul>
                <li>Tapez le nom d'utilisateur ou nom d'affichage de votre ami</li>
                <li>Cliquez sur le bouton "Rechercher" ou appuyez sur Entrée</li>
                <li>Sélectionnez-le dans les résultats de recherche</li>
                <li>Envoyez une demande d'ami</li>
                <li>Attendez qu'il accepte votre demande</li>
              </ul>
            </div>
          </div>
        </div>
      </div>

      <!-- Footer du modal -->
      <div class="modal-footer">
        <button @click="$emit('close')" class="btn-secondary">
          Fermer
        </button>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted, onUnmounted } from 'vue';
import { searchUsers, sendFriendRequest } from '../../services/friendsAPI';
import type { User } from '../../services/friendsAPI';
import UserSearchCard from './UserSearchCard.vue';

// Émissions
const emit = defineEmits<{
  'close': [];
  'friend-added': [];
}>();

// État réactif
const searchQuery = ref('');
const searchResults = ref<User[]>([]);
const isSearching = ref(false);
const addingUserId = ref<number | null>(null);
const error = ref<string | null>(null);
const successMessage = ref<string | null>(null);
const hasSearched = ref(false);
const lastSearchQuery = ref('');

// Méthodes
const handleSearchClick = async () => {
  clearMessages();
  
  if (searchQuery.value.length < 2) {
    error.value = 'Veuillez saisir au moins 2 caractères pour la recherche';
    return;
  }

  if (isSearching.value) return;

  isSearching.value = true;
  hasSearched.value = true;
  lastSearchQuery.value = searchQuery.value;
  
  try {
    const results = await searchUsers(searchQuery.value);
    searchResults.value = (results.success && results.data) ? results.data : [];
    
    if (!results.success) {
      error.value = results.error || 'Erreur lors de la recherche';
    }
  } catch (err: any) {
    error.value = err.message || 'Erreur lors de la recherche';
    searchResults.value = [];
  } finally {
    isSearching.value = false;
  }
};

const handleAddFriend = async (user: User) => {
  if (addingUserId.value === user.user_id) return;
  
  addingUserId.value = user.user_id;
  clearMessages();
  
  try {
    const result = await sendFriendRequest(user.username);
    
    if (result.success) {
      successMessage.value = 'Demande d\'ami envoyée avec succès !';
      // Retirer l'utilisateur des résultats
      searchResults.value = searchResults.value.filter(u => u.user_id !== user.user_id);
      
      // Émettre l'événement
      emit('friend-added');
      
      // Fermer le modal après 2 secondes
      setTimeout(() => {
        emit('close');
      }, 2000);
    } else {
      error.value = result.error || 'Erreur lors de l\'envoi de la demande';
    }
  } catch (err: any) {
    error.value = err.message || 'Erreur lors de l\'ajout de l\'ami';
  } finally {
    addingUserId.value = null;
  }
};

const clearMessages = () => {
  error.value = null;
  successMessage.value = null;
};

const handleOverlayClick = () => {
  emit('close');
};

const handleEscapeKey = (event: KeyboardEvent) => {
  if (event.key === 'Escape') {
    emit('close');
  }
};

// Lifecycle
onMounted(() => {
  document.addEventListener('keydown', handleEscapeKey);
  // Auto-focus sur l'input
  setTimeout(() => {
    const input = document.querySelector('.search-input') as HTMLInputElement;
    if (input) input.focus();
  }, 100);
});

onUnmounted(() => {
  document.removeEventListener('keydown', handleEscapeKey);
});
</script>

<style scoped>
.modal-overlay {
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.8);
  backdrop-filter: blur(5px);
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: 1000;
  animation: fadeIn 0.3s ease;
}

.modal-container {
  width: 600px;
  max-width: 600px;
  min-width: 600px;
  max-height: 90vh;
  margin: 0 auto;
  background: linear-gradient(135deg, #1a472a 0%, #2d5a3d 50%, #1a472a 100%);
  border-radius: 1rem;
  border: 1px solid rgba(212, 175, 55, 0.3);
  overflow: hidden;
  animation: slideIn 0.3s ease;
  display: flex;
  flex-direction: column;
}

.modal-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 1.5rem;
  background: rgba(0, 0, 0, 0.3);
  border-bottom: 1px solid rgba(255, 255, 255, 0.1);
}

.modal-title {
  font-size: 1.5rem;
  font-weight: 600;
  color: #d4af37;
  margin: 0;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.btn-close {
  width: 40px;
  height: 40px;
  border: none;
  background: rgba(220, 53, 69, 0.2);
  color: #ff3333;
  border-radius: 0.5rem;
  cursor: pointer;
  transition: all 0.3s ease;
  display: flex;
  align-items: center;
  justify-content: center;
  border: 1px solid rgba(220, 53, 69, 0.5);
  font-size: 1.5rem;
  font-weight: bold;
}

.btn-close:hover {
  background: rgba(220, 53, 69, 0.4);
  color: #fff;
  transform: scale(1.05);
}

.modal-content {
  flex: 1;
  overflow-y: auto;
  padding: 1.5rem;
}

.search-section {
  margin-bottom: 1.5rem;
}

.search-input-group {
  position: relative;
  margin-bottom: 0.5rem;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.search-input {
  flex: 1;
  padding: 1rem 1rem 1rem 3rem;
  background: rgba(0, 0, 0, 0.3);
  border: 1px solid rgba(255, 255, 255, 0.2);
  border-radius: 0.5rem;
  color: #f8f9fa;
  font-size: 1rem;
  transition: all 0.3s ease;
}

.search-input:focus {
  outline: none;
  border-color: rgba(212, 175, 55, 0.5);
  box-shadow: 0 0 0 3px rgba(212, 175, 55, 0.1);
}

.search-input::placeholder {
  color: #6c757d;
}

.search-input:disabled {
  opacity: 0.6;
  cursor: not-allowed;
}

.search-icon {
  position: absolute;
  left: 1rem;
  top: 50%;
  transform: translateY(-50%);
  color: #6c757d;
  pointer-events: none;
}

.search-button {
  display: flex;
  align-items: center;
  justify-content: center;
  width: 48px;
  height: 48px;
  background: linear-gradient(135deg, #28a745, #20c997);
  border: none;
  border-radius: 0.5rem;
  color: white;
  cursor: pointer;
  transition: all 0.3s ease;
  font-size: 1.5rem;
  font-weight: bold;
  flex-shrink: 0;
  border: 1px solid rgba(40, 167, 69, 0.5);
}

.search-button:hover:not(:disabled) {
  transform: translateY(-2px);
  box-shadow: 0 6px 15px rgba(40, 167, 69, 0.4);
  background: linear-gradient(135deg, #34ce57, #28a745);
}

.search-button:disabled {
  opacity: 0.5;
  cursor: not-allowed;
  transform: none;
  background: rgba(108, 117, 125, 0.5);
  color: #6c757d;
  border: 1px solid rgba(108, 117, 125, 0.3);
}

.search-hint {
  font-size: 0.8rem;
  color: #6c757d;
  margin: 0;
}

.error-message,
.success-message {
  display: flex;
  align-items: center;
  gap: 0.75rem;
  padding: 1rem;
  border-radius: 0.5rem;
  margin-bottom: 1rem;
  font-weight: 500;
}

.error-message {
  background: rgba(220, 53, 69, 0.2);
  border: 1px solid rgba(220, 53, 69, 0.5);
  color: #ff6b6b;
}

.success-message {
  background: rgba(40, 167, 69, 0.2);
  border: 1px solid rgba(40, 167, 69, 0.5);
  color: #51cf66;
}

.search-results {
  margin-bottom: 1rem;
}

.results-title {
  font-size: 1.1rem;
  font-weight: 600;
  color: #d4af37;
  margin-bottom: 1rem;
}

.results-list {
  display: flex;
  flex-direction: column;
  gap: 0.75rem;
  max-height: 300px;
  overflow-y: auto;
}

.empty-results {
  text-align: center;
  padding: 2rem;
  color: #6c757d;
}

.empty-results i {
  font-size: 3rem;
  margin-bottom: 1rem;
  color: #495057;
}

.empty-results h3 {
  color: #adb5bd;
  margin-bottom: 0.5rem;
}

.instructions {
  color: #adb5bd;
}

.instruction-item {
  display: flex;
  gap: 1rem;
  align-items: flex-start;
}

.instruction-item i {
  color: #d4af37;
  font-size: 1.2rem;
  margin-top: 0.25rem;
  flex-shrink: 0;
}

.instruction-item h4 {
  color: #f8f9fa;
  margin: 0 0 0.5rem 0;
}

.instruction-item ul {
  margin: 0;
  padding-left: 1rem;
}

.instruction-item li {
  margin-bottom: 0.25rem;
}

.modal-footer {
  padding: 1.5rem;
  background: rgba(0, 0, 0, 0.3);
  border-top: 1px solid rgba(255, 255, 255, 0.1);
  display: flex;
  justify-content: flex-end;
}

.btn-secondary {
  padding: 0.75rem 1.5rem;
  background: rgba(108, 117, 125, 0.3);
  border: 1px solid rgba(108, 117, 125, 0.5);
  color: #adb5bd;
  border-radius: 0.5rem;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 600;
}

.btn-secondary:hover {
  background: rgba(108, 117, 125, 0.5);
  color: #f8f9fa;
}

@keyframes fadeIn {
  from { opacity: 0; }
  to { opacity: 1; }
}

@keyframes slideIn {
  from {
    opacity: 0;
    transform: scale(0.9) translateY(-20px);
  }
  to {
    opacity: 1;
    transform: scale(1) translateY(0);
  }
}
</style>