import { FastifyRequest, FastifyReply } from 'fastify'
import bcrypt from 'bcryptjs'
import { User } from '../utils/db_models/user_model'
import { SignUpRequest } from '../utils/interfaces'
import { validateUsername } from '../utils/validation';

export async function sign_up (request: FastifyRequest<{ Body: SignUpRequest }>, reply: FastifyReply)
{
	try {
		const { username, password } = request.body
		if (!username || !password) {
			return reply.status(400).send({ error: 'Username and password are required' })
		}
		if (typeof username !== 'string' || typeof password !== 'string') {
			return reply.status(400).send({ error: 'Username and password must be strings' })
		}
		const usernametrim = username.trim();
		const usernameValidation = validateUsername(usernametrim);
		if (!usernameValidation.isValid) {
			return reply.status(400).send({ error: usernameValidation.error });
		}

		if (password.length < 8 || password.length > 255) {
			return reply.status(400).send({ error: 'Password must be at least 8 characters' })
		}

		const existingUser = await User.findOne({ where: { username: usernametrim } })
		if (existingUser) {
			return reply.status(400).send({ error: 'Username already exists' })
		}
		const hashed_password = await bcrypt.hash(password, 13)
		const newUser = await User.create({
			username: usernametrim,
			email_adress: null,
			hashed_password,
			google_user: false
		})

		if (!newUser) {
			return reply.status(400).send({ error: 'User creation failed' })
		}
		reply.status(201).send({ message: 'User created successfully'})
	}
	catch (error) {
		console.error('Sign up error:', error);
		reply.status(500).send({ error: 'Error creating user' })
	}
}