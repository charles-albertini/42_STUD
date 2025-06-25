import Fastify, { FastifyInstance } from 'fastify'
import { testConnection } from './utils/def';
import { syncDatabase } from './utils/db_models/syncDatabase';
import auth_plugins from './utils/plugins/auth_plugins';
import routes_match from './utils/routes';

const fastify: FastifyInstance = Fastify({ logger: true })

fastify.register(auth_plugins);
fastify.register(routes_match);

const start = async () => {
	try {
		await testConnection(5, 3000);

		await syncDatabase(3, 2000); // 3 retries, 2 second delay

		await fastify.listen({ port: 8002, host: '0.0.0.0' });
	}
	catch (err) {
		fastify.log.error(err)
		process.exit(1)
	}
}

start();