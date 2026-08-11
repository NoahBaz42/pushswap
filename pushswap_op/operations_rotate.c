/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:42:23 by charlie           #+#    #+#             */
/*   Updated: 2026/08/11 18:45:33 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    rotate_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
    t_node		*new_start;
	t_node 		*last;

    if (!stk && !*stk)
	{
		ft_free_stack(stk);
        give_error();
	}
	new_start = (*stk)->next;
	last = ft_lstlast(*stk);
	last->next = ft_pop(stk);
    last->next->prev = last;
	*stk = new_start;
    new_start->prev = NULL;
    if (stk_name == 'a')
	    op_count->ra++;
    else
        op_count->rb++;
    op_count->total++;
    ft_printf(1,"r%c\n", stk_name);
}
void    op_rr(t_stack *a, t_stack *b, t_op_count *op_count)
{
    if(a && *a)
        rotate_stack(a, op_count, 'a');
    if(b && *b)
        rotate_stack(b, op_count, 'b');
    
}


// int	main(int argc,char **argv)
// {
// 	t_node	*top;
	
// 	int	i;

// 	i = 1;
// 	top = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	printf("Unsorted:\n");
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	printf("Sorted:\n");
// 	ft_rstack(&top);
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// }
