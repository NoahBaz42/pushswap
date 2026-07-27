/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 05:45:15 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/07/27 17:30:36 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

//----------[counts args, without spaces]---------------------------------//

size_t	ft_count_args(const char *arg)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (arg[i])
	{
		while (ft_isspace(arg[i]) == 1)
			i++;
		if (arg[i] && ft_isspace(arg[i]) == 0)
			words++;
		while (arg[i] && ft_isspace(arg[i]) == 0)
			i++;
	}
	return (words);
}

//----------[with ft_count_args, checks all of the array]-----------------//

size_t	ft_count_new_args(char **argv, size_t	i)
{
	size_t	count;

	count = 0;
	while (argv[i])
	{
		count += ft_count_args(argv[i]);
		i++;
	}
	return (count);
}

//----------[+ or -]-----------------//

int	ft_isoperator(char c)
{
	if (c == '-' || (c == '+'))
		return (1);
	return (0);
}

//-----[white space checker]---------//

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

//------[ascii to long int]----------//

long int	ft_atol(char *array)
{
	int			i;
	int			sign;
	long int	result;

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
		i++;
	}
	return (result * sign);
}
