import { DataTypes, Model } from 'sequelize';
import { sequelize } from '../def'
import { DefaultAvatar } from '../default';

class User extends Model {
	user_id!: number
	username!: string
	email_adress?: string
	hashed_password!: string
	number_of_matches!: number
	number_of_win!: number
	number_of_lose!: number
	creation_date!: Date
	last_update!: Date
	avatar!: string
	twoFA!: boolean
	twoFA_secret?: string
	google_user!: boolean
	last_seen!: Date
	is_online!: boolean 
}

User.init({
	user_id: {
		type: DataTypes.INTEGER,
		autoIncrement: true,
		primaryKey: true
	},
	username: {
		type: DataTypes.STRING(20),
		allowNull: false,
		unique: true,
		validate: {
			len: [3, 20]
		}
	},
	email_adress: {
		type: DataTypes.STRING(255),
		allowNull: true,
		unique: true,
		validate: {
			isEmail: true
		}
	},
	hashed_password: {
		type: DataTypes.STRING(255),
		allowNull: false,
		validate: {
			len: [6, 255]
		}
	},
	number_of_matches: {
		type: DataTypes.INTEGER,
		allowNull: false,
		defaultValue: 0,
		validate: {
			min: 0
		}
	},
	number_of_win: {
		type: DataTypes.INTEGER,
		allowNull: false,
		defaultValue: 0,
		validate: {
			min: 0
		}
	},
	number_of_lose: {
		type: DataTypes.INTEGER,
		allowNull: false,
		defaultValue: 0,
		validate: {
			min: 0
		}
	},
	creation_date: {
		type: DataTypes.DATEONLY,
		allowNull: false,
		defaultValue: DataTypes.NOW
	},
	last_update: {
		type: DataTypes.DATEONLY,
		allowNull: false,
		defaultValue: DataTypes.NOW,
	},
	avatar: {
		type: DataTypes.TEXT('medium'),
		allowNull: false,
		defaultValue: DefaultAvatar
	},
	twoFA: {
		type: DataTypes.BOOLEAN,
		allowNull: false,
		defaultValue: false
	},
	twoFA_secret: {
		type: DataTypes.STRING(255),
		allowNull: true,
		defaultValue: null
	},
	google_user : {
		type: DataTypes.BOOLEAN,
		allowNull: false,
		defaultValue: false
	},
	last_seen: {
		type: DataTypes.DATE,
		allowNull: false,
		defaultValue: DataTypes.NOW
	},
	is_online: {
		type: DataTypes.BOOLEAN,
		allowNull: false,
		defaultValue: false
	}
}, {
	sequelize,
	modelName: 'User',
	tableName: 'user',
	timestamps: false
})

User.addHook('beforeUpdate', (user: User) => {
	user.last_update = new Date();
});

User.addHook('beforeCreate', (user: any) => {
    user.creation_date = new Date();
    user.last_update = new Date();
    if (!user.avatar) {
        user.avatar = DefaultAvatar;
    }
});

User.addHook('beforeSave', (user: User) => {
    user.last_seen = new Date();
    user.is_online =  true;
});

export { User }