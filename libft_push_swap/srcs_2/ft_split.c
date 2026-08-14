/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:52 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:08 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_freesplit(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free(s[j]);
		j++;
	}
	free(s);
}

static int	get_str_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_allocate_str(char const *s, char c, size_t *n)
{
	size_t	i;
	size_t	len;
	size_t	start;
	char	*str;

	i = *n;
	len = 0;
	start = i;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	*n = i;
	str = ft_substr(s, start, len);
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	strs;
	char	**matrix;

	i = 0;
	strs = 0;
	matrix = ft_calloc(get_str_count(s, c) + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			matrix[strs] = ft_allocate_str(s, c, &i);
			if (!matrix[strs])
				return (ft_freesplit(matrix), NULL);
			strs++;
		}
	}
	matrix[strs] = NULL;
	return (matrix);
}

// int	main(int argc, char **argv)
// {
// 	char		**matrix;
// 	char const	*str;
// 	char		c;
// 	int			i;

// 	if (argc < 3)
// 		return (0);
// 	str = argv[1];
// 	c = *argv[2];
// 	i = 0;
// 	matrix = ft_split(str, c);
// 	printf("ft_split:\nstr: %s\nc: (%c)\narray:\n---\n", str, c);
// 	while (matrix[i])
// 	{
// 		printf("[%d] '%s'\n", i + 1, matrix[i]);
// 		i++;
// 	}
// 	printf("[%d] --- %s ---\n", i + 1, matrix[i]);
// 	ft_freesplit(matrix);
// 	return (0);
// }
