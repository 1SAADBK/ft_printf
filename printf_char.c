/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:16:08 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:31:16 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}
