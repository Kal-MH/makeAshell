/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:14:50 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:14:51 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newele;

	newlst = NULL;
	while (lst != NULL)
	{
		newele = ft_lstnew((*f)(lst->content));
		if (newele == NULL)
		{
			ft_lstclear(&newlst, (*del));
			free(newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newele);
		lst = lst->next;
	}
	return (newlst);
}
