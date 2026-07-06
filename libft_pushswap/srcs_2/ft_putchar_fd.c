/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:42 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:12 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include "fcntl.h"

// int	main(int argc, char **argv)
// {
// 	char c;
// 	int fd;

// 	c = *argv[1];
// 	fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND);
// 	if (argc < 3)
// 		return (printf("Incorrect # of arguments\n"), 1);
// 	ft_putchar_fd(c, fd);
// 	ft_putchar_fd('\n', fd);
// 	return (0);
// }