/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:27:51 by username         ##+#    #+#             */
/*   Updated: 2026/08/12 22:58:56 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	diff_selection(t_stack *stk_a, t_stack *stk_b, t_flags *flags,
	t_op_count	*op_count)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*stk_a);
	if (stack_size == 3)
		return (stack_is_3(stk_a, op_count));
	if (stack_size == 5)
		return (stack_is_5(stk_a, stk_b, op_count));
	if (flags->has_diff == false || flags->difficulty == DIFF_ADAPTIVE)
		ft_resolve_strategy(flags, disorder(*stk_a));
	if (flags->difficulty == DIFF_SIMPLE)
		return (ft_simple(stk_a, stk_b, op_count));
	else if (flags->difficulty == DIFF_MEDIUM)
		return (chunk_sort(stk_a, stk_b, op_count));
	else
		return (radix_sort(stk_a, stk_b, op_count));
}

static void	free_all(t_stack *stk_a, t_stack *stk_b, t_op_count *op_count)
{
	ft_free_stack(stk_a);
	ft_free_stack(stk_b);
	free_op_count(op_count);
}

void	pushswap(char **argv)
{
	t_node		*stk_a;
	t_node		*stk_b;
	t_node		*og_stk;
	t_flags		flags;
	t_op_count	*op_count;

	stk_a = NULL;
	stk_b = NULL;
	flags = (t_flags)
	{
		0
	};
	op_count = ft_calloc(1, sizeof(t_op_count));
	stk_a = parsing(argv, &flags);
	og_stk = parsing(argv, &flags);
	index_stack(&stk_a);
	diff_selection(&stk_a, &stk_b, &flags, op_count);
	if (flags.has_bench == true)
		output_bench(&og_stk, op_count, &flags);
	free_all(&stk_a, &stk_b, op_count);
	ft_free_stack(&og_stk);
}

int	main(int argc, char **argv)
{
<<<<<<< Updated upstream
	int	fd;
=======
	// if (CHECKER)
		// return (checker(argv), 42);
	if (!ft_strcmp(argv[1], "--debug"))
	{
		argv++;
		argc--;
		int fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (argc < 2)
		return(ft_printf(1, "Incorrect # of arguments\n"), 1);
	pushswap(argv);
	return (0);
}
>>>>>>> Stashed changes

	if (!ft_strcmp(argv[1], "--debug"))
	{
		argv++;
		argc--;
		fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (argc < 2)
		return (ft_printf(1, "Incorrect # of arguments\n"), 1);
	pushswap(argv);
	return (0);
}

// if (CHECKER)
// return (checker(argv), 42);
// --- MAIN: MEDIUM ALG --- //
// int	main(int argc,char **argv)
// {
// 	int	i;
// 	t_node	*stk_a;
// 	t_node	*stk_b;
// 	t_op_count *op_count;

// 	i = 1;
// 	stk_a = NULL;
// 	stk_b = NULL;
// 	op_count = ft_calloc(1, sizeof(t_op_count));
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	if (!ft_strcmp(argv[1], "--debug"))
// 	{
// 		argv++;
// 		argc--;
// 		int fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 		dup2(fd, STDOUT_FILENO);
// 	}
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&stk_a, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	index_stack(&stk_a);
// 	// printf("Original list:\n");
// 	// ft_print_lst(stk_a);
// 	// printf("\n------------\n");
// 	chunk_sort(&stk_a, &stk_b, op_count);
// 	// printf("Sorted stack list:\n");
// 	// ft_print_lst(stk_a);
// 	return (0);
// }
