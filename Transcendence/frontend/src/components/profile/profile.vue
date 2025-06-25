<template>
	<div class="profile min-h-screen bg-gradient-to-br from-green-900 via-green-800 to-green-900 py-10">
	  <div class="container mx-auto px-4">
		<!-- État de chargement -->
		<div v-if="isLoadingData" class="text-center py-20">
		  <div class="animate-spin rounded-full h-32 w-32 border-b-2 border-yellow-500 mx-auto"></div>
		  <p class="text-white mt-4 text-xl">{{ $t('loading') }}...</p>
		</div>

		<!-- Contenu principal -->
		<div>
		  <!-- Section principale du profil -->
		  <div class="profile-container bg-black/40 backdrop-blur-sm p-8 rounded-xl border border-yellow-500/30 shadow-2xl">
			<div class="avatar-section">
			  <div class="avatar-wrapper">
				<img :src="displayAvatar" alt="Avatar" class="avatar" />
				<!-- Bouton d'édition de l'avatar supprimé -->
			  </div>
			  <!-- Suppression du player-rank (classement) -->
			</div>
			<div class="info-section">
			  <div class="info-row">
				<span class="label">{{ $t('username') }}:</span>
				<span class="value profile-username">{{ username }}</span>
			  </div>

			  <div class="info-row">
				<span class="label">{{ $t('status') }}:</span>
				<span class="status online">{{ $t('online') }}</span>
			  </div>

			  <div class="info-row">
				<span class="label">{{ $t('memberSince') }}:</span>
				<span class="value">{{ formatDate(memberSince) }}</span>
			  </div>
			</div>
		  </div>

		  <!-- Composant pour l'édition du profil -->
		  <EditProfileModal 
			:show="showEditProfile"
			:userProfile="editProfileData"
			@close="closeEditProfile"
			@profile-updated="handleProfileUpdated"
		  />
		  
		  <!-- Statistiques Pong -->
		  <div class="stats mt-10">
			<h2 class="text-3xl font-bold text-white mb-4 text-center flex items-center justify-center gap-3">
			  {{ $t('pongStatistics') }}
			</h2>
			
			<!-- Indicateur pour les matchs en ligne uniquement -->
			<div class="online-only-indicator mb-6 text-center">
			  <div class="inline-flex items-center gap-2 bg-blue-600/20 border border-blue-400/50 rounded-lg px-4 py-2">
				<span class="text-blue-300 text-lg">🌐</span>
				<span class="text-blue-100 font-medium">Statistiques des matchs en ligne uniquement</span>
			  </div>
			</div>
			
			<!-- Statistiques principales -->
			<div class="stats-grid mb-8">
			  <div class="stat-card">
				<div class="stat-icon">🌐</div>
				<h3>{{ $t('matchesPlayed') }} (En ligne)</h3>
				<div class="stat-value">{{ pongStats.matchesPlayed }}</div>
			  </div>
			  <div class="stat-card">
				<div class="stat-icon">🏆</div>
				<h3>{{ $t('victories') }} (En ligne)</h3>
				<div class="stat-value">{{ pongStats.victories }}</div>
				<div class="stat-subtitle">{{ pongStats.matchesPlayed - pongStats.victories }} défaites</div>
			  </div>
			  <div class="stat-card">
				<div class="stat-icon">📊</div>
				<h3>{{ $t('winRate') }} (En ligne)</h3>
				<div class="stat-value">{{ winRatePercentage }}%</div>
			  </div>
			  <div class="stat-card">
				<div class="stat-icon">👾</div>
				<h3>Parties à 4 joueurs</h3>
				<div class="stat-value">{{ fourPlayersMatchesCount }}</div>
				<div class="stat-subtitle">Mêlée générale</div>
			  </div>
			</div>

			<!-- Historique des matches et Évolution du Winrate -->
			<div class="charts-section">
			  <!-- Historique des matches détaillé -->
			  <div class="chart-container match-history-extended">
				<h3 class="chart-title">🌐 {{ $t('matchHistory') }} (Matchs en ligne)</h3>
				<div class="history-list" v-if="pongMatchHistory.length > 0">
				  <div 
					v-for="match in pongMatchHistory" 
					:key="match.id"
					class="match-item"
				  >
					<div class="match-result">
					  <div :class="['result-indicator', match.won ? 'win' : 'loss']">
						{{ match.won ? 'V' : 'D' }}
					  </div>
					</div>
					<div class="match-details">
					  <div class="match-score">
						{{ match.playerScore }} - {{ match.opponentScore }}
					  </div>
					  <div class="match-info">
						<span class="match-opponent">
						  <template v-if="match.matchType === '1v1'">
							vs {{ match.opponent }}
						  </template>
						  <template v-else>
							<span class="melee-badge">Mêlée générale</span>
						  </template>
						</span>
						<span class="match-duration">{{ match.duration }}</span>
					  </div>
					  <div class="match-stats">
						<span class="match-date">{{ formatDate(match.date) }}</span>
					  </div>
					  <div v-if="match.matchType === '1v1v1v1'" class="melee-players">
						<span class="melee-title">Joueurs & scores :</span>
						<ul class="melee-list">
						  <li v-for="(op, idx) in [ {username: username, score: match.playerScore}, ...match.allOpponents ]" :key="idx">
							<span class="melee-player">{{ op.username }}</span>
							<span class="melee-score">({{ op.score }})</span>
						  </li>
						</ul>
					  </div>
					</div>
					<div class="match-points">
					  <!-- Suppression de l'affichage des points gagnés/perdus et du ratingChange -->
					</div>
				  </div>
				</div>
				<!-- Message quand aucun historique -->
				<div v-else class="no-history">
				  <div class="no-history-icon">🌐</div>
				  <h4 class="no-history-title">Aucun match en ligne joué</h4>
				  <p class="no-history-text">Commencez à jouer en ligne pour voir votre historique !</p>
				</div>
			  </div>

			  <!-- Diagramme d'évolution du Winrate -->
			  <div class="chart-container">
				<h3 class="chart-title">{{ $t('winrateEvolution') }} (Matchs en ligne)</h3>
				<div class="winrate-chart">
				  <div class="chart-area">
					<svg class="winrate-svg" viewBox="0 0 400 200">
					  <!-- Grille de fond -->
					  <defs>
						<pattern id="winrate-grid" width="40" height="20" patternUnits="userSpaceOnUse">
						  <path d="M 40 0 L 0 0 0 20" fill="none" stroke="#374151" stroke-width="1" opacity="0.3"/>
						</pattern>
					  </defs>
					  <rect width="400" height="200" fill="url(#winrate-grid)" />
					  
					  <!-- Ligne de 50% (ligne de référence) -->
					  <line x1="0" y1="100" x2="400" y2="100" stroke="#6b7280" stroke-width="1" stroke-dasharray="5,5" opacity="0.5"/>
					  
					  <!-- Aire sous la courbe -->
					  <path
						:d="winrateAreaPath"
						fill="url(#winrateGradient)"
						opacity="0.3"
					  />
					  
					  <!-- Ligne de winrate -->
					  <polyline
						:points="winrateLinePoints"
						fill="none"
						stroke="#d4af37"
						stroke-width="3"
						stroke-linecap="round"
						stroke-linejoin="round"
					  />
					  
					  <!-- Points de données -->
					  <circle
						v-for="(point, index) in winratePoints"
						:key="index"
						:cx="point.x"
						:cy="point.y"
						r="4"
						fill="#d4af37"
						stroke="#ffffff"
						stroke-width="2"
					  />
					  
					  <!-- Dégradé pour l'aire -->
					  <defs>
						<linearGradient id="winrateGradient" x1="0%" y1="0%" x2="0%" y2="100%">
						  <stop offset="0%" style="stop-color:#d4af37;stop-opacity:0.8" />
						  <stop offset="100%" style="stop-color:#d4af37;stop-opacity:0.1" />
						</linearGradient>
					  </defs>
					</svg>
				  </div>
				  <div class="chart-labels">
					<span v-for="(data, index) in winrateHistory" :key="index" class="chart-label">
					  {{ formatShortDate(data.date) }}
					</span>
				  </div>
				  <div class="chart-legend">
					<div class="legend-item">
					  <div class="legend-color" style="background-color: #d4af37;"></div>
					  <span>{{ $t('winRate') }}</span>
					</div>
					<div class="current-winrate">
					  {{ $t('current') }}: {{ winRatePercentage }}%
					</div>
				  </div>
				</div>
			  </div>
			</div>
		  </div>

		  <!-- Section GDPR/Confidentialité & Données -->
		  <div v-if="isOwnProfile" class="gdpr-section" style="margin-top: 3rem;">
			<h2 class="gdpr-title">Confidentialité & Données</h2>
			<div class="gdpr-actions">
			  <button class="btn btn-secondary" @click="downloadPersonalData">Télécharger mes données</button>
			  <button class="btn btn-secondary" @click="anonymizeAccount">Anonymiser mon compte</button>
			  <button class="btn btn-primary" @click="deleteAccount">Supprimer mon compte</button>
			</div>
			<p class="gdpr-info">Vous pouvez gérer vos données personnelles conformément à la réglementation RGPD.</p>
		  </div>

		  <!-- Boutons d'action en bas de page -->
		  <div class="profile-actions-bottom">
			<div v-if="isOwnProfile" class="profile-actions-btns">
			  <button 
				@click="openEditProfile" 
				class="profile-btn profile-btn-edit"
			  >
				<svg class="profile-btn-icon" fill="currentColor" viewBox="0 0 20 20"><path d="M17.414 2.586a2 2 0 00-2.828 0l-9.9 9.9A2 2 0 004 14v2a2 2 0 002 2h2a2 2 0 001.414-.586l9.9-9.9a2 2 0 000-2.828l-2.828-2.828zM6 16v-2.586l8.293-8.293 2.586 2.586L8.586 16H6z"></path></svg>
				{{ $t('editProfile') || 'Modifier le profil' }}
			  </button>
			  <router-link 
				to="/Home2" 
				class="profile-btn profile-btn-home"
			  >
				<svg class="profile-btn-icon" fill="currentColor" viewBox="0 0 20 20"><path d="M10.707 2.293a1 1 0 00-1.414 0l-7 7A1 1 0 003 11h1v6a1 1 0 001 1h4a1 1 0 001-1v-4h2v4a1 1 0 001 1h4a1 1 0 001-1v-6h1a1 1 0 00.707-1.707l-7-7z"></path></svg>
				{{ $t('backToHome') || 'Accueil' }}
			  </router-link>
			</div>
			<div v-else class="profile-actions-btns">
			  <router-link 
				to="/friends" 
				class="profile-btn profile-btn-secondary"
			  >
				<svg class="profile-btn-icon" fill="currentColor" viewBox="0 0 20 20"><path d="M13 7a3 3 0 11-6 0 3 3 0 016 0zm-3 5a7 7 0 00-7 7 1 1 0 001 1h12a1 1 0 001-1 7 7 0 00-7-7z"></path></svg>
				{{ $t('backToFriends') || 'Retour aux amis' }}
			  </router-link>
			  <router-link 
				to="/Home2" 
				class="profile-btn profile-btn-home"
			  >
				<svg class="profile-btn-icon" fill="currentColor" viewBox="0 0 20 20"><path d="M10.707 2.293a1 1 0 00-1.414 0l-7 7A1 1 0 003 11h1v6a1 1 0 001 1h4a1 1 0 001-1v-4h2v4a1 1 0 001 1h4a1 1 0 001-1v-6h1a1 1 0 00.707-1.707l-7-7z"></path></svg>
				{{ $t('backToHome') || 'Accueil' }}
			  </router-link>
			</div>
		  </div>
		</div>
	  </div>
	</div>
