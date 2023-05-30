/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/30 15:37:58 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uint(unsigned int i)
{
	if (i < 0)
		i = -i;
	if (i > 9)
	{
		ft_uint(i / 10);
		ft_uint(i % 10);
	}
	else
		ft_putchar_fd(i + '0', 1);
}

void	str(char *s)
{
	if (!s)
		s = "(null)";
	ft_strlen(s);
	ft_putstr_fd(s, 1);
}

int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*hexa(uintptr_t hex, char c)
{
	char	*hexa;
	char	*result;
	int		i;
	int		ihexa;	

	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	result = ft_calloc(1, sizeof(char));
	i = 0;
	while (hex > 0)
	{
		ihexa = hex % 16;
		result[i] = hexa[ihexa];
		hex /= 16;
		i++;
	}
	result[i] = '\0';
	return (result);
	ft_strlen(result);
}

void	print_ptr(unsigned long ptr)
{
	char		*result;
	int			start;
	int			end;

	result = hexa((uintptr_t)ptr, 'c');
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_putstr_fd(result, 1);
	ft_strlen(result);
}

void	print_hexa(unsigned int nb, char c)
{
	char	*result;
	int		start;
	int		end;

	if (!nb)
		nb = 0;
	result = hexa(nb, c);
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putstr_fd(result, 1);
	ft_strlen(result);
}

void	convert(va_list args , char format)
{
	//int	count;

	//count = 0;
	if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);	
	else if (format == 's')
		str(va_arg(args, char *));
	else if (format == '%')
		ft_putchar_fd('%', 1);
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		//count++;
	}
	else if (format == 'u')
		ft_uint(va_arg(args, unsigned int));
	else if (format == 'p')
		print_ptr((unsigned long)va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		print_hexa(va_arg(args, unsigned int), format);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		if (format[i] == '%')
		{
			i++;
			count += convert(args, format[i]);
		}
	}
	va_end(args);
	return (i);
}
