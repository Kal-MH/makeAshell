/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:12:35 by napark            #+#    #+#             */
/*   Updated: 2021/12/18 01:40:33 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

static int	print_meg_env(char *str_arg, char *meg, int ret)
{
	ft_putstr_fd("env: ", STDERR_FILENO);
	ft_putstr_fd(str_arg, STDERR_FILENO);
	ft_putstr_fd(meg, STDERR_FILENO);
	return (ret);
}

int	env(char **argv)
{
	int		i;
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL || envv->env_var == NULL)
		return (EXIT_FAILURE);
	if (argv != NULL && argv[1] != NULL)
	{
		if (access(argv[1], F_OK) == 0)
		{
			return (print_meg_env(argv[1], ": Permission denied\n", 126));
		}
		return (print_meg_env(argv[1], ": No such file or directory\n", 127));
	}
	i = 0;
	while (envv->env_var && envv->env_var[i] != NULL)
	{
		if (ft_printf("%s\n", envv->env_var[i++]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
