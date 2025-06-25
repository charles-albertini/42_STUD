import { FastifyRequest, FastifyReply } from 'fastify'
import bcrypt from 'bcryptjs'
import { User } from '../utils/db_models/user_model'

export async function sign_in(request: FastifyRequest, reply:FastifyReply) {
	const { username, password } = request.body as {
		username: string;
		password: string;
	};
	const usernameTrimmed = username.trim();
	if (!password || !usernameTrimmed) {
		return reply.code(400).send({ error: 'Username and password are required' })
	}

	try {
		const user = await User.findOne({ where: { username: usernameTrimmed } })
		if (!user) {
		  return reply.code(404).send({ error: 'User not found' })
		}

		const isPasswordValid = await bcrypt.compare(password, user.hashed_password)
		if (!isPasswordValid) {
		  return reply.code(400).send({ error: 'Invalid password' })
		}

		if(user.twoFA) {
			const tmp_token = await reply.jwtSign({
				username: user.username,
				user_id: user.user_id,
				twoFA: true }, { expiresIn: '2m' });
			return reply.code(200).send({ 
				requires2FA: true,
				tmpToken: tmp_token,
				message: '2FA verification required'
			})
		}

		const token = await reply.jwtSign({ username: user.username, user_id: user.user_id }, { expiresIn: '15min'})
		const refreshToken = await reply.jwtSign({ username: user.username, user_id: user.user_id }, { expiresIn: '7d' })

		if (!token || !refreshToken) {
			return reply.code(500).send({ error: 'Failed to generate tokens' })
		}

		const userData = {
			username: user.username,
			userId: user.user_id,
		}
		await user.save();
		
		return reply.code(200).send({ token: token, refreshToken, user: userData })
	}
	catch (error) 
	{
		return reply.code(500).send({ error: 'Internal server error' })
	}
}