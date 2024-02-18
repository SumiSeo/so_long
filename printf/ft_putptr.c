/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:37 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/23 17:10:59 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	control_nul(void)
{
	ft_putstr("(nil)");
	return (5);
}

int	ft_putptr(long unsigned n)
{
	long unsigned	temp;
	char			final[256];
	int				i;
	int				count;

	count = 0;
	if (!n)
		return (control_nul());
	i = 0;
	while (n > 0)
	{
		temp = n % 16;
		final[i++] = "0123456789abcdef"[temp];
		n /= 16;
	}
	count += write(1, "0x", 2);
	while (--i >= 0)
		count += write(1, &final[i], 1);
	return (count);
}

// int	main(void)
// {
// 	unsigned	n;

// 	n = 1234;
// 	ft_putptr((long unsigned)n);
// 	printf("Here : [%p]\n", (void *)(long unsigned)n);
// }
