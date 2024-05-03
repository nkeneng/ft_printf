/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:53:06 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/03 17:10:29 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_swap(char *c, int size)
{
	int	temp;
	int	incr;

	incr = 0;
	while (incr < size / 2)
	{
		temp = c[incr];
		c[incr] = c[size - incr - 1];
		c[size - incr - 1] = temp;
		incr++;
	}
}

void	print_base(long long nb, char *base, int base_len, int *counter)
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

void	ft_convert_to_hex(long long i)
{
	char	*hex_chars;
	char	c[2];
	int		incr;

	incr = 0;
	hex_chars = "0123456789abcdef";
	while (i > 0)
	{
		c[incr] = hex_chars[i % 16];
		i = i / 16;
		incr++;
	}
	if (incr <= 1)
		c[incr++] = '0';
	c[incr] = '\0';
	ft_swap(c, 2);
	write(1, c, 2);
}
