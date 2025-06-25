import Fastify, { FastifyInstance } from 'fastify'
import { testConnection } from './utils/def';
import { syncDatabase } from './utils/db_models/syncDatabase';
import { deleteInactiveUsers } from './routes_def/deleteInactiveUsers';
import auth_plugins from './utils/plugins/auth_plugins';
import routes_profile from './utils/routes';

const fastify: FastifyInstance = Fastify({ logger: true })

setInterval(async () => {
	console.log('🧹 Nettoyage automatique...');
	await deleteInactiveUsers();
}, 24 * 60 * 60 * 1000);

fastify.register(auth_plugins);
fastify.register(routes_profile);

const start = async () => {
	try {
		await testConnection(5, 3000);

		await syncDatabase(3, 2000); // 3 retries, 2 second delay

		await deleteInactiveUsers();

		await fastify.listen({ port: 8002, host: '0.0.0.0' });
	}
	catch (err) {
		fastify.log.error(err)
		process.exit(1)
	}
}

start();