</template>

<script setup>
import { ref, computed, onMounted, onUnmounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useAuth } from '../../composable/useAuths.ts';
import { useUser } from '../../composable/useUser.ts';
import { useRouter, useRoute } from 'vue-router';
import { userApi } from '../../services/userAPI.ts';
import { DEFAULT_AVATARS_BASE64 } from '../../utils/imageUtils.ts';
import EditProfileModal from './EditProfileModal.vue';

const { t } = useI18n()
const { user: currentUser, isAuthenticated, initializeAuth } = useAuth();
const { fetchUser, isLoading, error } = useUser();
const router = useRouter();
const route = useRoute();

// Détermine si on affiche son propre profil ou celui d'un autre utilisateur
const targetUsername = ref(route.params.username || '');
const isOwnProfile = computed(() => !targetUsername.value || targetUsername.value === currentUser.value?.username);

// État local avec la Composition API
const username = ref('')
const avatar = ref(DEFAULT_AVATARS_BASE64.default) // Utilise l'avatar par défaut en base64
const memberSince = ref(new Date())

// Données backend réelles
const userProfile = ref(null)
const matchHistory = ref([])
const isLoadingData = ref(true)

// Statistiques Pong calculées à partir des vraies données
const pongStats = ref({
  matchesPlayed: 0,
  victories: 0,
  avgReactionTime: 200, // Valeur par défaut
  accuracy: 0,
  longestRally: 0,
  ballControl: 50, // Valeurs simulées pour le moment
  defensivePlay: 50,
  aggressivePlay: 50,
  totalPlayTime: 0
})

