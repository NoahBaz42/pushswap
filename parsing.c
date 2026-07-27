/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:20:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/07/27 17:31:19 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*------[ checks for valid numbers ]--------*/

static int	ft_is_valid_number(char *arg, int j)
{
	if (ft_isoperator(arg[j]))
		j++;
	if (!ft_isdigit(arg[j]))
		ft_give_error();
	while (ft_isdigit(arg[j]))
		j++;
	if (arg[j] && !ft_isspace(arg[j]))
		ft_give_error();
	return (j);
}

/*------[ checks for valid arguments ]--------*/

void	ft_valid_args(char **argv, size_t i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				j++;
			else
				j = ft_is_valid_number(argv[i], j);
		}
		i++;
	}
}

/*------[ checks first 2 args for valid flags ]--------*/

void	ft_valid_flag(char **argv)
{
	if (argv[1] && ft_strnstr(argv[1], "--", 2))
		if ((!ft_is_diff_flags(argv[1])) && (!ft_is_bench_flags(argv[1])))
			ft_give_error();
	if (argv[2] && ft_strnstr(argv[2], "--", 2))
		if ((!ft_is_diff_flags(argv[2])) && (!ft_is_bench_flags(argv[2])))
			ft_give_error();
}

/*------[ main function: ft_parsing ]--------*/

t_list	*ft_parsing(char **argv)
{
	size_t	i;
	size_t	count;
	char	**array;
	t_flags	flags;
	t_list	*stack_a;

	flags = (t_flags){0};
	ft_flag_check(&flags, argv);
	i = ft_count_flags(&flags) + 1;
	ft_valid_flag(argv);
	ft_valid_args(argv, i);
	count = ft_count_new_args(argv, i);
	array = ft_split_all(argv, i, count);
	if (!array)
		ft_give_error();
	stack_a = ft_array_to_stack(array);
	ft_is_it_duplicate(stack_a);
	return (stack_a);
}
