/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:49:06 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/23 14:19:23 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(char c, va_list args)
{
	else if (c == 'c')
		ft_char();
	else if (c == 's')
		ft_str();
	else if (c == 'p')
		ft_pointer();
	else if (c == 'd' || c == 'i')
		ft_int();
	else if (c == 'u')
		ft_uint();
	else if (c == 'x' || c == 'X')
		ft_hex();
	else if (c == '%')
		ft_percent();
}

