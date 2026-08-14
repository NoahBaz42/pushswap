/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:20:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:18:20 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <strings.h>

static int	is_valid_number(char *arg, int j)
{
	if (ft_isoperator(arg[j]))
		j++;
	if (!isdigit(arg[j]))
		give_error();
	while (isdigit(arg[j]))
		j++;
	if (arg[j] && !isspace(arg[j]))
		give_error();
	return (j);
}

void	valid_args(char **argv, size_t i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isspace(argv[i][j]))
				j++;
			else
				j = is_valid_number(argv[i], j);
		}
		i++;
	}
}

t_node	*parsing(char **argv, t_flags *flags)
{
	size_t	i;
	size_t	count;
	char	**array;
	t_node	*stk_a;

	stk_a = NULL;
	flag_check(flags, argv);
	i = count_flags(flags) + 1;
	valid_args(argv, i);
	count = count_new_args(argv, i);
	array = ft_split_all(argv, i, count);
	if (!array)
		give_error();
	stk_a = array_to_stk(array, count);
	if (!stk_a)
		exit_array(array, (int)count);
	if (dup_check(stk_a) == INVALID)
	{
		ft_free_array(array, count);
		exit_stack(&stk_a);
	}
	ft_free_array(array, count);
	return (stk_a);
}
