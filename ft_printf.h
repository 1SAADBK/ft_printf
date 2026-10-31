/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:35:00 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/12 11:30:55 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	printf_char(va_list args);
int	printf_decimal(int i);
int	printf_hexa(unsigned int i, int va_type);
int	printf_pointer(unsigned long long ul);
int	printf_str(va_list args);
int	printf_unsigned_integer(unsigned int i);

#endif