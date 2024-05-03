/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:34:41 by parallel          #+#    #+#             */
/*   Updated: 2024/05/03 17:13:32 by snkeneng         ###   ########.fr       */
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

int	ft_print_pointer(void *str)
{
	long long	nbr;
	int			incr;

	nbr = (long long)str;
	incr = 0;
	ft_printf("0x");
	print_base(nbr, "0123456789abcdef", 16, &incr);
	return (incr + 2);
}

int	ft_print_decimal(int nb)
{
	int	incr;

	incr = 0;
	ft_putnbr(nb, &incr);
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
	if (c == 'd')
		return (ft_print_decimal(va_arg(ptr, int)));
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
