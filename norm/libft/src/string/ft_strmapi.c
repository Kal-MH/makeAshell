/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:22:55 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:22:56 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*iterated;
	int		i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	iterated = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (iterated == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		iterated[i] = f(i, s[i]);
		i++;
	}
	iterated[i] = 0;
	return (iterated);
}
