/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:01:55 by charlie           #+#    #+#             */
/*   Updated: 2026/08/13 23:21:48 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "checker.h"

static void	bonus_op(t_stack *stk_a, t_stack *stk_b, t_op_count *op_count,
		char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_stack(stk_b, stk_a, op_count, 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		push_stack(stk_a, stk_b, op_count, 'b');
	else if (ft_strcmp(line, "sa\n") == 0)
		swap_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "rra\n") == 0)
		rrotate_stack(stk_a, op_count, 'a');
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrotate_stack(stk_b, op_count, 'b');
	else if (ft_strcmp(line, "ss\n") == 0)
		op_ss(stk_a, stk_b, op_count);
	else if (ft_strcmp(line, "rr\n") == 0)
		op_rr(stk_a, stk_b, op_count);
	else if (ft_strcmp(line, "rrr\n") == 0)
		op_rrr(stk_a, stk_b, op_count);
}

static void	store_op(t_op_lst **op_lst)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line && *line)
	{
		if (!ft_strcmp(line, "\n"))
		{
			free(line);
			break;
		}
		add_op(op_lst, op_new(line));
		line = get_next_line(STDIN_FILENO);
	}
}

static void	execute_op(t_stack *stk_a, t_stack *stk_b,
						t_op_count *op_count, t_op_lst **op_lst)
{
	t_op_lst	*node;

	node = *op_lst;
	while (node)
	{
		bonus_op(stk_a, stk_b, op_count, node->op);
		node = node->next;
	}
}

static t_node	*mini_parse(char **argv)
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

void	checker(char **argv)
{
	t_node		*stk_a;
	t_node		*stk_b;
	t_op_count	*op_count;
	t_op_lst	*op_lst;

	stk_a = NULL;
	stk_b = NULL;
	op_lst = NULL;
	op_count = ft_calloc(1, sizeof(t_op_count));
	op_count->checker = true;
	stk_a = mini_parse(argv);
	store_op(&op_lst);
	execute_op(&stk_a, &stk_b, op_count, &op_lst);
	if (stk_is_sorted(stk_a))
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free(op_count);
	ft_free_stack(&stk_a);
	free_op_lst(&op_lst, free_op_node);
}
int	main(int argc, char **argv)
{
	if (!ft_strcmp(argv[1], "--debug"))
	{
		argv++;
		argc--;
		int fd = open("log.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (argc < 2)
		return(ft_printf(1, "Incorrect # of arguments\n"), 1);
	checker(argv);
	return (0);
}
