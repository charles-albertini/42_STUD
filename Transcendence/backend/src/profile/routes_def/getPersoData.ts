import { FastifyRequest, FastifyReply } from 'fastify';
import { User } from '../utils/db_models/user_model';
import { JWTpayload } from '../utils/interfaces';
import { UserMatch } from '../utils/db_models/user_match_model';
import { Matches } from '../utils/db_models/matches_model';
import { Friendship } from '../utils/db_models/friendship_model';

export async function getPersoData(request: FastifyRequest, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		const user = await User.findByPk(payload.user_id);
		if (!user) {
			return reply.status(404).send({ error: 'User not found' });
		}

		const userMatches = await UserMatch.findAll({
			where: { user_id: user.user_id },
			include: [
				{
					model: Matches,
					as: 'match',
					include: [
						{
							model: UserMatch,
							as: 'userMatches',
							include: [
								{
									model: User,
									as: 'user',
									attributes: ['user_id', 'username']
								}]
						}]
				}],
			order: [
				[{ model: Matches, as: 'match' }, 'match_date', 'DESC']
			]
		});

		// 3. Récupérer toutes les relations d'amitié (envoyées et reçues)
		const sentFriendships = await Friendship.findAll({
			where: { user_id1: user.user_id },
				include: [{
					model: User,
					as: 'receiver',
					attributes: ['user_id', 'username']
				}],
			});

			const receivedFriendships = await Friendship.findAll({
			where: { user_id2: user.user_id },
			include: [{
					model: User,
					as: 'sender',
					attributes: ['user_id', 'username']
				}]
			});

		// 4. Formater les données pour l'export GDPR
		const gdprExport = {
			export_info: {
				export_date: new Date().toISOString(),
				user_id: user.user_id,
				format: "JSON",
				gdpr_compliance: "Article 15 (Right of access) & Article 20 (Right to data portability)",
				data_controller: "ft_transcendence"
			},

			personal_information: {
				user_id: user.user_id,
				username: user.username,
				email_address: user.email_adress ? user.email_adress : "No email address set",
				account_created: user.creation_date,
				last_update: user.last_update,
				two_factor_enabled: user.twoFA,
				avatar_data: user.avatar ? "Avatar data present" : "No avatar set",
			
				gaming_statistics: {
					total_matches: user.number_of_matches,
					wins: user.number_of_win,
					losses: user.number_of_lose,
					win_rate: user.number_of_matches > 0 
						? ((user.number_of_win / user.number_of_matches) * 100).toFixed(2) + '%'
						: '0%'
				}
			},

			match_history: userMatches.map(userMatch => {
				const match = (userMatch as any).match;
				const opponents = match.userMatches
					.filter((um: any) => um.user_id !== payload.user_id)
					.map((opponent: any) => ({
						opponent_id: opponent.user.user_id,
						opponent_username: opponent.user.username,
						opponent_score: opponent.user_score,
						opponent_won: opponent.winner
					}));

				return {
					match_id: match.match_id,
					match_date: match.match_date,
					game_duration: match.game_duration,
					my_score: userMatch.user_score,
					i_won: userMatch.winner,
					opponents: opponents
				};
			}),

			friendship_data: {
				sent_friend_requests: sentFriendships.map(friendship => ({
					friendship_id: friendship.friendship_id,
					sent_to_user_id: (friendship as any).receiver.user_id,
					sent_to_username: (friendship as any).receiver.username,
					status: friendship.status,
					request_date: friendship.creation_date,
					last_update: friendship.last_update
				})),

				received_friend_requests: receivedFriendships.map(friendship => ({
					friendship_id: friendship.friendship_id,
					received_from_user_id: (friendship as any).sender.user_id,
					received_from_username: (friendship as any).sender.username,
					status: friendship.status,
					request_date: friendship.creation_date,
					last_update: friendship.last_update
				}))
			},

			data_summary: {
				total_matches_played: userMatches.length,
				total_friendships: sentFriendships.length + receivedFriendships.length,
				active_friendships: [
					...sentFriendships.filter(f => f.status === 'accepted'),
					...receivedFriendships.filter(f => f.status === 'accepted')
				].length,
				pending_sent_requests: sentFriendships.filter(f => f.status === 'pending').length,
				pending_received_requests: receivedFriendships.filter(f => f.status === 'pending').length
			},

			data_retention_info: {
				notice: "Your data is retained as long as your account is active. You can request deletion at any time.",
				deletion_procedure: "Contact support or use the account deletion feature in your profile settings.",
				data_sharing: "Your data is not shared with third parties except as required by law."
			}
		};

		return reply.status(200)
			.header('Content-Type', 'application/json')
			.header('Content-Disposition', `attachment; filename="gdpr_export_user_${payload.username}_${Date.now()}.json"`)
			.send(gdprExport);
	} catch (error) {
		return reply.status(500).send({ error: 'Internal server error' });
	}
}