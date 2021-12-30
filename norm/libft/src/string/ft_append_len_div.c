/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_len_div.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:18:49 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:18:54 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_len_div(char **dst, char *src, int len, char *div)
{
	int		i;
	int		j;
	char	*out;

	j = 0;
	if (*dst == NULL || src == NULL || ft_strlen(src) < len)
		return (NULL);
	out = ft_append(dst, div);
	if (out == NULL)
		return (NULL);
	i = ft_strlen(out);
	out = ft_realloc_str(out, i + len + 1);
	while (src[j] && j < len)
	{
		out[i] = src[j];
		i++;
		j++;
	}
	ft_free_str(dst);
	return (out);
}
