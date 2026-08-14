/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 05:45:15 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 04:24:47 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//----------[counts args, without spaces]---------------------------------//

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

//----------[with count_args, checks all of the array]-----------------//
/*[------------------!!!NEEDS REVISION!!!!------------------------- ]*/
/*[ ps: DOES NOT give a valid error: must free BEFORE exiting.. ]*/

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
/*[------------------!!!NEEDS REVISION!!!!------------------------- ]*/
/*[ ps: DOES NOT give a valid error: must free BEFORE exiting.. ]*/

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
			give_error();
		else if ((result * sign) > INT_MAX)
			give_error();
		i++;
	}
	return (result * sign);
}
