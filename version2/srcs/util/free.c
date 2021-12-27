/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:43:24 by napark            #+#    #+#             */
/*   Updated: 2021/12/27 14:00:09 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2d(char **array)
{
	char	**temp;
	int		i;

	temp = array;
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	free_token(t_token *token)
{
	t_token	*tmp;
	t_token	*next;

	tmp = token;
	while (tmp)
	{
		if (tmp->str)
			free(tmp->str);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
