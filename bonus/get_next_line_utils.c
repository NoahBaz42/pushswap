/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:32:23 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/10 23:45:37 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen_gnl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (i);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ndest;
	const unsigned char	*nsrc;
	size_t				i;

	i = 0;
	ndest = dest;
	nsrc = src;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	int		size_l;
	int		size_b;
	char	*new;

	if (!buffer)
		return (line);
	size_l = ft_strlen_gnl(line);
	size_b = ft_strlen_gnl(buffer);
	new = malloc(size_l + size_b + 1);
	if (!new)
		return (NULL);
	if (line)
		ft_memcpy(&new[0], line, size_l);
	ft_memcpy(&new[size_l], buffer, size_b);
	new[size_l + size_b] = '\0';
	free(line);
	return (new);
}

void	ft_update(char *buffer)
{
	size_t	start;
	size_t	i;

	start = ft_strlen_gnl(buffer);
	if (!start)
		return ;
	i = 0;
	while (buffer[start + i])
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_find_line(char *line)
{
	if (!line)
		return (NULL);
	while (*line)
	{
		if (*line == '\n')
			return (line + 1);
		line++;
	}
	return (NULL);
}
