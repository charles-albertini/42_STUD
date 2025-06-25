import { FastifyRequest, FastifyReply } from 'fastify';
import speakeasy from 'speakeasy';
import { User } from '../utils/db_models/user_model';
import { JWTpayload } from '../utils/interfaces';

interface Check2FARequest {
	code: string;
}

export async function check2FA(request: FastifyRequest, reply: FastifyReply) {
	const payload = request.user as JWTpayload;
	const id = payload.user_id;
	const user = await User.findByPk(id);

	if (!user) {
		return reply.code(404).send({ error: 'User not found' });
	}
	if (user.google_user) {
		return reply.status(400).send({ error: 'Cannot check 2FA for Google-authenticated users' });
	}

	const { code: code2FA } = request.body as Check2FARequest;
	if (!code2FA) {
		return reply.code(400).send({ error: 'Code is required' });
	}

	if (!/^\d{6}$/.test(code2FA)) {
		return reply.code(400).send({ error: 'Le token doit contenir 6 chiffres' });
	}

	const verified = speakeasy.totp.verify({
		secret: user.twoFA_secret as string,
		encoding: 'base32',
		token: code2FA,
		window: 1, // Accepte les tokens avec 1 période de tolérance (30s avant/après)
	});
	if (!verified) {
		return reply.code(400).send({ error: 'Invalid 2FA code' });
	}

	if (!user.twoFA && user.twoFA_secret) {
		await user.update( { twoFA: true } );
	}
	
	const token = await reply.jwtSign(
		{ username: user.username, user_id: user.user_id },
		{ expiresIn: '15min' }
	);
	const refreshToken = await reply.jwtSign(
		{ username: user.username, user_id: user.user_id },
		{ expiresIn: '7d' }
	);

	const userData = {
		username: user.username,
		userId: user.user_id,
	}
	await user.save();

	return reply.code(200).send({ token: token, refreshToken, user: userData });
}