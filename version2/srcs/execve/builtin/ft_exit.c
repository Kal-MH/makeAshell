/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:39:54 by napark            #+#    #+#             */
/*   Updated: 2021/12/24 00:58:57 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_num_str(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	exit_not_num(t_cmd *cmd)
{
	printf("exit\n");
	printf("bash: exit: %s: numeric argument required\n", cmd->av[1]);
	exit(255);
}

void	ft_exit(t_state *state, t_cmd *cmd)
{
	int	ret;

	if (cmd->ac == 1)
	{
		printf("exit\n");
		exit(state->ret);
	}
	else if (cmd->ac == 2)
	{
		if (is_num_str(cmd->av[1]))
		{
			ret = ft_atoi(cmd->av[1]);
			printf("exit\n");
			exit(ret);
		}
		else
			exit_not_num(cmd);
	}
	else
	{
		printf("bash: exit: too many arguments\n");
		state->ret = 1;
	}
}
