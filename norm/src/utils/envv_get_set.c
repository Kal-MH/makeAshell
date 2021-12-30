/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_get_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:52:52 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:57:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

static t_env	*_get_envv(t_env *envv)
{
	static t_env	*static_envv = NULL;

	if (envv == NULL)
		return (static_envv);
	static_envv = envv;
	return (static_envv);
}

void	set_envv(t_env *envv)
{
	_get_envv(envv);
}

t_env	*get_envv(void)
{
	return (_get_envv(NULL));
}

char	**get_env_var(void)
{
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL)
		return (NULL);
	return (envv->env_var);
}
