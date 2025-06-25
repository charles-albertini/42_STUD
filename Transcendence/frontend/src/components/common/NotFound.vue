<template>
  <div class="error-container">
    <!-- Minimal billiard ball decorations -->
    <div class="billiard-decoration">
      <div class="billiard-ball ball-1 floating" style="top: 20%; left: 15%;"></div>
      <div class="billiard-ball ball-8 floating" style="top: 15%; right: 20%;"></div>
      <div class="billiard-ball ball-3 floating" style="top: 70%; left: 10%;"></div>
      <div class="billiard-ball ball-2 floating" style="top: 75%; right: 15%;"></div>
    </div>

    <div class="error-content">
      <!-- Simple 404 Display -->
      <div class="error-number">
        <h1 class="big-404">404</h1>
        <div class="underline"></div>
      </div>

      <!-- Error Message -->
      <div class="error-message">
        <h2 class="error-title">{{ $t('pageNotFound') || 'Page non trouvée' }}</h2>
        <p class="error-description">
          {{ $t('pageNotFoundDescription') || 'Désolé, la page que vous cherchez n\'existe pas ou a été déplacée.' }}
        </p>
        <p class="error-suggestion">
          {{ $t('errorSuggestion') || 'Vérifiez l\'URL ou utilisez les liens ci-dessous pour continuer votre navigation.' }}
        </p>
      </div>

      <!-- Action Buttons -->
      <div class="action-buttons">
        <button @click="goHome" class="btn btn-primary">
          <svg class="btn-icon" fill="currentColor" viewBox="0 0 20 20">
            <path d="M10.707 2.293a1 1 0 00-1.414 0l-7 7a1 1 0 001.414 1.414L4 10.414V17a1 1 0 001 1h2a1 1 0 001-1v-4a1 1 0 011-1h2a1 1 0 011 1v4a1 1 0 001 1h2a1 1 0 001-1v-6.586l.293.293a1 1 0 001.414-1.414l-7-7z"></path>
          </svg>
          {{ $t('backToHome') || 'Retour à l\'accueil' }}
        </button>

        <button @click="goBack" class="btn btn-secondary">
          <svg class="btn-icon" fill="currentColor" viewBox="0 0 20 20">
            <path fill-rule="evenodd" d="M9.707 16.707a1 1 0 01-1.414 0l-6-6a1 1 0 010-1.414l6-6a1 1 0 011.414 1.414L5.414 9H17a1 1 0 110 2H5.414l4.293 4.293a1 1 0 010 1.414z" clip-rule="evenodd"></path>
          </svg>
          {{ $t('goBack') || 'Page précédente' }}
        </button>
      </div>

      <!-- Navigation Links -->
      <div class="navigation-links">
        <router-link to="/multiplayer" class="nav-link">
          <svg class="link-icon" fill="currentColor" viewBox="0 0 20 20">
            <path d="M13 6a3 3 0 11-6 0 3 3 0 016 0zM18 8a2 2 0 11-4 0 2 2 0 014 0zM14 15a4 4 0 00-8 0v3h8v-3zM6 8a2 2 0 11-4 0 2 2 0 014 0zM16 18v-3a5.972 5.972 0 00-.75-2.906A3.005 3.005 0 0119 15v3h-3zM4.75 12.094A5.973 5.973 0 004 15v3H1v-3a3 3 0 013.75-2.906z"></path>
          </svg>
          {{ $t('multiplayer') || 'Multijoueur' }}
        </router-link>

        <router-link to="/profile" class="nav-link" v-if="isAuthenticated">
          <svg class="link-icon" fill="currentColor" viewBox="0 0 20 20">
            <path fill-rule="evenodd" d="M10 9a3 3 0 100-6 3 3 0 000 6zm-7 9a7 7 0 1114 0H3z" clip-rule="evenodd"></path>
          </svg>
          {{ $t('profile') || 'Profil' }}
        </router-link>

        <router-link to="/signin" class="nav-link" v-else>
          <svg class="link-icon" fill="currentColor" viewBox="0 0 20 20">
            <path fill-rule="evenodd" d="M3 3a1 1 0 011 1v12a1 1 0 11-2 0V4a1 1 0 011-1zm7.707 3.293a1 1 0 010 1.414L9.414 9H17a1 1 0 110 2H9.414l1.293 1.293a1 1 0 01-1.414 1.414l-3-3a1 1 0 010-1.414l3-3a1 1 0 011.414 0z" clip-rule="evenodd"></path>
          </svg>
          {{ $t('signIn') || 'Se connecter' }}
        </router-link>

        <router-link to="/game" class="nav-link">
          <svg class="link-icon" fill="currentColor" viewBox="0 0 20 20">
            <path d="M11 17a1 1 0 001.447.894l4-2A1 1 0 0017 15V9.236a1 1 0 00-1.447-.894l-4 2a1 1 0 000 1.788l4 2.094-4 2.094A1 1 0 0011 17z"></path>
          </svg>
          {{ $t('playGame') || 'Jouer' }}
        </router-link>
      </div>
    </div>
  </div>
</template>

<script setup>
import { useRouter } from 'vue-router'
import { useAuth } from '@/composable/useAuths'
import { useI18n } from 'vue-i18n'

const router = useRouter()
const { isAuthenticated } = useAuth()
const { t } = useI18n()

// Methods
const goHome = () => {
  if (isAuthenticated.value) {
    router.push({ name: 'Home2' })
  } else {
    router.push({ name: 'Home' })
  }
}

const goBack = () => {
  if (window.history.length > 1) {
    router.go(-1)
  } else {
    goHome()
  }
}
</script>

