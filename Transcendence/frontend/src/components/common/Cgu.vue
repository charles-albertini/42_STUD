<template>
  <div class="cgu-page min-h-screen bg-gradient-to-br from-green-900 via-green-800 to-green-900 py-10 flex flex-col items-center justify-center">
    <div class="cgu-container">
      <h1 class="text-3xl font-bold text-yellow-400 mb-6 text-center">Conditions d'Utilisation - Pong Billard</h1>
      <div class="cgu-content">
        <p class="text-sm text-gray-300 mb-2">Dernière mise à jour : 22 juin 2025</p>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">1. Qu'est-ce que Pong Billard ?</h2>
        <p>Pong Billard est un jeu en ligne gratuit où vous pouvez jouer contre d'autres joueurs et suivre vos performances.</p>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">2. Votre Compte</h2>
        <h3 class="font-bold text-yellow-200 mt-2">Inscription</h3>
        <ul class="list-disc ml-6 mb-2">
          <li>Vous pouvez créer un compte avec un nom d'utilisateur et un mot de passe ou vous connecter avec Google</li>
          <li>Choisissez un nom d'utilisateur unique</li>
          <li>Vous êtes responsable de votre mot de passe</li>
          <li>Vous devez avoir au moins 13 ans pour utiliser Pong Billard</li>
        </ul>
        <h3 class="font-bold text-yellow-200 mt-2">Vos Données</h3>
        <p>Nous collectons seulement :</p>
        <ul class="list-disc ml-6 mb-2">
          <li>Compte : nom d'utilisateur, mot de passe (crypté), avatar</li>
          <li>Jeu : nombre de parties, victoires, défaites, scores</li>
          <li>Social : votre liste d'amis</li>
        </ul>
        <p>Pour les joueurs se connectant avec Google, nous stockons votre email personnel en plus de votre avatar Google (nous ne conservons pas de mot de passe pour les joueurs Google).</p>
        <h3 class="font-bold text-yellow-200 mt-2">Pourquoi nous collectons vos données</h3>
        <ul class="list-disc ml-6 mb-2">
          <li>Compte : pour vous identifier et sécuriser votre profil</li>
          <li>Jeu : pour calculer vos statistiques et organiser les matchs</li>
          <li>Social : pour gérer votre liste d'amis</li>
        </ul>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">3. Règles du Jeu</h2>
        <div class="flex flex-col md:flex-row gap-6">
          <div class="flex-1">
            <span class="font-bold text-green-400">✅ Autorisé :</span>
            <ul class="list-disc ml-6 mb-2">
              <li>Jouer normalement contre d'autres joueurs</li>
              <li>Ajouter des amis</li>
              <li>Personnaliser votre avatar</li>
            </ul>
          </div>
          <div class="flex-1">
            <span class="font-bold text-red-400">❌ Interdit :</span>
            <ul class="list-disc ml-6 mb-2">
              <li>Tricher ou utiliser des bots</li>
              <li>Harceler d'autres joueurs</li>
            </ul>
          </div>
        </div>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">4. Vos Droits sur vos Données</h2>
        <p>Vous pouvez à tout moment :</p>
        <ul class="list-disc ml-6 mb-2">
          <li>Voir vos données : dans les paramètres du profil</li>
          <li>Exporter vos données : télécharger toutes vos informations</li>
          <li>Modifier : changer nom d'utilisateur, avatar, mot de passe</li>
          <li>Anonymiser : transformer votre compte en "utilisateur anonyme"</li>
          <li>Supprimer : effacer complètement votre compte</li>
        </ul>
        <h3 class="font-bold text-yellow-200 mt-2">Combien de temps nous gardons vos données</h3>
        <ul class="list-disc ml-6 mb-2">
          <li>Tant que votre compte est actif</li>
          <li>30 jours après suppression (pour récupération)</li>
          <li>Historique anonymisé conservé pour les statistiques du jeu</li>
        </ul>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">5. Sécurité</h2>
        <ul class="list-disc ml-6 mb-2">
          <li>Nous protégeons vos données avec des mots de passe cryptés</li>
          <li>L'authentification à 2 facteurs est disponible (recommandée)</li>
          <li>Nous ne partageons jamais vos données avec des tiers</li>
        </ul>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">6. Disponibilité</h2>
        <p>Le jeu est gratuit et le restera.</p>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">7. Si vous ne respectez pas les règles</h2>
        <p>Nous pouvons :</p>
        <ul class="list-disc ml-6 mb-2">
          <li>Suspendre temporairement votre compte</li>
          <li>Supprimer votre compte définitivement</li>
        </ul>
        <h2 class="text-xl font-semibold text-yellow-300 mt-4">8. Contact</h2>
        <p>Une question ? Un problème ?<br>Email : <a href="mailto:kaliszczakm@yahoo.com" class="underline text-yellow-300 hover:text-yellow-400">kaliszczakm@yahoo.com</a></p>
        <p class="mt-6 text-center text-sm text-gray-400">En jouant à Pong Billard, vous acceptez ces conditions d'utilisation.</p>
      </div>
      
      <!-- Bouton retour en bas -->
      <div class="mt-8 flex justify-center">
        <button 
          @click="goBack" 
          class="back-button flex items-center gap-2 px-4 py-2 bg-transparent border-2 border-yellow-400 text-yellow-400 rounded-lg hover:bg-yellow-400 hover:text-green-900 transition-all duration-300 font-semibold text-sm"
        >
          <svg class="w-4 h-4" fill="none" stroke="currentColor" viewBox="0 0 24 24">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 19l-7-7m0 0l7-7m-7 7h18"/>
          </svg>
          RETOUR
        </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import { useRouter } from 'vue-router'

