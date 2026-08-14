/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 08:21:47 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:19:00 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_split_arg(char **array, char *arg, size_t size)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	while (arg[i])
	{
		while (ft_isspace(arg[i]))
			i++;
		if (arg[i])
		{
			start = i;
			len = 0;
			while (arg[i] && !ft_isspace(arg[i]))
			{
				len++;
				i++;
			}
			array[size] = ft_substr(arg, start, len);
			if (!array[size])
				return (ft_free_array(array, size), -1);
			size++;
		}
	}
	return (size);
}

char	**ft_split_all(char **argv, size_t arg_index, size_t count)
{
	char	**array;
	ssize_t	size;

	size = 0;
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	ft_bzero(array, sizeof(char *) * (count + 1));
	while (argv[arg_index])
	{
		size = ft_split_arg(array, argv[arg_index], size);
		if (size == -1)
			return (NULL);
		arg_index++;
	}
	array[size] = NULL;
	return (array);
}
