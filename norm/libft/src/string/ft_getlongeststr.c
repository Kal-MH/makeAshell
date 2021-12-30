/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlongeststr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:19:36 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:19:40 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getlongeststr(char **array)
{
	int		max_len;
	int		tmp_len;
	char	*longest_str;

	if (array == NULL)
		return (NULL);
	max_len = ft_strlen(*array);
	longest_str = *array;
	array++;
	while (array && *array)
	{
		tmp_len = ft_strlen(*array);
		if (tmp_len > max_len)
		{
			max_len = tmp_len;
			longest_str = *array;
		}
		array++;
	}
	return (longest_str);
}
