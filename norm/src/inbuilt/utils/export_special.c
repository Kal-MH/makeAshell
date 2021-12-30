/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:10:31 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:56:43 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"
#include "inbuilt_utils.h"

int	export_wd(t_env *envv, t_export *exp, char **argv)
{
	if (ft_strlen(argv[exp->j]) > ft_strlen("PWD=")
		&& ft_strncmp(argv[exp->j], "PWD=", 4) == 0)
	{
		ft_free_str(&envv->pwd);
		envv->pwd = ft_strdup(ft_strchr(argv[exp->j], '='));
		if (envv->pwd == NULL)
			return (EXIT_FAILURE);
	}
	else if (ft_strlen(argv[exp->j]) > ft_strlen("OLDPWD=")
		&& ft_strncmp(argv[exp->j], "OLDPWD=", 7) == 0)
	{
		ft_free_str(&envv->oldpwd);
		envv->oldpwd = ft_strdup(ft_strchr(argv[exp->j], '='));
		if (envv->oldpwd == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_special(t_env *envv, t_export *exp)
{
	if (envv->env_var == NULL)
		return (EXIT_FAILURE);
	if (ft_strcmp(envv->env_var[exp->i], "PWD") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->pwd, "=");
	else if (ft_strcmp(envv->env_var[exp->i], "PWD=") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->pwd, NULL);
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->oldpwd, "=");
	else if (ft_strcmp(envv->env_var[exp->i], "OLDPWD=") == 0)
		envv->env_var[exp->i] = ft_strstrjoin(envv->env_var[exp->i],
				envv->oldpwd, NULL);
	if (envv->env_var[exp->i] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
