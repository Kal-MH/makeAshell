/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:17:48 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:17:51 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char **old, char **new)
{
	char	*tmp;

	tmp = *old;
	*old = *new;
	*new = tmp;
}

char	**ft_sort_str_arr(char *unsorted[])
{
	int		unsorted_len;
	int		i;
	int		j;

	if (unsorted == NULL)
		return (NULL);
	unsorted_len = ft_str_arr_len(unsorted);
	i = 0;
	while (i < unsorted_len)
	{
		j = 0;
		while (j < (unsorted_len - 1 - i))
		{
			if (ft_strcmp(unsorted[j], unsorted[j + 1]) > 0)
				swap(&unsorted[j], &unsorted[j + 1]);
			j++;
		}
		i++;
	}
	return (unsorted);
}
