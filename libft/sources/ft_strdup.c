/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:21:34 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:30:00 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*clone;
	size_t	len;

	len = ft_strlen(s);
	clone = (char *)malloc(sizeof(char) * (len + 1));
	if (!clone)
		return (NULL);
	clone[len] = 0;
	ft_memcpy(clone, s, len);
	return (clone);
}
