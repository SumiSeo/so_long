/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:31:19 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 13:32:40 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long n, int base);
int	ft_putmnbr(long n, int base);
int	ft_putptr(long unsigned n);
int	ft_printf(const char *format, ...);

#endif
