export interface JWTpayload {
	username: string;
	user_id: number;
}

export interface SignUpRequest {
	username: string;
	password: string;
}

export interface GoogleUserInfo {
	id: string;
	email: string;
	verified_email: boolean;
	name: string;
	given_name: string;
	family_name: string;
	picture: string;
	locale: string;
}