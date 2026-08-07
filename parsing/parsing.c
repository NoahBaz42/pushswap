/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:20:16 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/07 07:26:51 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 


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
	ft_valid_args(argv, i);
	count = ft_count_new_args(argv, i);
	array = ft_split_all(argv, i, count);
	if (!array)
		ft_give_error();
	stack_a = ft_array_to_stack(array);
	if(!stack_a)
		ft_exit_array(array, (int)count);
	if (ft_integer_check(stack_a))
	{
		ft_free_array(array, (int)count);
		ft_exit_stack(&stack_a);
	}
	ft_free_array(array, (int)count);
	return (stack_a);
}
