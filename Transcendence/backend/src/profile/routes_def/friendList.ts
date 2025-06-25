import { FastifyRequest, FastifyReply } from 'fastify';
import { Friendship } from '../utils/db_models/friendship_model';
import { User } from '../utils/db_models/user_model';
import { Op } from 'sequelize';
import { JWTpayload } from '../utils/interfaces';

export async function friendList(request: FastifyRequest, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		const userId = payload.user_id;

		if (!userId) {
			return reply.status(400).send({ error: 'User ID is required' });
		}

		const friendships = await Friendship.findAll({
			where: {
				[Op.or]: [
					{ user_id1: userId, status: 'accepted' },
					{ user_id2: userId, status: 'accepted' }
				]
			},
			include: [
				{
					model: User,
					as: 'sender',
					attributes: ['user_id', 'username']
				},
				{
					model: User,
					as: 'receiver',
					attributes: ['user_id', 'username']
				}
			],
			order: [['creation_date', 'DESC']]
		});

		if (!friendships || friendships.length === 0) {
			return reply.code(200).send({
				message: 'No friends found',
				friends: []
			});
		}

		const formattedFriends = friendships.map(friendship => {
			const friendUser = friendship.user_id1 === userId 
				? (friendship as any).receiver 
				: (friendship as any).sender;

			return {
				friendship_id: friendship.friendship_id,
				friend: { 
					username: friendUser.username 
				},
				creation_date: friendship.creation_date,
				status: friendship.status
			};
		});

		return reply.code(200).send({
			total_friends: formattedFriends.length,
			friends: formattedFriends
		});
	}
	catch (error) {
		return reply.status(500).send({ error: 'Internal server error while fetching friend list' });
	}
}