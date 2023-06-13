/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:57:42 by jgasparo          #+#    #+#             */
/*   Updated: 2023/06/13 16:04:54 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		s = "(null)";
	while (s[++i])
		ft_putchar(s[i]);
	return (ft_strlen(s));
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
