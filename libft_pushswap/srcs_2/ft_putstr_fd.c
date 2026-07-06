/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:12 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;
// 	int		fd;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"));
// 	s = argv[1];
// 	fd = atoi(argv[2]);
// 	ft_putendl_fd(s, fd);
// }