// État de la 2FA (lecture seule pour l'affichage, uniquement dans EditProfile)
const twoFactorEnabled = ref(false)

// Computed properties
const winRatePercentage = computed(() => {
  return pongStats.value.matchesPlayed > 0 ? Math.round((pongStats.value.victories / pongStats.value.matchesPlayed) * 100) : 0
})

// Computed pour l'avatar avec fallback
const displayAvatar = computed(() => {
  return avatar.value || DEFAULT_AVATAR
})

// Computed pour détecter si l'avatar actuel est personnalisé (non-défaut)
const isCustomAvatar = computed(() => {
  const currentAvatar = avatar.value
  return currentAvatar && 
         currentAvatar !== DEFAULT_AVATAR && 
         !Object.values(DEFAULT_AVATARS_BASE64).includes(currentAvatar)
})

// URL de l'avatar par défaut (même que le backend)
const DEFAULT_AVATAR = DEFAULT_AVATARS_BASE64.default

// Données d' évolution du winrate (calculées à partir des vraies données)
const winrateHistory = ref([
  { date: new Date(), winrate: 50 }
])

// Historique des matches (formaté pour l'affichage)
const pongMatchHistory = ref([])
// Nombre de parties à 4 joueurs (mêlée générale)
const fourPlayersMatchesCount = computed(() => {
  // Si le backend fournit matches_4p, on l'utilise directement
  if (userProfile.value && typeof userProfile.value.matches_4p === 'number') {
    return userProfile.value.matches_4p;
  }
  // Sinon, fallback sur le calcul local
  return pongMatchHistory.value.filter(match => match.matchType === '1v1v1v1').length;
});
// Nombre de parties à 2 joueurs (1v1)
const twoPlayersMatchesCount = computed(() => {
  if (userProfile.value && typeof userProfile.value.matches_2p === 'number') {
    return userProfile.value.matches_2p;
  }
  return pongMatchHistory.value.filter(match => match.matchType === '1v1').length;
});

// Variables pour l'édition du profil (simplifiées pour le composant)
const showEditProfile = ref(false)

