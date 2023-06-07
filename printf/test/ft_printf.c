/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/06/07 17:34:55 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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
/*
char	*hexa(uintptr_t hex, char c)
{
	char	*hexa;
	char	*result;
	int		i;
	int		ihexa;	

	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	result = (char *)malloc(17 * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (hex > 0)
	{
		ihexa = hex % 16;
		result[i] = hexa[ihexa];
		hex /= 16;
		i++;
		ft_putchar(result[i]);
	}
	result[i] = '\0';
	return (result);
	ft_strlen(result);
	//free (result);
}*/

/*
void	ft_hexa(uintptr_t hex, char c, size_t *count)
{
	char	*hexa;
	int		ihexa;

	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (hex >= 16)
	{
		ft_hexa(hex / 16, c, count);
		ihexa = hex % 16;
		ft_putchar(hexa[ihexa]);
		(*count)++;
	}
	else
		ft_putchar(hexa[hex]);
}
*/

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
	//char	*prefix;

	if (!ptr)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	//prefix = "0x";
	//ft_putstr_fd(prefix, 1);
	ft_hexa((uintptr_t)ptr, 'c', count);
}

void	print_hexa(unsigned int nb, char c, size_t *count)
{
	if (nb < 0)
		nb = 0;
	ft_hexa(nb, c, count);
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
	{
		ft_putstr_fd("0x", 1);
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
		if (format[i] == '%' && ft_check(format[i]) == 1)
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
