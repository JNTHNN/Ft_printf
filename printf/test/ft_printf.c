/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/31 16:35:18 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
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
void	ft_putnbr(int n, size_t *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		(*count)++;
		ft_putnbr(n, count);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
		(*count)++;
	}
}
void	ft_uint(unsigned int i, size_t *count)
{
	if (i < 0)
		i = -i;
	if (i > 9)
	{
		ft_uint(i / 10, count);
		ft_uint(i % 10, count);
	}
	else
	{
		i += '0';
		write(1, &i, 1);
		(*count)++;
	}
}

int	str(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
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

	result = NULL;
	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	result = ft_calloc(0, sizeof(char));
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

int	print_ptr(unsigned long ptr)
{
	char		*result;
	int			start;
	int			end;

	result = hexa((uintptr_t)ptr, 'c');
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putchar('0');
	ft_putchar('x');
	ft_putstr_fd(result, 1);
	return (ft_strlen(result));
}

int	print_hexa(unsigned int nb, char c)
{
	char	*result;
	int		start;
	int		end;

	if (nb < 0)
		nb = 0;
	result = hexa(nb, c);
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putstr_fd(result, 1);
	return (ft_strlen(result));
}
char	ft_check(char c)
{
	if	(c == 'c' || c == 'd' || c == 'i' || c == 's' || c == '%' || c == 'u' || c == 'p' || c == 'x' || c == 'X')
		return (1);
	return(0);
}

int	convert(va_list args , char format, size_t count)
{
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (format == 'u')
		ft_uint(va_arg(args, unsigned int), &count);
	else if (format == 'p')
		count += print_ptr((unsigned long)va_arg(args, void *)) + 2;
	else if (format == 'x' || format == 'X')
		print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t		i;
	size_t		count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]) == 1)
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
