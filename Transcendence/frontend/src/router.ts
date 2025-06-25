import { createRouter, createWebHistory } from "vue-router";
import Home from "./components/home&sig/Home.vue";
import Home2 from "./components/home&sig/Home2.vue";
import Game from "./components/game/local/Gameia.vue";
import Profile from "./components/profile/profile.vue";
import Signin from "./components/home&sig/signin.vue";
import Gamemulti from "./components/game/local/Gamemulti.vue";
import Signup from "./components/home&sig/signup.vue";
import Tournamentgame from "./components/tournament/tournamentgame.vue";
import Tournamentbracket from "./components/tournament/tournamentbracket.vue";
import Tournamentplayer from "./components/tournament/tournamentplayer.vue";
import CreateOrJoin from "./components/game/online/CreateOrJoin.vue";

// Fonction de vérification d'authentification
const isAuthenticated = () => {
  const authToken = localStorage.getItem('auth_token');
  const userToken = localStorage.getItem('user-token');
  return authToken !== null || userToken !== null;
};

const routes = [
  {
    path: "/",
    name: "Home",
    component: Home,
  },
  {
    path: "/Home2",
    name: "Home2",
    component: Home2,
  },
  {
    path: "/tournamentgame",
    name: "tournamentgame",
    component: Tournamentgame,
  },
  {
    path: "/signup",
    name: "Signup",
    component: Signup,
  },
  {
    path: "/game",
    name: "Game",
    component: Game,
  },
  {

	path: "/Gamemulti",
	name: "Gamemulti",
	component: Gamemulti,
  },
  {
    path: "/profile",
    name: "Profile",
    component: Profile,
  },
  {
    path: "/profile/:username",
    name: "UserProfile", 
    component: Profile,
    props: true
  },
  {
    path: "/signin",
    name: "Signin",
    component: Signin,
  },
  {
    path: "/tournamentbracket",
    name: "tournamentbracket",
    component: Tournamentbracket,
  },
    {
    path: "/tournamentplayer",
    name: "tournamentplayer",
    component: Tournamentplayer,
  },
  {
    path: "/Gamemulti",
    redirect: { name: "MultiplayerLocal" }
  },
  // 5) Hub multijoueur
  {
    path: "/multiplayer",
    name: "MultiplayerHub",
    component: () => import("./components/game/online/MultiplayerHub.vue")
  },
  // 6) Choix “Créer ou Rejoindre” (mode en ligne)
  {
    path: "/multiplayer/choose",
    name: "CreateOrJoin",
    component: CreateOrJoin
  },

  {
    path: "/multiplayer/join",
    name: "JoinGame",
    component: () => import("./components/game/online/JoinGame.vue")
  },
  {
    path: "/waiting-room",
    name: "WaitingRoom",
    component: () => import("./components/game/online/WaitingRoom.vue")
  },
  {
    path: "/gamemulti-online",
    name: "GamemultiOnline",
    component: () => import("./components/game/online/GamemultiOnline.vue")
  },
  // 8) Route “Local” depuis le hub multijoueur (alias)
  {
    path: "/multiplayer/local",
    name: "MultiplayerLocal",
    component: Gamemulti
  },
  // Routes pour l'authentification Google
  {
    path: "/auth/success",
    name: "GoogleAuthSuccess",
    component: () => import("./components/home&sig/auth/GoogleAuthCallback.vue")
  },
  {
    path: "/auth/error",
    name: "GoogleAuthError",
    component: () => import("./components/home&sig/auth/GoogleAuthCallback.vue")
  },
  // Route pour la page de gestion des amis
  {
    path: "/friends",
    name: "Friends",
    component: () => import("./components/friends/friendsview.vue"),
    meta: { requiresAuth: true }
  },
  {
    path: "/cgu",
    name: "Cgu",
    component: () => import("./components/common/Cgu.vue")
  },
  {
    path: "/:pathMatch(.*)*",
    name: "NotFound",
    component: () => import("./components/common/NotFound.vue")
  }
];

const router = createRouter({
  history: createWebHistory(),
  routes,
  // Ajout d'options pour améliorer la navigation
  scrollBehavior(_to, _from, savedPosition) {
    if (savedPosition) {
      return savedPosition;
    } else {
      return { top: 0 };
    }
  },
});

// Navigation guard
router.beforeEach((to, _from, next) => {
  // Liste des routes protégées qui nécessitent une authentification
  const protectedRoutes = ['/profile', '/friends', '/multiplayer/choose'];
  
  // Si la route est protégée et que l'utilisateur n'est pas authentifié
  if (protectedRoutes.includes(to.path) && !isAuthenticated()) {
    // Rediriger vers la page de connexion avec une redirection de retour
    next({ 
      path: '/signin',
      query: { redirect: to.fullPath }
    });
  } else {
    next();
  }
});

export default router;
