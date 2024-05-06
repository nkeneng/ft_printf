/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:53:06 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 18:52:34 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_base(long nb, char *base, int base_len, int *counter)
{
	long	nb_long;

	nb_long = (long)nb;
	*counter = *counter + 1;
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long *= -1;
	}
	if (nb_long >= base_len)
	{
		print_base(nb_long / base_len, base, base_len, counter);
		nb_long = nb_long % base_len;
	}
	write(1, &base[nb_long], 1);
}

void	ft_putnbr_unsigned(unsigned int nb, int *incr)
{
	char	c;

	*incr = *incr + 1;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, incr);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int *incr)
{
	char	c;

	*incr = *incr + 1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, incr);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
}
