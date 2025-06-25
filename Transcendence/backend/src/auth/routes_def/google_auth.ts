import { FastifyRequest, FastifyReply } from 'fastify';
import axios from 'axios';
import { User } from '../utils/db_models/user_model';
import { GoogleUserInfo } from '../utils/interfaces';

export async function googleCallback(request: FastifyRequest, reply: FastifyReply) {
	try {
		// Le plugin fait l'échange code → token automatiquement
		const { token } = await (request.server as any).googleOAuth2.getAccessTokenFromAuthorizationCodeFlow(request);

		// Récupérer les infos utilisateur avec le token
		const userResponse = await axios.get('https://www.googleapis.com/oauth2/v2/userinfo', {
			headers: {
				Authorization: `Bearer ${token.access_token}`
			}
		});
		const googleUser: GoogleUserInfo = userResponse.data;
		if (!googleUser.verified_email) {
			return reply.status(400).send({ error: 'Email not verified with Google' });
		}

		let user = await User.findOne({
			where: { email_adress: googleUser.email }
		});

		if (!user)
		{
			const baseName = googleUser.name.toLowerCase().replace(/[^a-z0-9]/g, '').substring(0, 8);
			const timestamp = Date.now().toString().slice(-4);
			const randomNum = Math.floor(Math.random() * 99);
			const googleIdSuffix = googleUser.id.slice(-3);
		
			const usernameOptions = [
				baseName,
				`${baseName}_${timestamp}`,
				`${baseName}_${randomNum}`,
				`${baseName}_${googleIdSuffix}`,
				`user_${timestamp}`,
				`u_${timestamp}_${randomNum}`
			].filter(username => username.length <= 20);
		
			const existingUsers = await User.findAll({
				where: {
					username: usernameOptions
				},
				attributes: ['username']
			});
		
			const takenUsernames = existingUsers.map(user => user.username);
			let finalUsername = usernameOptions.find(username => !takenUsernames.includes(username));
		
			if (!finalUsername) {
				const uniqueSuffix = Date.now().toString() + Math.floor(Math.random() * 999);
				finalUsername = `u_${uniqueSuffix}`.substring(0, 20);
			}
		
			user = await User.create({
				username: finalUsername,
				email_adress: googleUser.email,
				hashed_password: 'GOOGLE_OAUTH_USER',
				avatar: googleUser.picture,
				google_user: true,
			});
		}

		const jwtToken = await reply.jwtSign(
			{ username: user.username, user_id: user.user_id },
			{ expiresIn: '15min' }
		);

		const refreshToken = await reply.jwtSign(
			{ username: user.username, user_id: user.user_id },
			{ expiresIn: '7d' }
		);
		
		const userData = {
			username: user.username,
			userId: user.user_id,
		}
		await user.save();
		const frontendUrl = process.env.FRONTEND_URL || 'https://localhost:5000';
		return reply.redirect(`${frontendUrl}/Home2?token=${encodeURIComponent(jwtToken)}&refreshToken=${encodeURIComponent(refreshToken)}&userData=${encodeURIComponent(JSON.stringify(userData))}`);
	}
	catch (error) {
		const frontendUrl = process.env.FRONTEND_URL || 'https://localhost:5000';
		return reply.code(400).redirect(`${frontendUrl}/signin`);
	}
}