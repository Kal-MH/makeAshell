/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:52:08 by mkal              #+#    #+#             */
/*   Updated: 2021/12/24 00:15:52 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_dir(t_state *s, char *path)
{
	char	*buf;
	int		ret;

	if (!ft_strncmp(path, "~", 1))
		buf = ft_strdup(find_env_val(s->env_head, "HOME"));
	else if (!ft_strncmp(path, "-", 1))
		buf = ft_strdup(find_env_val(s->env_head, "OLDPWD"));
	else
		buf = ft_strdup(path);
	if (!buf)
		exit(1);
	ret = chdir(buf);
	free(buf);
	return (ret);
}

int	ft_cd(t_state *s, t_cmd *cmd)
{
	char	pwd[999];

	(void)cmd;
	if (cmd->ac == 1)
		change_dir(s, "~");
	else if (change_dir(s, cmd->av[1]) == -1)
	{
		printf("bash: cd: %s: %s\n", cmd->av[1], strerror(errno));
		s->ret = 1;
	}
	else
	{
		getcwd(pwd, 999);
		update_env(s->env_head, "OLDPWD", find_env_val(s->env_head, "PWD"), 1);
		update_env(s->env_head, "PWD", pwd, 1);
		s->ret = 0;
	}
	return (0);
}
