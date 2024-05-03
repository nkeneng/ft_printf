/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:58:45 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 18:53:05 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_unsigned_decimal(unsigned int nb)
{
	int	incr;

	incr = 0;
	ft_putnbr_unsigned(nb, &incr);
	return (incr);
}

int	ft_print_hex(int nb, int _case)
{
	int	incr;

	incr = 0;
	if (_case == 1)
	{
		ft_prinfstr("0x");
		print_base((long long)nb, "0123456789abcdef", 16, &incr);
	}
	else
	{
		ft_prinfstr("0X");
		print_base((long long)nb, "0123456789ABCDEF", 16, &incr);
	}
	return (incr + 2);
}

/*
 *prints out and return the len of printed string
 * */
int	ft_print_special(char c, va_list ptr)
{
	if (c == 'c')
		return (ft_printchar((char)va_arg(ptr, int)));
	if (c == 's')
		return (ft_prinfstr(va_arg(ptr, char *)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(ptr, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(ptr, int)));
	if (c == 'u')
		return (ft_print_unsigned_decimal(va_arg(ptr, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(ptr, int), 1));
	if (c == 'X')
		return (ft_print_hex(va_arg(ptr, int), 2));
	if (c == '%')
		return (ft_printchar('%'));
	return (0);
}