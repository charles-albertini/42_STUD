<template>
  <div v-if="show" class="login-popup-overlay" @click="onClose">
    <div class="login-popup" @click.stop>
      <div class="popup-header">
        <h2>{{ title }}</h2>
        <button class="close-button" @click="onClose">×</button>
      </div>
      <div class="popup-content">
        <div class="popup-icon">🔒</div>
        <h3 class="popup-title">{{ subtitle }}</h3>
        <p>{{ message }}</p>
        <div v-if="features && features.length" class="popup-features">
          <div v-for="(feature, i) in features" :key="i" class="popup-feature">
            <span class="popup-feature-icon">{{ feature.icon }}</span>
            <span>{{ feature.text }}</span>
          </div>
        </div>
        <div class="popup-buttons">
          <!-- Bouton Se connecter (classique, toujours actif) -->
          <button @click="onSignIn" class="btn btn-primary popup-btn">
            <svg class="btn-icon" fill="currentColor" viewBox="0 0 20 20">
              <path fill-rule="evenodd" d="M3 3a1 1 0 011 1v12a1 1 0 11-2 0V4a1 1 0 011-1zm7.707 3.293a1 1 0 010 1.414L9.414 9H17a1 1 0 110 2H9.414l1.293 1.293a1 1 0 01-1.414 1.414l-3-3a1 1 0 010-1.414l3-3a1 1 0 011.414 0z" clip-rule="evenodd"></path>
            </svg>
            <span class="btn-label">{{ signInLabel }}</span>
          </button>

          <!-- Bouton S'inscrire -->
          <button @click="onSignUp" class="btn btn-secondary popup-btn">
            <svg class="btn-icon" fill="currentColor" viewBox="0 0 20 20">
              <path d="M8 9a3 3 0 100-6 3 3 0 000 6zM8 11a6 6 0 016 6H2a6 6 0 016-6zM16 7a1 1 0 10-2 0v1h-1a1 1 0 100 2h1v1a1 1 0 102 0v-1h1a1 1 0 100-2h-1V7z"></path>
            </svg>
            <span class="btn-label">{{ signUpLabel }}</span>
          </button>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { defineProps, defineEmits, ref } from 'vue';
const props = defineProps({
  show: Boolean,
  title: { type: String, default: 'Accès restreint' },
  subtitle: { type: String, default: 'Connexion requise' },
  message: { type: String, default: 'Vous devez être connecté pour accéder à cette fonctionnalité.' },
  features: { type: Array, default: () => [] },
  signInLabel: { type: String, default: 'Se connecter' },
  signUpLabel: { type: String, default: 'S\'inscrire' },
});
const emit = defineEmits(['close', 'signIn', 'signUp']);
const acceptCgu = ref(false);
const onClose = () => emit('close');
const onSignIn = () => emit('signIn');
const onSignUp = () => emit('signUp');
</script>

<style scoped>
.login-popup-overlay {
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.7);
  backdrop-filter: blur(5px);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 1000;
  animation: fadeIn 0.3s ease-out;
}
.login-popup {
  background: linear-gradient(135deg, #2d5a3d 0%, #1a472a 100%);
  border: 2px solid #d4af37;
  border-radius: 1rem;
  width: 90%;
  max-width: 600px;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.5);
  overflow: hidden;
  animation: scaleIn 0.3s ease-out;
}
.popup-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 1.5rem;
  background: rgba(0, 0, 0, 0.3);
  border-bottom: 1px solid rgba(212, 175, 55, 0.3);
}
.popup-header h2 {
  color: #d4af37;
  margin: 0;
  font-size: 1.5rem;
}
.close-button {
  background: none;
  border: none;
  color: #fff;
  font-size: 1.8rem;
  cursor: pointer;
  padding: 0;
  line-height: 1;
  transition: color 0.2s;
}
.close-button:hover {
  color: #d4af37;
}
.popup-content {
  padding: 2rem;
  text-align: center;
}
.popup-icon {
  font-size: 4rem;
  margin-bottom: 1rem;
  animation: bounce 2s infinite;
}
.popup-title {
  color: #d4af37;
  font-size: 1.5rem;
  margin-bottom: 1rem;
}
.popup-content p {
  color: #e0e0e0;
  font-size: 1.1rem;
  margin-bottom: 2rem;
  line-height: 1.5;
}
.popup-features {
  display: flex;
  flex-direction: column;
  gap: 1rem;
  margin-bottom: 2rem;
  text-align: left;
}
.popup-feature {
  display: flex;
  align-items: center;
  gap: 1rem;
  padding: 0.75rem;
  background: rgba(255, 255, 255, 0.1);
  border-radius: 0.5rem;
  color: #e0e0e0;
}
.popup-feature-icon {
  font-size: 1.5rem;
  min-width: 2rem;
}
.popup-buttons {
  display: flex;
  justify-content: center;
  gap: 1rem;
  flex-wrap: wrap;
}
.popup-btn {
  min-width: 160px;
  padding: 1rem 2rem;
  border: none;
  border-radius: 0.75rem;
  font-size: 1.125rem;
  font-weight: 600;
  cursor: pointer;
  transition: all 0.3s ease;
  text-transform: uppercase;
  letter-spacing: 1px;
  display: flex;
  align-items: center;
  gap: 0.5rem;
  justify-content: center;
  box-shadow: 0 4px 15px rgba(212, 175, 55, 0.15);
}
.btn-primary {
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  box-shadow: 0 4px 15px rgba(212, 175, 55, 0.3);
}
.btn-primary:hover {
  background: linear-gradient(135deg, #f4d03f, #d4af37);
  color: #1a1a1a;
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(212, 175, 55, 0.4);
}
.btn-secondary {
  background: transparent;
  color: #d4af37;
  border: 2px solid #d4af37;
}
.btn-secondary:hover {
  background: #d4af37;
  color: #1a1a1a;
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(212, 175, 55, 0.3);
}
.btn-icon {
  width: 20px;
  height: 20px;
}
@keyframes fadeIn {
  from { opacity: 0; }
  to { opacity: 1; }
}
@keyframes scaleIn {
  from { transform: scale(0.9); opacity: 0; }
  to { transform: scale(1); opacity: 1; }
}
@keyframes bounce {
  0%, 20%, 50%, 80%, 100% {
    transform: translateY(0);
  }
  40% {
    transform: translateY(-10px);
  }
  60% {
    transform: translateY(-5px);
  }
}
</style>
