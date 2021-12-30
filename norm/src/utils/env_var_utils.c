/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:18:25 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:57:23 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

static void	get_env_var_value_utils(t_env *envv, char *var, char **value, int i)
{
	if (ft_strlen(*value) == 0 && ft_strcmp(var, "PWD") == 0)
	{
		if (ft_strlen(envv->pwd) == 0)
			*value = ft_calloc(1, sizeof (char));
		else
			*value = ft_strdup(envv->pwd);
	}
	else if (ft_strlen(*value) == 0 && ft_strcmp(var, "OLDPWD") == 0)
	{
		if (ft_strlen(envv->oldpwd) == 0)
			*value = ft_calloc(1, sizeof (char));
		else
			*value = ft_strdup(envv->oldpwd);
	}
	else if (envv->env_var[i] == NULL && *value == NULL)
		*value = ft_calloc(1, sizeof(char));
}

char	*get_env_var_value(t_env *envv, char *var)
{
	int		i;
	char	*value;

	value = NULL;
	i = 0;
	while (envv && envv->env_var && envv->env_var[i] != NULL)
	{
		if (ft_strcmp(var, envv->env_var[i]) == -61)
		{
			value = ft_strchr(envv->env_var[i++], '=') + 1;
			if (ft_strlen(value) == 0)
				value = ft_calloc(1, sizeof (char));
			else
				value = ft_strdup(value);
			break ;
		}
		else if (ft_strcmp(var, envv->env_var[i++]) == 0)
		{
			value = ft_calloc(1, sizeof (char));
			break ;
		}
	}
	get_env_var_value_utils(envv, var, &value, i);
	return (value);
}

t_env	*init_envv(char **envp)
{
	t_env	*envv;

	envv = ft_calloc(1, sizeof(t_env));
	if (envv != NULL && envp != NULL && *envp != NULL)
	{
		envv->envp = envp;
		envv->env_var = ft_str_arr_dup(envp);
		envv->pwd = get_env_var_value(envv, "PWD");
		envv->oldpwd = get_env_var_value(envv, "OLDPWD");
		if (envv->env_var != NULL && envv->pwd != NULL && envv->oldpwd != NULL)
			return (envv);
	}
	return (NULL);
}

void	free_envv(t_env *envv)
{
	envv->envp = NULL;
	ft_free_str_array(&envv->env_var);
	ft_free_str(&envv->pwd);
	ft_free_str(&envv->oldpwd);
	free(envv);
}

int	reinit_env_var(t_env *envv, char **argv)
{
	if (*envv->env_var == NULL)
	{
		envv->env_var = ft_realloc_str_arr(envv->env_var, 2);
		if (envv->env_var == NULL)
			return (EXIT_FAILURE);
		envv->env_var[0] = ft_strdup(argv[1]);
		if (envv->env_var[0] == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
