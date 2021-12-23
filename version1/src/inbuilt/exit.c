/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:13:29 by napark            #+#    #+#             */
/*   Updated: 2021/12/15 00:35:53 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_exit_arg(char *args[])
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	exit_inbuilt(char *args[])
{
	int	exit_code;

	if (ft_strncmp(*args, "exit", ft_strlen(*args)) != 0)
		return (EXIT_FAILURE);
	args++;
	exit_code = ft_atoi(*args);
	if (!is_valid_exit_arg(args))
	{
		ft_putstr_fd("exit: not a valid argument\n", STDERR_FILENO);
		exit_code = 255;
	}
	if (*(++args))
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		printf("exit\n");
		return (EXIT_FAILURE);
	}
	printf("exit\n");
	exit(exit_code);
	return (exit_code);
}
