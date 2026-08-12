/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:58:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/12 04:06:03 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!*buffer)
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if (read_size < 0)
				return (free(line), NULL);
			buffer[read_size] = '\0';
			if (read_size == 0)
				return (line);
		}
		line = ft_strjoin_gnl(line, buffer);
		ft_update(buffer);
		if (ft_find_line(line))
			break ;
	}
	return (line);
}
// int main(void)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	line = NULL;
// 	while (!i || strcmp(line, "END\n"))
// 	{
// 		line = get_next_line(STDIN_FILENO);
// 		printf("[%03d] %s", i, line);
// 		i++;
// 	}
// }