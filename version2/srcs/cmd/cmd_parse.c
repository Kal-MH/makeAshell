/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:42:16 by mkal              #+#    #+#             */
/*   Updated: 2021/12/28 15:48:48 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd(t_state *state, int ac)
{
	t_token	*token;
	t_token	*start;
	int		type;

	token = state->token_head;
	start = state->token_head;
	type = NORMAL_TYPE;
	while (token)
	{
		ac++;
		if (token->type >= PIPE || !token->next)
		{
			if (token->type == SPACE || token->type >= PIPE)
				ac--;
			make_cmd(start, ac, type, 0);
			if (token->type >= PIPE)
				type = token->type;
			ac = 0;
			start = token->next;
		}
		else if (token->type == SPACE)
			ac--;
		token = token->next;
	}
}

void	make_cmd(t_token *start, int ac, int type, int i)
{
	char	**av;
	char	*tmp;

	av = make_empty_av(ac);
	while (start && i < ac && start->type != PIPE && start->type != SEMICOLON)
	{
		if (start->type == SPACE)
			jump_space(av[i], &i);
		else
		{
			make_cmd_condition(start, av, &i);
			if (i < ac)
			{
				tmp = ft_strjoin2(av[i], start->str);
				free(av[i]);
				av[i] = tmp;
			}
		}
		start = start->next;
	}
	add_cmd_back(&g_state.cmd_head, av, type);
}

char	**make_empty_av(int ac)
{
	int		i;
	char	**av;

	i = 0;
	if (!ft_calloc(ac + 1, sizeof(char *), (void **)&av))
		exit(1);
	while (i < ac)
		av[i++] = 0;
	return (av);
}

void	add_cmd_back(t_cmd **head, char **av, int type)
{
	t_cmd	*cmd;
	int		ac;

	ac = 0;
	while (av[ac])
		ac++;
	if (*head == NULL)
		*head = create_cmd(av, ac, type, 0);
	else
	{
		cmd = *head;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = create_cmd(av, ac, type, cmd);
	}
}

t_cmd	*create_cmd(char **av, int ac, int type, t_cmd *prev)
{
	t_cmd	*cmd;

	if (av == NULL)
		return (NULL);
	if (!ft_calloc(1, sizeof(t_cmd), (void *)&cmd))
		exit(1);
	cmd->av = av;
	cmd->ac = ac;
	cmd->type = type;
	cmd->next = 0;
	cmd->prev = prev;
	return (cmd);
}
