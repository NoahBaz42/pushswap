/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 06:53:11 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/11 01:04:37 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char format, int fd)
{
	char	*hex;
	int		count;
	int		ret;
	char	rest;

	hex = "0123456789abcdef";
	if (format == 'X')
		hex = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		ret = ft_puthex(num / 16, format, fd);
		count += ret;
	}
	rest = hex[num % 16];
	if (write(fd, &rest, 1) == -1)
		return (-1);
	count++;
	return (count);
}
