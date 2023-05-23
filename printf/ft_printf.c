/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/23 15:47:20 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;

	va_start(args, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
			{
				int	d;
				d = va_arg(args, int);
				ft_putnbr_fd(d, 1);
			}
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
			else if (format[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 'u')
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
			//else if (format[i] == 'p')
			//	va_arg(args, void *)
			}
	}
	va_end(args);
	return (i);
}