<style scoped>
.error-container {
  min-height: 100vh;
  background: linear-gradient(135deg, #1a472a 0%, #2d5a3d 50%, #1a472a 100%);
  color: #f8f9fa;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 2rem;
  position: relative;
  overflow: hidden;
}

.error-content {
  text-align: center;
  max-width: 600px;
  z-index: 2;
}

/* Large 404 Number */
.error-number {
  margin-bottom: 3rem;
}

.big-404 {
  font-size: 8rem;
  font-weight: 900;
  color: #d4af37;
  margin: 0;
  text-shadow: 4px 4px 8px rgba(0, 0, 0, 0.5);
  font-family: 'Georgia', serif;
  line-height: 1;
}

.underline {
  width: 120px;
  height: 4px;
  background: linear-gradient(90deg, #d4af37, #c19b2e);
  margin: 1rem auto;
  border-radius: 2px;
}

/* Error Message */
.error-message {
  margin-bottom: 3rem;
}

.error-title {
  font-size: 2.5rem;
  font-weight: bold;
  color: #d4af37;
  margin-bottom: 1.5rem;
  text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);
  font-family: 'Georgia', serif;
}

.error-description {
  font-size: 1.2rem;
  color: #e0e0e0;
  margin-bottom: 1rem;
  line-height: 1.6;
  opacity: 0.9;
}

.error-suggestion {
  font-size: 1rem;
  color: #bbf7d0;
  opacity: 0.8;
  line-height: 1.6;
}

/* Action Buttons */
.action-buttons {
  display: flex;
  flex-wrap: wrap;
  gap: 1.5rem;
  justify-content: center;
  margin-bottom: 3rem;
}

.btn {
  display: flex;
  align-items: center;
  gap: 0.75rem;
  padding: 1rem 2rem;
  border: none;
  border-radius: 0.75rem;
  font-size: 1.1rem;
  font-weight: 600;
  text-decoration: none;
  cursor: pointer;
  transition: all 0.3s ease;
  min-width: 180px;
  justify-content: center;
}

.btn-icon {
  width: 1.25rem;
  height: 1.25rem;
}

.btn-primary {
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
}

.btn-primary:hover {
  transform: translateY(-3px);
  box-shadow: 0 10px 30px rgba(212, 175, 55, 0.4);
}

.btn-secondary {
  background: rgba(255, 255, 255, 0.1);
  color: #e0e0e0;
  border: 2px solid rgba(255, 255, 255, 0.2);
}

.btn-secondary:hover {
  background: rgba(255, 255, 255, 0.2);
  color: #ffffff;
  transform: translateY(-3px);
  box-shadow: 0 10px 30px rgba(255, 255, 255, 0.1);
}

/* Navigation Links */
.navigation-links {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
  gap: 1.5rem;
  max-width: 500px;
  margin: 0 auto;
}

.nav-link {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  color: #d4af37;
  text-decoration: none;
  font-weight: 600;
  font-size: 1rem;
  transition: all 0.3s ease;
  position: relative;
  padding: 0.75rem 1rem;
  border-radius: 0.5rem;
  background: rgba(212, 175, 55, 0.1);
  border: 1px solid rgba(212, 175, 55, 0.3);
  justify-content: center;
}

.link-icon {
  width: 1.125rem;
  height: 1.125rem;
}

.nav-link:hover {
  color: #f4d03f;
  background: rgba(212, 175, 55, 0.2);
  border-color: #d4af37;
  transform: translateY(-2px);
  box-shadow: 0 4px 15px rgba(212, 175, 55, 0.3);
}

/* Minimal Billiard Ball Decorations */
.billiard-decoration {
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  pointer-events: none;
  z-index: 1;
}

.billiard-ball {
  position: absolute;
  width: 50px;
  height: 50px;
  border-radius: 50%;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.3);
  opacity: 0.7;
}

.ball-1 { background-color: #ffeb3b; }
.ball-2 { background-color: #2196f3; }
.ball-3 { background-color: #f44336; }
.ball-8 { 
  background: radial-gradient(circle at 30% 30%, #333, #000);
  color: white;
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: bold;
  font-size: 1.5rem;
}

.ball-8::after {
  content: '8';
}

.floating {
  animation: gentleFloat 8s ease-in-out infinite;
}

@keyframes gentleFloat {
  0%, 100% { 
    transform: translateY(0px) rotate(0deg);
    opacity: 0.7;
  }
  50% { 
    transform: translateY(-15px) rotate(180deg);
    opacity: 0.9;
  }
}

/* Responsive Design */
@media (max-width: 768px) {
  .error-container {
    padding: 1rem;
  }
  
  .big-404 {
    font-size: 5rem;
  }
  
  .error-title {
    font-size: 2rem;
  }
  
  .error-description {
    font-size: 1.1rem;
  }
  
  .action-buttons {
    flex-direction: column;
    align-items: center;
  }
  
  .btn {
    width: 100%;
    max-width: 300px;
  }
  
  .navigation-links {
    grid-template-columns: 1fr;
    gap: 1rem;
  }
}

@media (max-width: 480px) {
  .big-404 {
    font-size: 4rem;
  }
  
  .error-title {
    font-size: 1.75rem;
  }
  
  .error-description {
    font-size: 1rem;
  }
  
  .btn {
    font-size: 1rem;
    padding: 0.875rem 1.5rem;
  }
  
  .billiard-ball {
    width: 35px;
    height: 35px;
  }
  
  .ball-8 {
    font-size: 1.2rem;
  }
}
</style>