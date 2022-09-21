/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:08:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:29:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	if (c > 255)
		return ((void *)s);
	aux = (char *)s;
	while (*aux)
	{
		if (*aux == c)
			return (aux);
		aux++;
	}
	if (*aux == c)
		return (aux);
	return (NULL);
}
