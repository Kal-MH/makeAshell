/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:17:36 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:12:22 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_single(t_cmd *cmd)
{
	int	single_i;
	char	*buf;
	char	*tmp;
	int	i;

	i = 0;
	while(cmd->av[i])
	{	
		while (1)
		{
			single_i = ft_strhas(cmd->av[i], ";|");
			if (single_i < 0)
				break ;
			buf = ft_substr(cmd->av[i], 0, single_i);
			tmp = ft_substr(cmd->av[i], single_i + 2, ft_strlen(cmd->av[i]));
			free(cmd->av[i]);
			cmd->av[i] = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
		}
		i++;
	}
}
void	remove_single_one_line(char **cmd)
{
	int	single_i;
	char	*buf;
	char	*tmp;

	while(1)
	{	
		single_i = ft_strhas(*cmd, ";|");
		if (single_i < 0)
			break ;
		buf = ft_substr(*cmd, 0, single_i);
		tmp = ft_substr(*cmd, single_i + 2, ft_strlen(*cmd));
		free(*cmd);
		*cmd = ft_strjoin(buf, tmp);
		free(buf);
		free(tmp);
	}
}

void	remove_back(t_cmd *cmd)
{
	int	single_i;
	char	*buf;
	char	*tmp;
	int	i;

	i = 0;
	while(cmd->av[i])
	{	
		while (1)
		{
			single_i = ft_strchr_index(cmd->av[i], '\\');
			if (single_i < 0)
				break ;
			buf = ft_substr(cmd->av[i], 0, single_i);
			tmp = ft_substr(cmd->av[i], single_i + 1, ft_strlen(cmd->av[i]));
			free(cmd->av[i]);
			cmd->av[i] = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
		}
		i++;
	}
}

void	remove_back_one_line(char **cmd)
{
	char	*buf;
	char	*tmp;
	int	i;

	i = 0;
	while (*cmd[i])
	{
		if (*cmd[i] == '\\')
		{
			buf = ft_substr(*cmd, 0, i);
			tmp = ft_substr(*cmd, i + 1, ft_strlen(*cmd));
			free(*cmd);
			*cmd = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
		}
		i++;
	}
}
	/*
	i = 0;
	while(cmd->av[i])
	{
		j = 0;
		while (cmd->av[i][j])
		{
			if (cmd->av[i][j] == '\\'
					&& (cmd->av[i][j + 1]
						&& ((cmd->av[i][j + 1] != 'n' || cmd->av[i][j + 1] != 't'))))
			{
				buf = ft_substr(cmd->av[i], 0, j);
				tmp = ft_substr(cmd->av[i], j + 1, ft_strlen(cmd->av[i]));
				free(cmd->av[i]);
				cmd->av[i] = ft_strjoin(buf, tmp);
				free(buf);
				free(tmp);
			}
			j++;
		}
		i++;
	}*/
		/*while (1)
		{
			single_i = ft_strchr_index(cmd->av[i], '\\');
			if (single_i < 0)
				break ;
			buf = ft_substr(cmd->av[i], 0, single_i);
			tmp = ft_substr(cmd->av[i], single_i + 1, ft_strlen(cmd->av[i]));
			free(cmd->av[i]);
			cmd->av[i] = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
		}
		i++;
	}*/
//}

void	remove_character(t_cmd *cmd)
{
	int	i;

	remove_single_one_line(&cmd->av[0]);
	if (!ft_strcmp(cmd->av[0], "echo"))
	{
		//redirection 확
		i = 1;
		while (cmd->av[i])
		{
			if(!ft_strcmp(cmd->av[i], ">") || !ft_strcmp(cmd->av[i], "<")
					|| !ft_strcmp(cmd->av[i], ">>") || !ft_strcmp(cmd->av[i], "<<"))
				remove_single_one_line(&cmd->av[i + 1]);
			i++;
		}
		//single 제거
		return ;
	}
	remove_single(cmd);
	remove_back(cmd);
	if (!ft_strcmp(cmd->av[0], "export") || !ft_strcmp(cmd->av[0], "unset"))
		return;
	check_cmd_dollar_sign(cmd);
	//remove_single(cmd);
	//remove_back(cmd);
}
