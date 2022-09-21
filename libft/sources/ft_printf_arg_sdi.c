/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_sdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/21 23:53:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_arg_sdi(const char *format, int len, va_list arg)
{
	char		*s;
	long int	i;

	if (*format == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			s = "(null)";
		write(1, s, ft_strlen(s));
		len = len + ft_strlen(s);
	}
	else if (*format == 'd' || *format == 'i')
	{
		i = va_arg(arg, int);
		if (i < 0)
		{
			write (1, "-", 1);
			len++;
			i *= -1;
		}
		ft_putbase(i, DECA);
		len += ft_countdigits(i, 10);
	}
	return (len);
}
