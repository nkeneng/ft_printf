/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:34:41 by parallel          #+#    #+#             */
/*   Updated: 2024/05/02 21:13:24 by parallel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printchar(char c)
{
	write(1, &c, 1);
}

void	ft_printstr(const char *str)
{
	while (*str)
		ft_printchar(*(str++));
}

int	in_list(char c)
{
	char	*list;
	int		incr;

	list = "cspdiuxX%";
	incr = 0;
	while (list[incr])
	{
		if (list[incr] == c)
		{
			return (1);
		}
		incr++;
	}
	return (0);
}

/*
 * Get the number of % values to list
 *
 */
int	get_conv_nb(const char *str)
{
	int	counter;
	int	incr;

	counter = 0;
	incr = 0;
	while (str[incr])
	{
		if (str[incr] == '%' && in_list(str[incr + 1]))
		{
			counter++;
		}
		incr++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		nb_args;

	nb_args = get_conv_nb(str);
	va_start(ptr, str);
	while (nb_args--)
	{
		printf("%d\n", va_arg(ptr, int));
	}
	ft_printstr(str);
	return (0);
}
