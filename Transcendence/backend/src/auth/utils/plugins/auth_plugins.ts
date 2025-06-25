import fp from 'fastify-plugin';
import jwt from '@fastify/jwt'
import { User } from '../db_models/user_model';

export default fp(async (fastify) => {
	fastify.register(jwt, {
		secret: process.env.JWT_SECRET_KEY as string,
		sign: { expiresIn: '15min' }
	});

	fastify.decorate('authenticate', async function (request: any, reply: any) {
		try {
			await request.jwtVerify();
			
			// Mettre à jour le statut en ligne à chaque requête authentifiée
			const payload = request.user;
			if (payload && payload.user_id) {
				try {
					await User.update({
						is_online: true,
						last_seen: new Date()
					}, {
						where: { user_id: payload.user_id }
					});
				} catch (error) {
					// Erreur silencieuse pour ne pas casser l'authentification
					fastify.log.warn('Failed to update user online status:', error);
				}
			}
		} catch (err) {
			reply.code(401).send('Token is invalid or expired');
		}
	});
});