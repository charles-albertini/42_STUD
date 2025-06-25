import { User } from './user_model';
import { Matches } from './matches_model';
import { UserMatch } from './user_match_model';
import { Friendship } from './friendship_model';


async function syncDatabase(maxRetries = 3, delay = 2000) {
    for (let attempt = 1; attempt <= maxRetries; attempt++) {
        try {
            await User.sync();

            await Matches.sync();
            await UserMatch.sync();
            await Friendship.sync();

			return true;
        } catch (error) {
            throw error;
        }
    }
}

export { syncDatabase };