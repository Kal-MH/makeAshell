/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_Get_Set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:37:50 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:00:30 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "parser_utils.h"

static t_iter	*_get_iter(t_iter *iter, bool reset)
{
	static t_iter	*static_iter = NULL;

	if (iter == NULL && !reset)
		return (static_iter);
	if (reset)
	{
		static_iter = NULL;
		return (NULL);
	}
	static_iter = iter;
	return (static_iter);
}

t_iter	*get_iter(void)
{
	return (_get_iter(NULL, false));
}

void	set_iter(t_iter *iter)
{
	_get_iter(iter, false);
}

void	reset_iter(void)
{
	_get_iter(NULL, true);
}
