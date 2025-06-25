export interface JWTpayload {
	username: string;
	user_id: number;
}

export interface CreateMatchRequest {
    Players: Array<{
        username: string;
        score: number;
        is_winner: boolean;
    }>;
    game_duration: string;
}