export interface JWTpayload {
	username: string;
	user_id: number;
}

export interface Pub_User {
	username: string;
	email_adress?: string | null;
	number_of_matches: number;
	number_of_win: number;
	number_of_lose: number;
	ratio: number;
	created_at: Date;
	updated_at: Date;
	avatar: string;
	twoFA?: boolean;
}

export interface UpdateData {
	username?: string;
	avatar?: string;
}

export interface ChangePasswordRequest {
	currentPassword: string;
	newPassword: string;
}