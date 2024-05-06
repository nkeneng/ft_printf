/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:40 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 18:59:39 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char const *str)
{
	size_t	incr;

	incr = 0;
	while (str[incr])
		incr++;
	return (incr);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_prinfstr(char *str)
{
	int	incr;

	if (str == NULL)
		return (0);
	incr = 0;
	while (str[incr])
	{
		ft_printchar(str[incr]);
		incr++;
	}
	return (incr);
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
			return (1);
		incr++;
	}
	return (0);
}
