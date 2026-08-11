/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:01:11 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/11 01:04:51 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *str, int fd)
{
	unsigned long	ptr;
	int				ret;

	if (!str)
	{
		if (write(fd, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(fd, "0x", 2) == -1)
		return (-1);
	ptr = (unsigned long)str;
	ret = ft_puthex(ptr, 'x', fd);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
