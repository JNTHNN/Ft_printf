/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/06/13 16:24:15 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(uintptr_t hex, char c, size_t *count)
{
	if (hex >= 16)
	{
		ft_hexa(hex / 16, c, count);
		ft_hexa(hex % 16, c, count);
	}
	else if (c == 'X')
	{
		(*count)++;
		ft_putchar("0123456789ABCDEF"[hex]);
	}
	else
	{
		(*count)++;
		ft_putchar("0123456789abcdef"[hex]);
	}
}

void	print_ptr(unsigned long long int ptr, size_t *count)
{
	if (!ptr)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	ft_hexa((uintptr_t)ptr, 'c', count);
}

void	print_hexa(unsigned int nb, char c, size_t *count)
{
	if (nb < 0)
		nb = 0;
	ft_hexa(nb, c, count);
}

int	convert(va_list args, char format, size_t count)
{
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (format == 'u')
		ft_uint(va_arg(args, unsigned int), &count);
	else if (format == 'p')
	{
		ft_putstr("0x");
		count += 2;
		print_ptr((unsigned long long int)va_arg(args, void *), &count);
	}
	else if (format == 'x' || format == 'X')
		print_hexa(va_arg(args, unsigned int), format, &count);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	size_t		count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = convert(args, format[i + 1], count);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
