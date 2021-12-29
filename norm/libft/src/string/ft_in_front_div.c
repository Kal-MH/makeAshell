/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_front_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:42 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:16:43 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
this will add src infront of dst divided by div
dst will be free'd
returns NULL if dst == NULL or src == NULL or if error
*/
char	*ft_in_front_div(char **dst, char *src, char *div)
{
	char	*out;

	out = ft_strdup(src);
	if (out == NULL)
		return (NULL);
	out = ft_append(&out, div);
	if (out == NULL)
		return (NULL);
	out = ft_append(&out, *dst);
	if (out == NULL)
		return (NULL);
	ft_free_str(dst);
	return (out);
}
