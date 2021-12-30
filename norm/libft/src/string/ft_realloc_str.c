/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:20:56 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:20:57 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char *str, int size)
{
	char	*new;
	int		i;

	if (str == NULL)
		return (NULL);
	new = ft_calloc(size + 1, sizeof(*new));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str && str[i] && size--)
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}
