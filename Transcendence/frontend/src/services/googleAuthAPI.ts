// Service pour l'authentification Google
export class GoogleAuthService {
  private static instance: GoogleAuthService
  
  static getInstance(): GoogleAuthService {
    if (!GoogleAuthService.instance) {
      GoogleAuthService.instance = new GoogleAuthService()
    }
    return GoogleAuthService.instance
  }

  // Initier la connexion Google
  initiateGoogleLogin(): void {
    // Rediriger vers l'endpoint Google OAuth du backend
    window.location.href = '/api/auth/google'
  }

  // Extraire les tokens de l'URL (après redirection depuis Google)
  extractTokensFromUrl(): { token: string | null, refreshToken: string | null } {
    const urlParams = new URLSearchParams(window.location.search)
    return {
      token: urlParams.get('token'),
      refreshToken: urlParams.get('refreshToken')
    }
  }

  // Nettoyer l'URL après extraction des tokens
  cleanUrl(): void {
    const url = new URL(window.location.href)
    url.search = ''
    window.history.replaceState({}, document.title, url.toString())
  }

  // Vérifier si l'authentification Google a échoué
  isAuthenticationError(): boolean {
    const urlParams = new URLSearchParams(window.location.search)
    return urlParams.has('error') || window.location.pathname.includes('error')
  }
}

// Export de l'instance singleton
export const googleAuthService = GoogleAuthService.getInstance()
