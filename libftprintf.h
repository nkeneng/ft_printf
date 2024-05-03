/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:35:22 by parallel          #+#    #+#             */
/*   Updated: 2024/05/03 17:10:17 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		in_list(char c);
int		get_conv_nb(const char *str);
void	fill_cvalues(const char *str, char *res);
size_t	ft_strlen(char const *str);
void	ft_convert_to_hex(long long i);
void	print_base(long long nb, char *base, int base_len, int *counter);
void	ft_putnbr(int nb, int *incr);
#endif