// Computed pour l'interface avec EditProfileModal
const editProfileData = computed(() => {
  return {
    username: username.value,
    twoFA: userProfile.value?.twoFA || false,
    avatar: avatar.value || DEFAULT_AVATAR,
    google_user: userProfile.value?.google_user || false
  }
})

// Fonction utilitaire pour obtenir le username à partir de l'id utilisateur courant
const getCurrentUsernameFromId = () => {
  const userData = JSON.parse(localStorage.getItem('user_data') || '{}');
  return userData.username || '';
}

// Fonction pour charger les données utilisateur depuis le backend
const loadUserData = async () => {
  try {
    isLoadingData.value = true
    
    // Détermine quel utilisateur charger
    let usernameToLoad = '';
    if (isOwnProfile.value) {
      // Toujours utiliser le username à jour lié à l'id utilisateur courant
      usernameToLoad = getCurrentUsernameFromId();
    } else {
      usernameToLoad = targetUsername.value;
    }
    if (!usernameToLoad) throw new Error('Aucun username trouvé');
    
    // Récupérer les informations du profil utilisateur
    const userInfo = await userApi.getUser(usernameToLoad);
    userProfile.value = userInfo
    
    // Mise à jour des données de base
    username.value = userInfo.username || ''
    memberSince.value = new Date(userInfo.created_at) || new Date()
    avatar.value = userInfo.avatar || DEFAULT_AVATAR // Utilise l'avatar par défaut si null en DB

    // Mise à jour du nombre de matchs 2p/4p si présents
    if (typeof userInfo.matches_2p === 'number') {
      userProfile.value.matches_2p = userInfo.matches_2p;
    }
    if (typeof userInfo.matches_4p === 'number') {
      userProfile.value.matches_4p = userInfo.matches_4p;
    }

    // Mise à jour de l'état 2FA (seulement pour son propre profil)
    if (isOwnProfile.value) {
      twoFactorEnabled.value = userInfo.twoFA || false
    }
    
    // Calcul des statistiques à partir des vraies données (sera mise à jour par processMatchHistory)
    pongStats.value.matchesPlayed = 0 // Sera calculé avec les matchs en ligne seulement
    pongStats.value.victories = 0     // Sera calculé avec les matchs en ligne seulement
    
    // Récupérer l'historique des matches depuis le serveur
    try {
      const history = await userApi.getHistory(usernameToLoad)
      if (history && history.matches) {
        matchHistory.value = history.matches
        // Traiter les données d'historique pour les graphiques
        processMatchHistory(history.matches)
      }
    } catch (historyError) {
      // Utiliser des données par défaut si pas d'historique
      generateDefaultData()
    }
    
  } catch (err) {
    // Utiliser des données par défaut en cas d'erreur
    generateDefaultData()
  } finally {
    isLoadingData.value = false
  }
}

const processMatchHistory = (matches) => {
  // Filtrer uniquement les matchs en ligne (exclure les matchs contre l'IA)
  const onlineMatches = matches.filter(match => 
    match.opponents && 
    match.opponents.length > 0 && 
    match.opponents[0]?.username && 
    match.opponents[0]?.username !== 'IA' &&
    match.opponents[0]?.username.toLowerCase() !== 'ia' &&
    match.opponents[0]?.username.toLowerCase() !== 'bot'
  )

  // Séparer les matchs 1v1 (2 joueurs) et 1v1v1v1 (4 joueurs)
  const oneVsOneMatches = onlineMatches.filter(match => match.opponents.length === 1);
  const fourPlayersMatches = onlineMatches.filter(match => match.opponents.length === 3);

  // Mettre à jour les statistiques pour les 1v1 uniquement
  pongStats.value.matchesPlayed = oneVsOneMatches.length;
  pongStats.value.victories = oneVsOneMatches.filter(match => match.i_won).length;

  // Calculer les données de winrate au fil du temps (1v1)
  let wins = 0;
  const winrateData = [];
  oneVsOneMatches.forEach((match, index) => {
    if (match.i_won) wins++;
    const winrate = Math.round((wins / (index + 1)) * 100);
    winrateData.push({
      date: new Date(match.match_date),
      winrate: winrate
    });
  });
  winrateHistory.value = winrateData.length > 0 ? winrateData : [
    { date: new Date(), winrate: pongStats.value.matchesPlayed > 0 ? Math.round((pongStats.value.victories / pongStats.value.matchesPlayed) * 100) : 0 }
  ];

  // Historique pour affichage : on mélange les deux types, mais on précise le type
  // On affiche tous les matchs (1v1 et 1v1v1v1), avec un affichage détaillé pour les 4 joueurs
  pongMatchHistory.value = onlineMatches.map((match, index) => {
    const isFourPlayers = match.opponents.length === 3;
    let matchType = isFourPlayers ? '1v1v1v1' : '1v1';
    let opponentsDisplay = '';
    let playerScore = match.my_score;
    let opponentScore = match.opponents[0]?.score || 0;
    let opponent = match.opponents[0]?.username || 'Inconnu';
    if (isFourPlayers) {
      // Affichage détaillé pour la mêlée générale
      opponentsDisplay = match.opponents.map(op => `${op.username} (${op.score})`).join(' | ');
      // Pour l'affichage principal, on peut mettre le score du joueur et la somme des autres scores
      opponentScore = match.opponents.reduce((acc, op) => acc + (op.score || 0), 0);
      opponent = 'Mêlée générale';
    } else {
      opponentsDisplay = `${match.opponents[0]?.username || 'Inconnu'} (${match.opponents[0]?.score ?? '-'})`;
    }
    return {
      id: index + 1,
      playerScore,
      opponentScore,
      opponent,
      won: match.i_won,
      duration: match.game_duration || formatDuration(match.game_duration),
      date: new Date(match.match_date),
      matchType,
      opponentsDisplay,
      allOpponents: match.opponents
    };
  });
}

