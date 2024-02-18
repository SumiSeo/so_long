/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:34:22 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/22 17:36:17 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar((int)*str);
		count++;
		str++;
	}
	return (count);
}
