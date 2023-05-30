/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:08 by jgasparo          #+#    #+#             */
/*   Updated: 2023/05/24 15:29:28 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*cb;
	unsigned char	uc;

	uc = (unsigned char) c;
	cb = b;
	i = 0;
	while (len > i)
	{
		cb[i] = uc;
		i++;
	}
	return (b);
}
