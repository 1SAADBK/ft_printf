/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:16:15 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:31:25 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hexa(unsigned int i, int va_type)
{
	char	*hexa;
	char	c;
	int		len;

	len = 1;
	if (va_type == 6)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (i == 0)
		write (1, "0", 1);
	else if (i < 16)
	{
		c = hexa[i];
		write(1, &c, 1);
	}
	else
	{
		len += printf_hexa(i / 16, va_type);
		c = hexa[i % 16];
		write(1, &c, 1);
	}
	return (len);
}
