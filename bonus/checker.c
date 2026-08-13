/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:01:55 by charlie           #+#    #+#             */
/*   Updated: 2026/08/13 05:32:59 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "checker.h"

static void	bonus_op(t_stack *stk_a, t_stack *stk_b, t_op_count *op_count,
		char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push_stack(stk_b, stk_a, op_count, 'a');
	else if (ft_strcmp(line, "pb") == 0)
		push_stack(stk_a, stk_b, op_count, 'b');
	else if (ft_strcmp(line, "sa") == 0)
		swap_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "sb") == 0)
		swap_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "ra") == 0)
		rotate_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "rb") == 0)
		rotate_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "rra") == 0)
		rrotate_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "rrb") == 0)
		rrotate_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "ss") == 0)
		op_ss(stk_a, stk_b, op_count);
	else if (ft_strcmp(line, "rr") == 0)
		op_rr(stk_a, stk_b, op_count);
	else if (ft_strcmp(line, "rrr") == 0)
		op_rrr(stk_a, stk_b, op_count);
}

static void	execute_op(t_stack *stk_a, t_stack *stk_b, t_op_count *op_count)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		bonus_op(stk_a, stk_b, op_count, line);
		line = get_next_line(STDIN_FILENO);
	}
}

static void	mini_parse(char **argv)
{
	t_node	*stk_a;
	char	**array;
	size_t	count;
	int		i;

	
	stk_a = NULL;
	i = 1;
	valid_args(argv, i);
	count = count_new_args(argv, i);
	array = ft_split_all(argv, i, count);
	if (!array)
		give_error();
	stk_a = array_to_stk(array);
	if(!stk_a)
		exit_array(array, (int)count);
	if (dup_check(stk_a) == INVALID)
	{
		ft_free_array(array, count);
		exit_stack(&stk_a);
	}
	ft_free_array(array, count);;
	array = ft_split_all(argv, 1, count);
	if (!array)
		give_error();
	stk_a = array_to_stk(array);
	if (!stk_a)
		exit_array(array, (int) count);
	if (dup_check(stk_a) == INVALID)
	{
		ft_free_array(array, count);
		exit_stack(&stk_a);
	}
}
// ft_free_array(array, count);

void	checker(char **argv)
{
	t_stack		*stk_a;
	t_stack		*stk_b;
	t_op_count	*op_count;

	stk_a = NULL;
	stk_b = NULL;
	op_count = ft_calloc(1, sizeof(t_op_count));
	mini_parse(argv);
	execute_op(stk_a, stk_b, op_count);
	if (stk_is_sorted(*stk_a))
		ft_printf(1, "OK");
	else
		ft_printf(1, "KO");
}
// int	main(int argc, char **argv)
// {
// 	if (!ft_strcmp(argv[1], "--debug"))
// 	{
// 		argv++;
// 		argc--;
// 		int fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 		dup2(fd, STDOUT_FILENO);
// 	}
// 	if (argc < 2)
// 		return(ft_printf(1, "Incorrect # of arguments\n"), 1);
// 	checker(argv);
// 	return (0);
// }
