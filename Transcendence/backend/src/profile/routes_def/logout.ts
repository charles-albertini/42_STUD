import { FastifyRequest, FastifyReply } from 'fastify';
import { JWTpayload } from '../utils/interfaces';
import { User } from '../utils/db_models/user_model';

export async function logout(request: FastifyRequest, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		
		// Marquer l'utilisateur comme hors ligne
		await User.update({
			is_online: false,
			last_seen: new Date()
		}, {
			where: { user_id: payload.user_id }
		});

		return reply.status(200).send({ 
			success: true,
			message: 'Logged out successfully' 
		});

	} catch (error) {
		return reply.status(500).send({ 
			success: false,
			error: 'Internal server error during logout' 
		});
	}
}