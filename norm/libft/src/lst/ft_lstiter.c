/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:14:35 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:14:38 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*c;

	if (lst == NULL || f == NULL)
		return ;
	c = lst;
	while (c != NULL)
	{
		(*f)(c->content);
		c = c->next;
	}
}
