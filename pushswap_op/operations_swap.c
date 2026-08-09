/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:31:47 by charlie           #+#    #+#             */
/*   Updated: 2026/08/09 16:05:57 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//--------------------------//
//----------SWAP------------//
//--------------------------//

/*-------[ operations: sa ]----------*/

void    op_sa_stack(t_stack *stk_a, t_op_count	*op_count)
{
    int			temp;

    if (ft_lstsize(*stk_a) == 1)
        return ;
    if (!*stk_a)
	{
		ft_free_stack(stk_a);
        give_error();
	}
    temp = (*stk_a)->content;
    (*stk_a)->content = (*stk_a)->next->content;
    (*stk_a)->next->content = temp;
	op_count->sa++;
	op_count->total++;
    ft_printf(1,"sa\n");
}

/*-------[ operations: sb ]----------*/

void    op_sb_stack(t_stack *stk_b, t_op_count	*op_count)
{
    int			temp;

    if (ft_lstsize(*stk_b) == 1)
        return ;
    if (!*stk_b)
	{
		ft_free_stack(stk_b);
        give_error();
	}
    temp = (*stk_b)->content;
    (*stk_b)->content = (*stk_b)->next->content;
    (*stk_b)->next->content = temp;
	op_count->sb++;
	op_count->total++;
    ft_printf(1,"sb\n");
}

/*-------[ operations: ss ]----------*/

void    op_ss(t_node *a, t_node *b, t_op_count	*op_count)
{
    op_sa_stack(&a, op_count);
    op_sb_stack(&b, op_count);
}



//-----------sstack----------//


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
// 	ft_sstack(&top);
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// }



//-----------ss----------//


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
// 	ft_ss(top, b);
// 	while (top || b)
// 	{
// 		printf("%d    %d\n", top->content, b->content);
// 		top = top->next;
//         b = b->next;
// 	}
// }
