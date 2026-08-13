/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:00:56 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/13 22:40:07 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrotate_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
	t_node	*new_top;

	if (!stk || !*stk)
	{
		printf("rrs\n");
		ft_free_stack(stk);
		give_error();
	}
	new_top = ft_lstlast(*stk);
	new_top->prev->next = NULL;
	new_top->prev = NULL;
	new_top->next = *stk;
	new_top->next->prev = new_top;
	(*stk) = new_top;
	if (stk_name == 'a')
		op_count->rra++;
	else
		op_count->rrb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "rr%c\n", stk_name);
}

void	op_rrr(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (a && *a)
		rrotate_stack(a, op_count, 'a');
	if (b && *b)
		rrotate_stack(b, op_count, 'b');
}

//-----------rrstack----------//
// int	main(int argc,char **argv)
// {
// 	// t_node	*top;
//     t_node  *b;

// 	int	i;

// 	i = 1;
// 	// top = NULL;
//     b = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&b, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
//     i = 1;
// 	printf("Sorted:\n");
// 	ft_rrstack(&b);
//     printf("b:\n");
// 	while (b)
// 	{
// 		printf("%d\n", b->content);
// 		b = b->next;
// 	}
// }

//-----------rr----------//
// int	main(int argc,char **argv)
// {
// 	t_node	*top;
//     t_node  *b;

// 	int	i;

// 	i = 1;
// 	top = NULL;
//     b = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
//     i = 1;
//     while (i < argc)
// 	{
// 		ft_lstadd_back(&b, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	printf("Sorted:\n");
// 	ft_rr(&top, &b);
//     printf("a:\n");
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
//     printf("b:\n");
// 	while (b)
// 	{
// 		printf("%d\n", b->content);
// 		b = b->next;
// 	}
// }