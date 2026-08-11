/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:58:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/10 23:45:44 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
