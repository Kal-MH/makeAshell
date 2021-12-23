/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:19:53 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:19:54 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	char	*duped;
	int		i;
	size_t	duped_len;

	duped_len = n;
	i = 0;
	duped = malloc((duped_len + 1) * sizeof(*duped));
	if (duped == NULL)
		return (NULL);
	while (n--)
	{
		duped[i] = str[i];
		i++;
	}
	duped[i] = '\0';
	return (duped);
}
