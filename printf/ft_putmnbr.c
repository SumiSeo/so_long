/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:31:40 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 13:31:42 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putmnbr(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return ((ft_putmnbr(-n, base) + 1));
	}
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_putmnbr(n / base, base);
		return (count + ft_putmnbr(n % base, base));
	}
	return (count);
}
