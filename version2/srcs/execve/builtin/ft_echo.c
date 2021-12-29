/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:42:21 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:40:03 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_echo_flag(char **av, int *i, int *flag)
{
	int	j;

	*i = 1;
	while (av[*i] && av[*i][0] == '-' && av[*i][1] == 'n')
	{
		j = 2;
		while (av[*i][j] && av[*i][j] == 'n')
			j++;
		if (av[*i][j] == 0)
		{
			*flag = 1;
			(*i)++;
		}
		else
			break ;
	}
}

static int	has_escape_character(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i + 1] && (cmd[i] == '\\' && cmd[i + 1] == 'n'))
			return (1);
		if (cmd[i + 1] && (cmd[i] == '\\' && cmd[i + 1] == 't'))
			return (1);
		i++;
	}
	return (0);
}

static void	handle_escape(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i + 1] && (cmd[i] == '\\' && cmd[i + 1] == 'n'))
		{
			write(1, "\n", 1);
			i++;
		}
		else if (cmd[i + 1] && (cmd[i] == '\\' && cmd[i + 1] == 't'))
		{
			write(1, "\t", 1);
			i++;
		}
		else
			write(1, &cmd[i], 1);
		i++;
	}
}

void	ft_echo(t_state *s, t_cmd *cmd)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	check_echo_flag(cmd->av, &i, &flag);
	while (i < cmd->ac)
	{
		if (has_escape_character(cmd->av[i]))
			handle_escape(cmd->av[i]);
		else
			write(1, cmd->av[i], ft_strlen(cmd->av[i]));
		if (i < cmd->ac - 1 && ft_strlen(cmd->av[i]))
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	s->ret = 0;
}
