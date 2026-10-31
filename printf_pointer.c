/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:16:18 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:31:29 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_pointer(unsigned long long ul)
{
	int				i;
	char			*hexa;
	int				len;

	len = 0;
	hexa = "0123456789abcdef";
	i = 0;
	if (ul == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (ul < 16)
	{
		write (1, &hexa[ul], 1);
		return (1);
	}
	else
	{
		len += printf_pointer(ul / 16);
		write (1, &hexa[ul % 16], 1);
		len++;
	}
	return (len);
}
