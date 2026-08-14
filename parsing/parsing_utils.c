/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 05:45:15 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:18:49 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	count_args(const char *arg)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (arg[i])
	{
		while (isspace(arg[i]) == 1)
			i++;
		if (arg[i] && isspace(arg[i]) == 0)
			words++;
		i++;
	}
	return (words);
}

size_t	count_new_args(char **argv, size_t i)
{
	size_t	count;

	count = 0;
	while (argv[i])
	{
		count += count_args(argv[i]);
		i++;
	}
	return (count);
}

int	ft_isoperator(char c)
{
	if (c == '-' || (c == '+'))
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	ft_atol(char *array)
{
	int				i;
	long			sign;
	long			result;

	i = 0;
	sign = 1;
	result = 0;
	while (array[i] == ' ' || (array[i] >= 9 && array[i] <= 13))
		i++;
	if (array[i] == '-' || array[i] == '+')
	{
		if (array[i] == '-')
			sign *= -1;
		i++;
	}
	while (array[i] >= '0' && array[i] <= '9')
	{
		result = (result * 10) + (array[i] - '0');
		if ((result * sign) < INT_MIN)
			return (1L + INT_MAX);
		else if ((result * sign) > INT_MAX)
			return (1L + INT_MAX);
		i++;
	}
	return (result * sign);
}
