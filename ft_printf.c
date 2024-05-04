/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:34:41 by parallel          #+#    #+#             */
/*   Updated: 2024/05/04 17:13:29 by stevennk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		incr;
	int		counter;

	counter = 0;
	va_start(ptr, str);
	incr = 0;
	while (*str)
	{
		if (str[incr] == '%' && in_list(str[incr + 1]))
			counter += ft_print_special(str++[incr + 1], &ptr);
		else
			counter += ft_printchar(str[incr]);
		str++;
	}
	va_end(ptr);
	return (counter);
}
