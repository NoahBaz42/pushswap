/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:20:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/13 20:22:23 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <strings.h>

/*------[ checks for valid numbers ]--------*/

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

/*------[ checks for valid arguments ]--------*/

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

/*------[ main function: parsing ]--------*/

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
	stk_a = array_to_stk(array);
	if (!stk_a)
		exit_array(array, (int)count);
	if (dup_check(stk_a) == INVALID)
	{
		ft_free_array(array, count);
		free(flags);
		exit_stack(&stk_a);
	}
	ft_free_array(array, count);
	return (stk_a);
}
// int	main(int argc,char **argv)
// {
// 	t_node	*stk_a;
// 	t_node	*stk_b;

// 	stk_a = NULL;
// 	stk_b = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	stk_a = parsing(argv);
// 	index_stack(stk_a);
// 	chunk_sort(&stk_a, &stk_b);
// 	printf("Stack_a:\n");
// 	ft_print_lst(stk_a);
// 	ft_free_stack(&stk_a);
// 	ft_free_stack(&stk_b);
// 	return (0);
// }
