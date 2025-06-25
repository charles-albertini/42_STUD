import { Sequelize } from 'sequelize';
import dotenv from 'dotenv';

dotenv.config({ path: '../../.env' });

export const sequelize = new Sequelize({
    database: process.env.MARIADB_DATABASE,
    username: process.env.MARIADB_USER,
    password: process.env.MARIADB_PASSWORD,
    host: 'db',
    port: 3306,
    dialect: 'mariadb',
    logging: false,
});

async function testConnection(maxRetries = 5, delay = 3000) {
    for (let attempt = 1; attempt <= maxRetries; attempt++) {
        try {
            await sequelize.authenticate();
            return true;
        } catch (error) {
            if (attempt === maxRetries) {
                process.exit(1);
            }
            
            await new Promise(resolve => setTimeout(resolve, delay));
        }
    }
}

import './db_models/associations';

export { testConnection}
export default sequelize;