/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfsave.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:46:17 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/22 14:19:54 by jgasparo         ###   ########.fr       */
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