import { User } from "../utils/db_models/user_model";
import { UserMatch } from "../utils/db_models/user_match_model";
import { Matches } from "../utils/db_models/matches_model";
import { FastifyRequest, FastifyReply } from "fastify";
import { Op } from "sequelize";

export async function getHistory(request: FastifyRequest<{ Params: { username: string } }>, reply: FastifyReply) {
	try {
		const name = request.params.username;
		const user = await User.findOne({where: { username: name },})

		if (!user) {
			return reply.status(404).send({ error: 'User not found' });
		}

		const userMatches = await UserMatch.findAll({ where: { user_id: user.user_id },
			attributes: ['match_id', 'user_score', 'winner'],
			include: [
			{
				model: Matches,
				as: 'match',
				attributes: ['match_id', 'match_date', 'game_duration'],
				include: [
				{
					model: UserMatch,
					as: 'userMatches',
					where: { 
						user_id: { [Op.ne]: user.user_id }
					},
					required: false,
					attributes: ['user_id', 'user_score', 'winner'],
					include: [
					{
						model: User,
						as: 'user',
						attributes: ['username']
					}]
				}]
			}],
			order: [
				[{ model: Matches, as: 'match' }, 'match_date', 'DESC'],
				[{ model: Matches, as: 'match' }, 'match_id', 'DESC']
			]
		});

		if (!userMatches || userMatches.length === 0) {
			return reply.status(200).send({ message: 'No matches found for this user' });
		}
		const formattedMatches = userMatches.map(userMatch => ({
			match_id: (userMatch as any).match.match_id,
			match_date: (userMatch as any).match.match_date,
			game_duration: (userMatch as any).match.game_duration,
			my_score: userMatch.user_score,
			i_won: userMatch.winner,

			opponents: (userMatch as any).match.userMatches?.map((opponent: any) => ({
				username: opponent.user.username,
				score: opponent.user_score,
				won: opponent.winner
			})) || []
		}));

		let matches1v1 = 0;
		let matches1v1v1v1 = 0;

		formattedMatches.forEach(match => {
			const totalPlayers = match.opponents.length + 1;
			if (totalPlayers === 2) {
				matches1v1++;
			} else if (totalPlayers === 4) {
				matches1v1v1v1++;
			}
		});

		return reply.status(200).send({
			total_matches: formattedMatches.length,
			matches_2p: matches1v1,
			matches_4p: matches1v1v1v1,
			matches: formattedMatches
		});

		} catch (error) {
			return reply.status(500).send({ error: 'Internal server error' });
		}
}