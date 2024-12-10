/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:34:44 by jgasparo          #+#    #+#             */
/*   Updated: 2023/06/13 16:05:22 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define    FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
void	ft_putnbr(int n, size_t *count);
void	ft_uint(unsigned int i, size_t *count);
int		ft_count(int n);

#endif