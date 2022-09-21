/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:45:27 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:22:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	i = 0;
	aux = (unsigned char *)s;
	while (i < n)
	{
		if (*aux == (unsigned char)c)
			return (aux);
		i++;
		aux++;
	}
	return (NULL);
}
