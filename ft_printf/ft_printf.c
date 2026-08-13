/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:51:31 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/13 07:09:30 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list *va, const char *format, int fd)
{
	int	total;

	total = 0;
	if (*format == 'c')
		total += ft_putchr(va_arg(*va, int), fd);
	else if (*format == 'X' || *format == 'x')
		total += ft_puthex(va_arg(*va, unsigned long), *format, fd);
	else if (*format == 'd' || *format == 'i')
		total += ft_putnbr(va_arg(*va, int), fd);
	else if (*format == 'p')
		total += ft_putptr(va_arg(*va, void *), fd);
	else if (*format == 's')
		total += ft_putstr(va_arg(*va, char *), fd);
	else if (*format == 'u')
		total += ft_putuns(va_arg(*va, unsigned int), fd);
	else if (*format == '%')
		total += ft_putchr('%', fd);
	return (total);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	va;
	int		i;
	int		cnt;

	if (!format)
		return (-1);
	va_start(va, format);
	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
			cnt = ft_type(&va, &format[++i], fd);
		else
			cnt = write(fd, &format[i], 1);
		if (format[i])
			i++;
	}
	va_end(va);
	return (cnt);
}
