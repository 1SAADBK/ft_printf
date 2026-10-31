/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_integer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:16:21 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:31:36 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_unsigned_integer(unsigned int i)
{
	char	c;
	int		len;

	len = 0;
	if (i < 10)
	{
		c = i + '0';
		write (1, &c, 1);
		return (1);
	}
	else
	{
		len += printf_unsigned_integer(i / 10);
		c = (i % 10) + '0';
		write (1, &c, 1);
		len++;
		return (len);
	}
}
