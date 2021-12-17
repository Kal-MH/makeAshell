/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_single_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:15:56 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:15:57 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
add new after (*arr)[pos]
*/
char	**ft_add_single_str(char ***arr, int pos, char *new)
{
	int		i;

	pos++;
	if (new == NULL)
	{
		ft_free_str_array(arr);
		return (NULL);
	}
	*arr = ft_realloc_str_arr(*arr, ft_str_arr_len(*arr) + 1);
	if (*arr == NULL)
		return (NULL);
	i = ft_str_arr_len(*arr);
	while (i > pos)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[i] = ft_strdup(new);
	if ((*arr)[i] == NULL)
	{
		ft_free_str_array(arr);
		return (NULL);
	}
	return (*arr);
}
