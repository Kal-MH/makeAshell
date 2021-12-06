/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:08:30 by napark            #+#    #+#             */
/*   Updated: 2021/12/04 13:11:13 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_data(t_cmd *cmd, t_list *l_env)
{
    cmd->p_type = -1;
    cmd->quote = 0;
    cmd->word = NULL;
    cmd->environ = l_env;//환경변수 환경변수 길이
    cmd->cmd_num = 0;
    cmd->pid = -1;
    cmd->next = NULL;
    cmd->prev = NULL;
    if (find_env("PATH", cmd->environ) != NULL)
        cmd->path = ft_split(find_env_value("PATH", cmd->environ), ':');
    else
        cmd->path = ft_split("", ':');
}

t_list  *pre_process(char **envp)
{
    int     i;
    t_list  *new;

    i = 0;
    new = ft_lstnew(ft_strdup(envp[0]));
    while (envp[++i])
        ft_lstadd_back(&new, ft_lstnew(ft_strdup(envp[i])));
    set_signal();
    return (new);
}
