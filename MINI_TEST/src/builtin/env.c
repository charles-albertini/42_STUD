/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:46:07 by axburin-          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:45 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_env *envp)
{
	while(envp)
	{
		printf("%s\n", envp->value);
		envp = envp->next;
	}
	return(0);
}

//marche pas
