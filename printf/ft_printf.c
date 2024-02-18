/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:56:46 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/22 17:00:47 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_putnbr(va_arg(ap, int), 10);
	else if (specifier == 'i')
		count += ft_putnbr((long)va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_putnbr((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_putmnbr((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'p')
		count += ft_putptr((long unsigned)(va_arg(ap, void *)));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	char *ptr;
	int num;
	char *s;
	char c;
	int count;
	int original_count;
	original_count = 0;
	count = 0;
	num = 403423;
	ptr = "pointdfsdfdsfdsfdsfdsfdsfer address";
	c = 'A';
	s = "PRINT Fdfdfdsfsdfdfsf";
	count = ft_printf("character :%c\n and %s\n and %p\n and %d\n", c, s, &ptr,
			num);
	printf("total length %d\n", count);
	original_count = printf("character :%c\n and %s\n and %p\n and %d\n", c, s,
			&ptr, num);
	printf("original total length %d\n", original_count);
	printf("%p\n", &ptr);
	ft_printf("%p\n", &ptr);
}*/