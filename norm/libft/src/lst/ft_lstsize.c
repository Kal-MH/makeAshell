/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:17:39 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:17:39 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*c;

	if (list == NULL)
		return (0);
	i = 1;
	c = list;
	while (c->next != 0)
	{
		c = c->next;
		i++;
	}
	return (i);
}
