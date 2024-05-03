/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:38:51 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 14:27:47 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

size_t	get_index(char c)
{
	char		*list;
	size_t		incr;

	list = "cspdiuxX%";
	incr = 0;
	while (incr < ft_strlen(list))
	{
		if (list[incr] == c)
			return (incr);
	}
	return (-1);
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

void	fill_cvalues(const char *str, char *res)
{
	int	counter;
	int	incr;

	counter = 0;
	incr = 0;
	while (str[incr])
	{
		if (str[incr] == '%' && in_list(str[incr + 1]))
			res[counter++] = str[incr + 1];
		incr++;
	}
}
