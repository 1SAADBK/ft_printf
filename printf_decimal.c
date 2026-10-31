/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:16:11 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:31:22 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_decimal(int i)
{
	char	c;
	int		len;

	len = 0;
	if (i == -2147483648)
		return (write (1, "-2147483648", 11));
	if (i < 0)
	{
		len += write (1, "-", 1);
		i *= -1;
	}
	if (i < 10)
	{
		c = i + '0';
		return (len + write (1, &c, 1));
	}
	else
	{
		len += printf_decimal(i / 10);
		c = (i % 10) + '0';
		len += write (1, &c, 1);
	}
	return (len);
}
