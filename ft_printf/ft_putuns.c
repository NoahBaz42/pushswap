/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 06:53:36 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/11 01:07:27 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int num, int fd)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_putuns(num / 10, fd);
	count += ft_putchr(num % 10 + '0', fd);
	return (count);
}
