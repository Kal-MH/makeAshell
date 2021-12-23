/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:07 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:18:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strdup for string arrays
arr: the array to copy
cpy: the copied array that gets returned
*/
char	**ft_str_arr_dup(char **arr)
{
	char	**cpy;
	int		i;

	if (arr == NULL)
		return (NULL);
	cpy = ft_calloc(ft_str_arr_len(arr) + 1, sizeof(*cpy));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		cpy[i] = ft_strdup(arr[i]);
		i++;
	}
	return (cpy);
}
