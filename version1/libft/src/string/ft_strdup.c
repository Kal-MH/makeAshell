/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:46 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:18:47 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duped;
	int		duped_len;

	duped_len = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	duped = malloc((duped_len + 1) * sizeof(*duped));
	if (duped == NULL)
		return (NULL);
	while (str && *str)
		*duped++ = *str++;
	*duped = '\0';
	return (duped - duped_len);
}
