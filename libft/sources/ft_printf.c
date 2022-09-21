/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:08:51 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/21 23:53:39 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			len++;
		}
		else
		{
			format++;
			len = ft_validation(format, len, arg);
			format++;
		}
	}
	va_end(arg);
	return (len);
}
