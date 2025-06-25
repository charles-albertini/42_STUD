import { FastifyRequest, FastifyReply } from 'fastify';
import { JWTpayload } from '../utils/interfaces';
import { User } from '../utils/db_models/user_model';
import { Friendship } from '../utils/db_models/friendship_model';
import { Op } from 'sequelize';

export async function getFriendsOnlineStatus(request: FastifyRequest, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		const userId = payload.user_id;

		// Récupérer tous les amis de l'utilisateur
		const friendships = await Friendship.findAll({
			where: {
				[Op.or]: [
					{ user_id1: userId, status: 'accepted' },
					{ user_id2: userId, status: 'accepted' }
				]
			}
		});

		// Extraire les IDs des amis
		const friendIds = friendships.map(friendship => {
			return friendship.user_id1 === userId 
				? friendship.user_id2 
				: friendship.user_id1;
		});

		if (friendIds.length === 0) {
			return reply.status(200).send({
				success: true,
				friends_status: {},
				total_friends: 0,
				online_friends: 0
			});
		}

		// Récupérer le statut en ligne de tous les amis
		const friends = await User.findAll({
			where: {
				user_id: { [Op.in]: friendIds }
			},
			attributes: ['user_id', 'username', 'is_online', 'last_seen']
		});

		// Construire l'objet de réponse
		const friendsStatus: { [key: number]: { 
			username: string;
			is_online: boolean; 
			last_seen: Date | null;
		} } = {};

		let onlineCount = 0;

		friends.forEach(friend => {
			const isRecentlyActive = friend.last_seen ? 
				(new Date().getTime() - friend.last_seen.getTime()) < 5 * 60 * 1000 : false;
			
			const isOnline = friend.is_online && isRecentlyActive;
			
			friendsStatus[friend.user_id] = {
				username: friend.username,
				is_online: isOnline,
				last_seen: friend.last_seen
			};

			if (isOnline) {
				onlineCount++;
			}
		});

		return reply.status(200).send({
			success: true,
			friends_status: friendsStatus,
			total_friends: friendIds.length,
			online_friends: onlineCount
		});

	} catch (error) {
		return reply.status(500).send({ 
			success: false,
			error: 'Internal server error while fetching friends online status' 
		});
	}
}