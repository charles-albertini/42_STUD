import { FastifyRequest , FastifyReply } from 'fastify';
import { JWTpayload } from '../utils/interfaces';
import { Friendship } from '../utils/db_models/friendship_model';

export async function acceptRequest(request: FastifyRequest<{ Body: { friendship_id: number } }>, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		const userId = payload.user_id;
		const friendship_id  = request.body.friendship_id;
		if (!friendship_id) {
			return reply.status(400).send({ error: 'Friendship ID is required' });
		}

		const friendship = await Friendship.findOne({
			where: {
				friendship_id: friendship_id,
				user_id1: userId,
				status: 'pending'
			},
		});

		if (!friendship) {
			return reply.status(404).send({ error: 'Friendship not found' });
		}

		await friendship.update({ status: 'accepted' });

		return reply.status(200).send({ message: 'Friend request accepted successfully', });
	}
	catch (error) {
		return reply.status(500).send({ error: 'Internal server error while accepting friend request' });
	}
}