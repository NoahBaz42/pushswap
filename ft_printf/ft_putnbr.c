/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:00:29 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/11 01:07:07 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	long int	nb;
	int			count;
	int			ret;
	char		rest;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10, fd);
		count += ret;
	}
	rest = (nb % 10) + '0';
	if (write(fd, &rest, 1) == -1)
		return (-1);
	count++;
	return (count);
}

// #include <stdio.h>
// int main (void)
// {
// 	ft_putnbr(-2147483647);
//     printf("\n%d\n", -2147483647);
// }
