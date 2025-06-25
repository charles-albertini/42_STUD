const USERNAME_REGEX = /^[a-zA-Z0-9_]{3,20}$/;

export function validateUsername(username: string): { isValid: boolean; error?: string } {
	if (!username) {
		return { isValid: false, error: 'Username is required' };
	}
	
	if (username.length < 3 || username.length > 20) {
		return { isValid: false, error: 'Username must be between 3 and 20 characters' };
	}
	
	if (!USERNAME_REGEX.test(username)) {
		return { isValid: false, error: 'Username can only contain letters, numbers, and underscores' };
	}
	
	const reservedUsernames = ['admin', 'root', 'system', 'api', 'www', 'mail', 'support'];
	if (reservedUsernames.includes(username.toLowerCase())) {
		return { isValid: false, error: 'This username is reserved' };
	}
	
	return { isValid: true };
}