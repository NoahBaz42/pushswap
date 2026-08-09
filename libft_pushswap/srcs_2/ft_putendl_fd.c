/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:45 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:35:29 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;
// 	int		fd;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"));
// 	s = argv[1];
// 	fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND);
// 	ft_putendl_fd(s, fd);
// }
