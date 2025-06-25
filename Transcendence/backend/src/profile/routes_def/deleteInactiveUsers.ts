import { User } from '../utils/db_models/user_model';
import { Op } from 'sequelize';

export async function deleteInactiveUsers() {
    try {
        const DAYS_INACTIVE = 30; // Supprimer après 30 jours d'inactivité
        const cutoffDate = new Date();
        cutoffDate.setDate(cutoffDate.getDate() - DAYS_INACTIVE);

        const deletedUsers = await User.destroy({
            where: {
                [Op.or]: [
                    {
                        last_seen: {
                            [Op.lt]: cutoffDate
                        }
                    },
                    {
                        last_seen: null,
                        creation_date: {
                            [Op.lt]: cutoffDate
                        }
                    }
                ]
            }
        });

        return deletedUsers;
    } catch (error) {
        console.error('❌ Erreur suppression utilisateurs:', error);
        return 0;
    }
}