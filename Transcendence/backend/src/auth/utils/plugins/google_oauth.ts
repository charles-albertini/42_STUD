import fp from 'fastify-plugin';

export default fp(async function googleOAuth(fastify: any) {
    await fastify.register(require('@fastify/oauth2'), {
        name: 'googleOAuth2',
        credentials: {
            client: {
                id: process.env.GOOGLE_CLIENT_ID as string,
                secret: process.env.GOOGLE_CLIENT_SECRET as string,
            },
            auth: {
                authorizeHost: 'https://accounts.google.com',
                authorizePath: '/o/oauth2/v2/auth',
                tokenHost: 'https://oauth2.googleapis.com',
                tokenPath: '/token'
            }
        },
        startRedirectPath: '/google',
        callbackUri: process.env.GOOGLE_REDIRECT_URI as string,
        scope: ['openid', 'profile', 'email']
    });
    
    // Google OAuth plugin configured
});