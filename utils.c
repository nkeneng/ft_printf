/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:40 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 11:56:08 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char const *str)
{
	size_t	incr;

	incr = 0;
	while (str[incr])
		incr++;
	return (incr);
}
