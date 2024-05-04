/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:35:22 by parallel          #+#    #+#             */
/*   Updated: 2024/05/04 17:13:49 by stevennk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
void	ft_putnbr_unsigned(unsigned int nb, int *incr);
int		ft_prinfstr(char *str);
int		ft_printchar(char c);
int		ft_print_special(char c, va_list *ptr);
int		ft_print_hex(int nb, int _case);
int		ft_print_unsigned_decimal(unsigned int nb);
int		ft_print_decimal(int nb);
int		ft_print_pointer(void *str);
#endif
