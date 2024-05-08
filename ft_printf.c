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
	int		counter;

	counter = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	while (*str)
	{
		if (str[0] == '%' && in_list(str[1]))
			counter += ft_print_special(str++[1], &ptr);
		else
			counter += ft_printchar(str[0]);
		str++;
	}
	va_end(ptr);
	return (counter);
}
