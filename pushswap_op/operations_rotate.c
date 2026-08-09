/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:42:23 by charlie           #+#    #+#             */
/*   Updated: 2026/08/09 16:03:58 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//--------------------------//
//--------ROTATE------------//
//------A---AND---B---------//

/*-------[ operations: ra ]----------*/

void    op_ra_stack(t_stack *stk_a, t_op_count	*op_count)
{
	t_node		*new_start;
	t_node 		*last;

    if (!stk_a && !*stk_a)
	{
		ft_free_stack(stk_a);
        give_error();
	}
	new_start = (*stk_a)->next;
	last = ft_lstlast(*stk_a);
	last->next = ft_pop(stk_a);
	*stk_a = new_start;
	op_count->ra++;
	op_count->total++;
    ft_printf(1,"ra\n");
}

/*-------[ operations: rb ]----------*/

void    op_rb_stack(t_stack *stk_b, t_op_count	*op_count)
{
	t_node		*new_start;
	t_node 		*last;

    if (!stk_b && !*stk_b)
	{
		ft_free_stack(stk_b);
        give_error();
	}
	new_start = (*stk_b)->next;
	last = ft_lstlast(*stk_b);
	last->next = ft_pop(stk_b);
	*stk_b = new_start;
	op_count->rb++;
	op_count->total++;
    ft_printf(1,"rb\n");
}

/*-------[ operations: rra ]----------*/


void    op_rra_stack(t_stack *stk_a, t_op_count	*op_count)
{
    t_node     *b4last;
    t_node     *new_top;
    
    if (!stk_a || !*stk_a)
    {
        printf("rrs\n");
        ft_free_stack(stk_a);
        give_error();
    }
    b4last = ft_lstb4last(*stk_a);
    new_top = ft_lstlast(*stk_a);
    new_top->next = *stk_a;
    b4last->next = NULL;
    (*stk_a) = new_top;
	op_count->rra++;
	op_count->total++;
    ft_printf(1,"rra\n");
}

/*-------[ operations: rrb ]----------*/

void    op_rrb_stack(t_stack *stk_b, t_op_count	*op_count)
{
    t_node     *b4last;
    t_node     *new_top;
    
    if (!stk_b || !*stk_b)
    {
        printf("rrs\n");
        ft_free_stack(stk_b);
        give_error();
    }
    b4last = ft_lstb4last(*stk_b);
    new_top = ft_lstlast(*stk_b);
    new_top->next = *stk_b;
    b4last->next = NULL;
    (*stk_b) = new_top;
	op_count->rrb++;
	op_count->total++;
    ft_printf(1,"rrb\n");
}



//-----------rstack----------//


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
