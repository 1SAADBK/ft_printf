/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenkass <sbenkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:15:43 by sbenkass          #+#    #+#             */
/*   Updated: 2026/01/15 11:12:19 by sbenkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isformat(char c)
{
	char	*str;
	int		va_type;
	int		i;

	i = 0;
	(void)va_type;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == c)
		{
			va_type = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_putpercent(void)
{
	write (1, "%", 1);
	return (1);
}

static int	printvariable(va_list args, int va_type)
{
	int					len;
	unsigned long long	ul;

	if (va_type == 0)
		len = printf_char(args);
	else if (va_type == 1)
		len = printf_str(args);
	else if (va_type == 2)
	{
		ul = va_arg(args, unsigned long long);
		write (1, "0x", 2);
		len = 2 + printf_pointer(ul);
	}
	else if (va_type == 3 || va_type == 4)
		len = printf_decimal(va_arg(args, int));
	else if (va_type == 5)
		len = printf_unsigned_integer(va_arg(args, unsigned int));
	else if (va_type == 6 || va_type == 7)
		len = printf_hexa(va_arg(args, unsigned int), va_type);
	else if (va_type == 8)
		return (ft_putpercent());
	else
		return (0);
	return (len);
}

static int	variable_type(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		va_type;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && isformat(str[i + 1]))
		{
			va_type = variable_type(str[i + 1]);
			len += printvariable(args, va_type);
			i++;
		}
		else if (str[i] != '%')
		{
			write (1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}