const router = useRouter()

// Fonction pour revenir à la page précédente
const goBack = () => {
  // Utiliser router.go(-1) qui est plus fiable que window.history.back()
  // car il fonctionne avec le système de routage de Vue
  try {
    router.go(-1)
  } catch (error) {
    // Si erreur ou pas d'historique, rediriger vers l'accueil
    router.push('/')
  }
}
</script>

<style scoped>
.cgu-page {
  min-height: 100vh;
  background: linear-gradient(135deg, #1a472a 0%, #2d5a3d 50%, #1a472a 100%);
  color: #f8f9fa;
  position: relative;
  overflow-x: hidden;
  padding: 2rem 0;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: flex-start;
}

.back-button {
  transition: all 0.3s ease;
  user-select: none;
  min-width: 100px;
  background-color: #fbbf24;
  color: #1a1a1a;
  border: 2px solid #fbbf24;
}

.back-button:hover {
  transform: translateY(-1px);
  box-shadow: 0 4px 12px rgba(212, 175, 55, 0.3);
  background-color: #f59e0b;
  border-color: #f59e0b;
}

.back-button:active {
  transform: translateY(0);
}

.cgu-container {
  /* Suppression du fond, bordure, ombre, arrondi pour un affichage pleine page */
  background: none;
  border: none;
  box-shadow: none;
  border-radius: 0;
  max-width: 900px;
  width: 100%;
  max-height: none;
  overflow: visible;
  padding: 0;
}
.cgu-content {
  padding: 2rem 1rem;
  width: 100%;
  max-width: 900px;
  margin: 0 auto;
  background: none;
  color: #f8f9fa;
  scrollbar-width: thin;
  scrollbar-color: #d4af37 #2d5a3d;
}
.cgu-content h2 {
  margin-top: 1.5rem;
  color: #d4af37;
}
.cgu-content h3 {
  color: #22c55e;
}
.cgu-content ul {
  color: #f8f9fa;
}
.cgu-content li {
  margin-bottom: 0.3em;
}
.cgu-content a {
  color: #d4af37;
  text-decoration: underline;
  transition: color 0.2s;
}
.cgu-content a:hover {
  color: #22c55e;
}
.cgu-content .text-yellow-200 {
  color: #22c55e;
}
.cgu-content .text-green-400 {
  color: #22c55e;
}
.cgu-content .text-red-400 {
  color: #ef4444;
}
.cgu-content .text-yellow-300 {
  color: #d4af37;
}
.cgu-content .text-gray-300, .cgu-content .text-gray-400 {
  color: #b5b5b5;
}
.cgu-content .font-bold {
  font-weight: 700;
}
.cgu-content .underline {
  text-decoration: underline;
}
.cgu-content::-webkit-scrollbar {
  width: 8px;
}
.cgu-content::-webkit-scrollbar-thumb {
  background: #d4af37;
  border-radius: 4px;
}
.cgu-content::-webkit-scrollbar-track {
  background: #2d5a3d;
  border-radius: 4px;
}
</style>
