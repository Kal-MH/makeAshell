/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:19 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:18:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_arr_realloc(char *array[], size_t size)
{
	char	**reallocated;
	int		i;

	reallocated = ft_calloc(size + 1, sizeof(*reallocated));
	if (reallocated == NULL)
		return (NULL);
	i = 0;
	while (size-- && array && array[i])
	{
		reallocated[i] = ft_strdup(array[i]);
		i++;
	}
	ft_free_str_array(&array);
	return (reallocated);
}