// Générer des données par défaut (pas de matchs en ligne)
const generateDefaultData = () => {
  // Réinitialiser les statistiques pour les matchs en ligne seulement
  pongStats.value.matchesPlayed = 0
  pongStats.value.victories = 0
  
  const currentWinRate = 0 // Pas de matchs en ligne = 0% winrate
  winrateHistory.value = [
    { date: new Date(), winrate: currentWinRate }
  ]
  pongMatchHistory.value = []
}

// Fonction pour formater la durée
const formatDuration = (seconds) => {
  if (!seconds) return '0m 0s'
  const mins = Math.floor(seconds / 60)
  const secs = seconds % 60
  return `${mins}m ${secs}s`
}

// Computed pour les graphiques winrate
const winrateLinePoints = computed(() => {
  if (winrateHistory.value.length === 0) return ''
  if (winrateHistory.value.length === 1) {
    // Si un seul point, placer au centre
    return `200,${180 - ((winrateHistory.value[0].winrate / 100) * 160)}`
  }
  return winrateHistory.value.map((item, index) => {
    const x = (index / (winrateHistory.value.length - 1)) * 380 + 10
    const y = 180 - ((item.winrate / 100) * 160)
    return `${x},${y}`
  }).join(' ')
})

const winrateAreaPath = computed(() => {
  if (winrateHistory.value.length === 0) return ''
  if (winrateHistory.value.length === 1) {
    // Si un seul point, créer une petite aire autour de ce point
    const y = 180 - ((winrateHistory.value[0].winrate / 100) * 160)
    return `M 190 180 L 190 ${y} L 210 ${y} L 210 180 Z`
  }
  const points = winrateHistory.value.map((item, index) => {
    const x = (index / (winrateHistory.value.length - 1)) * 380 + 10
    const y = 180 - ((item.winrate / 100) * 160)
    return { x, y }
  })
  
  let path = `M ${points[0].x} 180`
  points.forEach(point => {
    path += ` L ${point.x} ${point.y}`
  })
  path += ` L ${points[points.length - 1].x} 180 Z`
  
  return path
})

const winratePoints = computed(() => {
  if (winrateHistory.value.length === 0) return []
  if (winrateHistory.value.length === 1) {
    // Si un seul point, placer au centre
    const y = 180 - ((winrateHistory.value[0].winrate / 100) * 160)
    return [{ x: 200, y }]
  }
  return winrateHistory.value.map((item, index) => {
    const x = (index / (winrateHistory.value.length - 1)) * 380 + 10
    const y = 180 - ((item.winrate / 100) * 160)
    return { x, y }
  })
})

// Méthodes
const formatDate = (date) => {
  return new Intl.DateTimeFormat('fr-FR', {
    year: 'numeric',
    month: 'short',
    day: 'numeric'
  }).format(date)
}

const formatShortDate = (date) => {
  return new Intl.DateTimeFormat('fr-FR', {
    month: 'short',
    day: 'numeric'
  }).format(date)
}

// Fonctions pour l'édition du profil (simplifiées pour le composant)
const openEditProfile = () => {
  showEditProfile.value = true
}

const closeEditProfile = () => {
  showEditProfile.value = false
}

// Fonction pour gérer la mise à jour du profil depuis le composant
const handleProfileUpdated = async (updatedProfile) => {
  // Mettre à jour les données locales
  username.value = updatedProfile.username
  avatar.value = updatedProfile.avatar

  // Recharge le username à jour depuis le localStorage (user_data)
  const userData = JSON.parse(localStorage.getItem('user_data') || '{}');
  if (userData.username) {
    username.value = userData.username;
  }

  // Recharger les données utilisateur pour synchroniser avec le backend
  await loadUserData()
}

// Hook de cycle de vie pour écouter les matches terminés
const handleMatchCompleted = async (event) => {
  try {
    // Recharger les données utilisateur après le match
    await loadUserData()
  } catch (error) {
    // Erreur silencieuse
  }
}

// Hook de cycle de vie
onMounted(async () => {
  // Initialiser l'authentification
  initializeAuth();
  
  // Le router guard s'occupe déjà de la vérification d'authentification
  // Pas besoin de vérifier ici, nous pouvons directement charger les données
  await loadUserData()
  
  // Ajouter un écouteur d'événements pour les matches terminés
  window.addEventListener('matchCompleted', handleMatchCompleted)
})

// Nettoyage lors du démontage
onUnmounted(() => {
  // Supprimer l'écouteur d'événements
  window.removeEventListener('matchCompleted', handleMatchCompleted)
})

