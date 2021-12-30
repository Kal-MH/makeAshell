/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_front_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:19:49 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:19:53 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
