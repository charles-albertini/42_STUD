// Service API pour la gestion des matches
import { fetchWithAuth } from './api';

// Interface pour les données d'un joueur dans un match
export interface MatchPlayer {
  username: string;
  score: number;
  is_winner: boolean;
}

// Interface pour les données d'un match à sauvegarder
export interface SaveMatchRequest {
  Players: MatchPlayer[];
  game_duration: string;
}

// Interface pour la réponse de sauvegarde d'un match
export interface SaveMatchResponse {
  message: string;
  match_id: number;
}

// API pour la gestion des matches
export const matchApi = {
  // Sauvegarder un match terminé
  saveMatch: async (matchData: SaveMatchRequest): Promise<SaveMatchResponse> => {
    return await fetchWithAuth('/match/save', {
      method: 'POST',
      body: JSON.stringify(matchData),
    });
  },

  // Récupérer l'historique des matches d'un utilisateur
  getMatchHistory: async (username: string): Promise<any> => {
    return await fetchWithAuth(`/profile/history/${username}`);
  }
};