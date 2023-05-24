/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfsave.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:46:17 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/24 13:04:55 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print;

	va_start(args, *format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			// affiche un nombre decimal base 10
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int	d;
				d = va_arg(args, int);
				ft_putnbr_fd(d);
			}
			// affiche un seul caractere
			else if (format[i + 1] == 'c')
			{
				va_arg(args, int);
				ft_putchar();
			}
			// affiche une chaine de caractere
			else if (format[i + 1] == 's')
			{
				if (s == 0)
					return ("(null)");
				va_arg(args, char *);
				ft_itoa();
			}
			// affiche un nombre decimal non signe base 10
			else if (format[i + 1] == 'u')
			{
				va_arg(args, unsigned int);
			}
			// affiche un entier base 10
/*			else if (format[i + 1] == 'i')
			{
				va_arg(flag, int);
			
			}*/
			// l'argument de pointeur (void *) affiché en hexadecimal
			else if (format[i + 1] == 'p')
			{
				va_arg(args, unsigned long);
		
			}
			// affiche un nombre en hexadecimal em minuscule
			else if (format[i + 1] == 'x')
			{
				va_arg(args, unsigned int);
				if (ft_isalpha(str[i]) == 1)
					return (ft_tolower(str[i]));
			}
			// affiche un nombre en hexadecimal en majuscule
			else if (format[i + 1] == 'X')
			{
				va_arg(args, unsigned int);
				if (ft_isalpha(str[i]) == 1)
					return (ft_toupper(str[i]));
			
			}
			else if (format[i + 1] == '%')
			{
				va_arg(args, unsigned int);
				write(1,'%', 1);
			
			}
		}
		va_end(args);
	}
	return (print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:34:45 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/24 13:04:48 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*hexa(unsigned int hex, char c)
{
	char	*hexa;
	char	*result;
	int		i;
	int		ihexa;	

	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	//if (c == 'p')
		//hex = 
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
}

void	print_ptr(unsigned long ptr)
{
	uintptr_t	address;
	int			i;
	char		*result;
	int		start;
	int 	end;
	char		*hexa;
	int			ihexa;
	//int			ptr_hexa;
	char 	temp;
	//address = (uintptr_t)ptr;
	//result = hexa(address, 'c');
	hexa = "0123456789abcdef";
	result = ft_calloc(1, sizeof(char));
	i = 0;
	while (ptr > 0)
	{
		ihexa = ptr % 16;
		result[i] = hexa[ihexa];
		ptr /= 16;
		i++;
	}
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_putstr_fd(result, 1);
}

void	print_hexa(unsigned int nb, char c)
{
	/*char	*hexa;
	int		ihexa;*/
	char	*result;
	int		i;
	int		start;
	int 	end;
	//char 	temp;

	/*hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	i = 0;
	result = ft_calloc(1, sizeof(char));
	while (nb > 0)
	{
		ihexa = nb % 16;
		result[i] = hexa[ihexa];
		nb /= 16;
		i++;
	}*/
	//result[i] = '\0';
	result = hexa(nb, c);
	start = 0;
	end = ft_strlen(result) - 1;
	while (start < end)
		swap(&result[start++], &result[end--]);
	ft_putstr_fd(result, 1);
}

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
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
			else if (format[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 'u')
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
			else if (format[i] == 'p')
				print_ptr((unsigned long)va_arg(args, void *));
			else if (format[i] == 'x' || format[i] == 'X')
				print_hexa(va_arg(args, unsigned int), format[i]);
		}
	}
	va_end(args);
	return (i);
}