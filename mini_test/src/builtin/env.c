/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:46:07 by axburin-          #+#    #+#             */
/*   Updated: 2025/02/20 16:42:10 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_env *envp)
{
	t_env *env = envp;
	while(env)
	{
		printf("%s\n", env->value);
		env = env->next;
	}
	return(0);
}

//marche pas
