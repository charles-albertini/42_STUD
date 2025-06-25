import { User } from "../utils/db_models/user_model";
import { FastifyRequest, FastifyReply } from "fastify";
import { JWTpayload, UpdateData } from "../utils/interfaces";
import { validateUsername } from "../utils/validation";

export async function update(request: FastifyRequest<{ Body: UpdateData }>, reply: FastifyReply) {
	try {
		const payload = request.user as JWTpayload;
		const userId = payload.user_id;
		const update_payload = request.body as UpdateData;

		if (!update_payload) {
			return reply.status(400).send({ error: 'No update data provided' });
		}

		const user = await User.findByPk(userId);
		if (!user) {
			return reply.status(404).send({ error: 'User not found' });
		}

		if (update_payload.username) {
			const checkUsername = validateUsername(update_payload.username.trim());
			if (!checkUsername.isValid) {
				return reply.status(400).send({ error: 'Invalid username format' });
			}

			const existingUser = await User.findOne({
				where: { username: update_payload.username.trim() },
			});
			if (existingUser && existingUser.user_id !== userId) {
				return reply.status(400).send({ error: 'Username already exists' });
			}
			else {
				user.username = update_payload.username;
			}
		}

		if (update_payload.avatar) {
			user.avatar = update_payload.avatar;
		}

		await user.save();
		return reply.status(200).send({ message: 'User updated successfully'});
	}
	catch (error) {
		return reply.status(500).send({ error: 'Internal server error while updating user' });
	}
}