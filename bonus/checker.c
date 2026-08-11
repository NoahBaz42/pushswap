/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:01:55 by charlie           #+#    #+#             */
/*   Updated: 2026/08/10 23:44:38 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "checker.h"

static void	bonus_op(t_node *stk_a, t_node *stk_b, t_op_count *op_count, char *line)
{
	if(ft_strcmp(line, "pa") == 0)
		op_pa_stack(&stk_b, &stk_a, op_count);
	else if(ft_strcmp(line, "pb") == 0)
		op_pb_stack(&stk_a, &stk_b, op_count);
	else if(ft_strcmp(line, "sa") == 0)
		op_sa_stack(&stk_a, op_count);
	else if(ft_strcmp(line, "sb") == 0)
		op_sb_stack(&stk_b, op_count);
	else if(ft_strcmp(line, "ra") == 0)
		op_ra_stack(&stk_a, op_count);
	else if(ft_strcmp(line, "rb") == 0)
		op_rb_stack(&stk_b, op_count);
	else if(ft_strcmp(line, "rra") == 0)
		op_rra_stack(&stk_a, op_count);
	else if(ft_strcmp(line, "rrb") == 0)
		op_rrb_stack(&stk_b, op_count);
	else if(ft_strcmp(line, "ss") == 0)
		op_ss(stk_a, stk_b, op_count);
	else if(ft_strcmp(line, "rr") == 0)
		op_rr(&stk_a, &stk_b, op_count);
	else if(ft_strcmp(line, "rrr") == 0)
		op_rrr(&stk_a, &stk_b, op_count);
}

void	checker(char **argv)
{
	t_node *stk_a;
	t_node *stk_b;
	t_op_count *op_count;
	
	stk_a = parsing(argv);
	stk_b = NULL;
	op_count = ft_calloc(1, sizeof(t_op_count));
	bonus_op (stk_a, stk_b, op_count, get_next_line(0));
	if (stk_is_sorted(stk_a))
		ft_printf(1, "OK");
	ft_printf(1, "KO");
	ft_free_stack(&stk_a);
	ft_free_stack(&stk_b);
}