// GDPR actions
const downloadPersonalData = async () => {
  try {
    // Appel à l'API backend pour récupérer les données personnelles
    const token = localStorage.getItem('auth_token');
    const response = await fetch('/api/profile/data', {
      headers: { Authorization: `Bearer ${token}` }
    });
    if (!response.ok) throw new Error('Erreur lors du téléchargement des données');
    const data = await response.json();
    const blob = new Blob([JSON.stringify(data, null, 2)], { type: 'application/json' });
    const url = window.URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'mes_donnees_perso.json';
    a.click();
    window.URL.revokeObjectURL(url);
  } catch (err) {
    alert('Impossible de télécharger vos données personnelles.');
  }
};
const anonymizeAccount = async () => {
  if (!confirm('Êtes-vous sûr de vouloir anonymiser votre compte ? Cette action est irréversible.')) return;
  try {
    const token = localStorage.getItem('auth_token');
    const response = await fetch('/api/profile/anonymization', {
      method: 'PATCH',
      headers: { Authorization: `Bearer ${token}` }
    });
    if (!response.ok) throw new Error('Erreur lors de l\'anonymisation');
    alert('Votre compte a été anonymisé. Vous allez être déconnecté.');
    localStorage.removeItem('auth_token');
    // Si d'autres infos d'auth existent, les supprimer aussi
    localStorage.removeItem('refresh_token');
    sessionStorage.clear();
    // Rediriger vers la page de connexion
    router.push('/signin');
  } catch (err) {
    alert('Impossible d\'anonymiser votre compte.');
  }
};
const deleteAccount = async () => {
  if (!confirm('Êtes-vous sûr de vouloir supprimer votre compte ? Cette action est irréversible.')) return;
  try {
    const token = localStorage.getItem('auth_token');
    const response = await fetch('/api/profile/delete', {
      method: 'DELETE',
      headers: { Authorization: `Bearer ${token}` }
    });
    if (!response.ok) throw new Error('Erreur lors de la suppression');
    alert('Votre compte a été supprimé.');
    window.location.href = '/';
  } catch (err) {
    alert('Impossible de supprimer votre compte.');
  }
};
</script>

<style scoped>
.profile {
  min-height: 100vh;
  background: linear-gradient(135deg, #1a472a 0%, #2d5a3d 50%, #1a472a 100%);
  color: #f8f9fa;
  position: relative;
  overflow-x: hidden;
  padding: 2rem 0;
}

.profile-container {
  display: flex;
  margin: 30px 0;
  gap: 40px;
  color: #ffffff;
  background: rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(10px);
  padding: 2rem;
  border-radius: 1rem;
  border: 1px solid rgba(212, 175, 55, 0.3);
}

.avatar-section {
  display: flex;
  flex-direction: column;
  align-items: center;
  min-width: 200px;
}

.avatar-wrapper {
  position: relative;
}

.avatar {
  width: 150px;
  height: 150px;
  border-radius: 50%;
  border: 4px solid #d4af37;
  object-fit: cover;
  margin-bottom: 15px;
  transition: transform 0.3s ease;
  box-shadow: 0 8px 20px rgba(0, 0, 0, 0.3);
}

.avatar:hover {
  transform: scale(1.05);
}

.info-section {
  flex: 1;
  text-align: left;
}

.info-row {
  margin-bottom: 20px;
  display: flex;
  align-items: center;
  gap: 15px;
}

.username-field {
  display: flex;
  align-items: center;
  gap: 15px;
  flex: 1;
}

.security-field {
  display: flex;
  align-items: center;
  gap: 15px;
  flex: 1;
}

.label {
  width: 150px;
  font-weight: bold;
  color: #d4af37;
  font-size: 1.1em;
}

.value {
  font-size: 1.1em;
  color: #f8f9fa;
}

.status {
  padding: 6px 12px;
  border-radius: 12px;
  font-size: 0.9em;
  font-weight: bold;
}

.status.online {
  background-color: #22c55e;
  color: white;
}

.btn {
  padding: 12px 20px;
  border: none;
  border-radius: 8px;
  background: rgba(255, 255, 255, 0.1);
  color: #f8f9fa;
  cursor: pointer;
  font-size: 1em;
  font-weight: 600;
  transition: all 0.3s ease;
  border: 2px solid rgba(212, 175, 55, 0.3);
  backdrop-filter: blur(10px);
}

.btn:hover {
  background: rgba(255, 255, 255, 0.15);
  border-color: #d4af37;
  transform: translateY(-2px);
}

.stats-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  gap: 20px;
  margin-top: 20px;
}

.stat-card {
  background: rgba(255, 255, 255, 0.1);
  border: 1px solid rgba(212, 175, 55, 0.3);
  border-radius: 1rem;
  padding: 20px;
  color: #f8f9fa;
  text-align: center;
  transition: all 0.3s ease;
  backdrop-filter: blur(10px);
}

.stat-card:hover {
  transform: translateY(-5px);
  background: rgba(255, 255, 255, 0.15);
  border-color: #d4af37;
  box-shadow: 0 10px 25px rgba(212, 175, 55, 0.2);
}

.stat-icon {
  font-size: 2em;
  margin-bottom: 8px;
}

.stat-card h3 {
  color: #d4af37;
  margin-bottom: 10px;
  font-size: 0.9em;
  font-weight: 600;
}

