/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:34:41 by parallel          #+#    #+#             */
/*   Updated: 2024/05/03 16:25:25 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_prinfstr(char *str)
{
	int incr;

	incr = 0;
	while (str[incr])
	 ft_printchar(str[incr++]);
	return (incr);
}

int ft_print_pointer(void *str)
{
	int			incr;
	char		buffer[20];
	uintptr_t	address;
	int			digit;

	address = (uintptr_t)str;
	incr = sizeof(uintptr_t) * 2 - 1;
	buffer[incr + 1] = '\n';
	buffer[incr + 2] = '\0';
	incr = 0;
	while (incr >= 0 && address != 0)
	{
		digit = address & 0xF;
		if ( digit < 10)
			buffer[incr++] = '0' + digit;
		else
		 buffer[incr++] = 'A' + (digit - 10);
		address >>= 4;
	}
	return (incr);
}

/*
 *prints out and return the len of printed string
 * */
int	ft_print_special(char c, va_list ptr)
{
	//"cspdiuxX%
	if (c == 'c')
		return (ft_printchar((char)va_arg(ptr, int)));
	if (c == 's')
		return (ft_prinfstr(va_arg(ptr, char *)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(ptr, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		nb_args;
	int		incr;
	char	*c_values;
	int counter;

	nb_args = get_conv_nb(str);
	counter = 0;
	c_values = (char *)malloc(nb_args);
	if (!c_values)
		return (0);
	va_start(ptr, str);
	incr = 0;
	while (*str)
	{
		if (str[incr] == '%' && in_list(str[incr + 1]))
			counter += ft_print_special(str++[incr + 1], ptr);
		else 
			counter += ft_printchar(str[incr]);
		str++;
	}
	va_end(ptr);
	return (counter);
}
