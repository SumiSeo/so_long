/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:35:38 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/22 18:37:45 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return ((ft_putnbr(-n, base) + 1));
	}
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_putnbr(n / base, base);
		return (count + ft_putnbr(n % base, base));
	}
	return (count);
}