.stat-value {
  font-size: 2em;
  font-weight: bold;
  color: #f8f9fa;
  margin-top: 8px;
}

.charts-section {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 30px;
  margin-top: 30px;
}

.match-history-extended {
  grid-column: 1;
}

.chart-container {
  background: rgba(255, 255, 255, 0.1);
  border: 1px solid rgba(212, 175, 55, 0.3);
  border-radius: 1rem;
  padding: 24px;
  backdrop-filter: blur(10px);
}

.chart-title {
  color: #d4af37;
  font-size: 1.3em;
  font-weight: 600;
  margin-bottom: 20px;
  text-align: center;
  text-shadow: 0 2px 4px rgba(0, 0, 0, 0.3);
}

.skills-chart {
  display: flex;
  flex-direction: column;
  gap: 15px;
}

.skill-item {
  display: flex;
  flex-direction: column;
  gap: 8px;
}

.skill-info {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.skill-name {
  color: #f8f9fa;
  font-weight: 600;
}

.skill-value {
  color: #d4af37;
  font-weight: bold;
}

.skill-bar {
  height: 12px;
  background-color: rgba(255, 255, 255, 0.1);
  border-radius: 6px;
  overflow: hidden;
}

.skill-fill {
  height: 100%;
  border-radius: 6px;
  transition: width 1s ease;
}

/* Styles pour l'historique des matches étendu */
.match-history-extended .history-list {
  max-height: 400px;
  overflow-y: auto;
  scrollbar-width: none; /* Firefox */
}

.match-history-extended .history-list::-webkit-scrollbar {
  display: none; /* Chrome, Safari, Opera */
}

/* Styles pour le message "Aucun historique" */
.no-history {
  text-align: center;
  padding: 40px 20px;
  color: #f8f9fa;
}

.no-history-icon {
  font-size: 4em;
  margin-bottom: 20px;
  opacity: 0.6;
}

.no-history-title {
  font-size: 1.5em;
  font-weight: bold;
  color: #d4af37;
  margin-bottom: 10px;
}

.no-history-text {
  color: #e0e0e0;
  margin-bottom: 25px;
  font-size: 1.1em;
}

/* Styles pour le graphique de winrate */
.winrate-chart {
  display: flex;
  flex-direction: column;
  gap: 15px;
}

.chart-area {
  position: relative;
  height: 200px;
}

.winrate-svg {
  width: 100%;
  height: 100%;
}

.chart-labels {
  display: flex;
  justify-content: space-between;
  color: #e0e0e0;
  font-size: 0.8em;
  padding: 0 10px;
}

.chart-legend {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-top: 10px;
}

.legend-item {
  display: flex;
  align-items: center;
  gap: 8px;
  color: #f8f9fa;
}

.legend-color {
  width: 12px;
  height: 12px;
  border-radius: 2px;
}

.current-winrate {
  color: #d4af37;
  font-weight: bold;
}

.match-history {
  background: rgba(255, 255, 255, 0.1);
  border: 1px solid rgba(212, 175, 55, 0.3);
  border-radius: 1rem;
  padding: 24px;
  backdrop-filter: blur(10px);
}

.history-list {
  display: flex;
  flex-direction: column;
  gap: 15px;
}

.match-item {
  display: flex;
  align-items: center;
  gap: 20px;
  padding: 15px;
  background: rgba(255, 255, 255, 0.1);
  border-radius: 8px;
  border: 1px solid rgba(212, 175, 55, 0.3);
  transition: all 0.3s ease;
  backdrop-filter: blur(10px);
}

.match-item:hover {
  border-color: #d4af37;
  transform: translateX(5px);
  background: rgba(255, 255, 255, 0.15);
}

.result-indicator {
  width: 40px;
  height: 40px;
  border-radius: 50%;
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: bold;
  font-size: 1.2em;
}

.result-indicator.win {
  background-color: #22c55e;
  color: white;
}

.result-indicator.loss {
  background-color: #ef4444;
  color: white;
}

.match-details {
  flex: 1;
}

.match-score {
  font-size: 1.3em;
  font-weight: bold;
  color: #f8f9fa;
  margin-bottom: 4px;
}

.match-info {
  display: flex;
  gap: 15px;
  margin-bottom: 4px;
}

.match-opponent {
  color: #d4af37;
  font-weight: 600;
}

.match-duration {
  color: #e0e0e0;
  font-size: 0.9em;
}

.match-stats {
  display: flex;
  gap: 15px;
}

.match-date {
  color: #e0e0e0;
  font-size: 0.8em;
}

/* Animation de chargement */
.animate-spin {
  animation: spin 1s linear infinite;
}

@keyframes spin {
  from { transform: rotate(0deg); }
  to { transform: rotate(360deg); }
}

/* Styles pour les boutons d'action */
.bg-yellow-500 {
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
}

.bg-yellow-500:hover {
  background: linear-gradient(135deg, #c19b2e, #b8941f);
}

.bg-green-600 {
  background: rgba(34, 197, 94, 0.8);
  color: white;
  border: 1px solid rgba(34, 197, 94, 0.3);
  backdrop-filter: blur(10px);
}

.bg-green-600:hover {
  background: rgba(34, 197, 94, 0.9);
  border-color: rgba(34, 197, 94, 0.6);
}

.bg-gray-600 {
  background: rgba(255, 255, 255, 0.1);
  color: #f8f9fa;
  border: 1px solid rgba(212, 175, 55, 0.3);
  backdrop-filter: blur(10px);
}

.bg-gray-600:hover {
  background: rgba(255, 255, 255, 0.15);
  border-color: #d4af37;
}

/* Classes utilitaires */
.font-bold { font-weight: bold; }
.py-3 { padding-top: 0.75rem; padding-bottom: 0.75rem; }
.px-6 { padding-left: 1.5rem; padding-right: 1.5rem; }
.rounded-lg { border-radius: 0.5rem; }
.transition-colors { transition: all 0.3s ease; }
.items-center { align-items: center; }
.gap-2 { gap: 0.5rem; }
.gap-4 { gap: 1rem; }
.mt-8 { margin-top: 2rem; }
.flex { display: flex; }
.justify-center { justify-content: center; }

/* Styles pour l'interactivité des cartes de statistiques */
.stat-card.interactive {
  cursor: pointer;
  position: relative;
  overflow: hidden;
}

.stat-card.interactive:hover {
  transform: translateY(-5px) scale(1.02);
  box-shadow: 0 15px 30px rgba(212, 175, 55, 0.3);
}

.stat-card.interactive.active {
  border-color: #d4af37;
  background: rgba(212, 175, 55, 0.1);
  box-shadow: 0 0 20px rgba(212, 175, 55, 0.4);
}

.stat-subtitle {
  font-size: 0.8em;
  color: #e0e0e0;
  margin-top: 5px;
}

.interaction-indicator {
  position: absolute;
  top: 8px;
  right: 8px;
  font-size: 0.8em;
  opacity: 0.7;
  transition: all 0.3s ease;
}

.stat-card.interactive:hover .interaction-indicator {
  opacity: 1;
  transform: scale(1.2);
}

/* Styles pour l'état de sécurité */
.security-status {
  padding: 4px 8px;
  border-radius: 4px;
  font-weight: 500;
  background: rgba(239, 68, 68, 0.2);
  color: #fca5a5;
  border: 1px solid rgba(239, 68, 68, 0.3);
}

.security-status.secure {
  background: rgba(34, 197, 94, 0.2);
  color: #86efac;
  border: 1px solid rgba(34, 197, 94, 0.3);
}

/* Section GDPR */
.gdpr-section {
  background: rgba(255,255,255,0.05);
  border: 1px solid rgba(212, 175, 55, 0.2);
  border-radius: 1rem;
  padding: 2rem;
  margin-top: 2rem;
  text-align: center;
}
.gdpr-title {
  color: #d4af37;
  font-size: 1.3em;
  font-weight: 600;
  margin-bottom: 1rem;
}
.gdpr-actions {
  display: flex;
  justify-content: center;
  gap: 1.5rem;
  margin-bottom: 1rem;
  flex-wrap: wrap;
}
.gdpr-info {
  color: #e0e0e0;
  font-size: 0.95em;
  margin-top: 1rem;
}

/* Ajout du style pour le pseudo dans la section info-row */
.profile-username {
  color: #d4af37;
  font-size: 1.2em;
  font-weight: bold;
  letter-spacing: 1px;
  padding-left: 0.5em;
}

/* Styles pour les boutons d'action en bas de page */
.profile-actions-bottom {
  display: flex;
  justify-content: center;
  align-items: center;
  margin-top: 3rem;
  margin-bottom: 1.5rem;
}
.profile-actions-btns {
  display: flex;
  gap: 2rem;
  flex-wrap: wrap;
}
.profile-btn {
  display: flex;
  align-items: center;
  gap: 0.75rem;
  font-size: 1.1rem;
  font-weight: 700;
  padding: 1rem 2rem;
  border-radius: 0.75rem;
  border: none;
  min-width: 160px;
  justify-content: center;
  text-decoration: none;
  cursor: pointer;
  transition: all 0.3s ease;
  letter-spacing: 1px;
}
.profile-btn.profile-btn-edit {
  background: linear-gradient(135deg, #d4af37, #c19b2e);
  color: #1a1a1a;
  box-shadow: 0 4px 15px rgba(212, 175, 55, 0.3);
  border: none;
}
.profile-btn.profile-btn-edit:hover {
  background: linear-gradient(135deg, #c19b2e, #d4af37);
  color: #1a1a1a;
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(212, 175, 55, 0.4);
}
.profile-btn.profile-btn-home {
  background: transparent;
  color: #d4af37;
  border: 2px solid #d4af37;
  box-shadow: none;
}
.profile-btn.profile-btn-home:hover {
  background: #d4af37;
  color: #1a1a1a;
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(212, 175, 55, 0.3);
}
.profile-btn.profile-btn-secondary {
  background: transparent;
  color: #d4af37;
  border: 2px solid #d4af37;
  box-shadow: none;
}
.profile-btn.profile-btn-secondary:hover {
  background: #d4af37;
  color: #1a1a1a;
  transform: translateY(-2px);
  box-shadow: 0 8px 25px rgba(212, 175, 55, 0.3);
}
.profile-btn-icon {
  width: 22px;
  height: 22px;
}
</style>
