/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:37:15 by charlie           #+#    #+#             */
/*   Updated: 2026/08/09 16:02:35 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "C_algorithm/ft_printf/ft_printf.h"
#include <linux/openat2.h>

//--------------------------//
//----------PUSH------------//
//--------------------------//

/*-------[ operations: pa ]----------*/


void    op_pa_stack(t_stack *stk_b, t_stack *stk_a, t_op_count	*op_count)
{
    t_node  	*tmp;
  
    if (!stk_b || !stk_a)
	{
		ft_free_stack(stk_b);
		ft_free_stack(stk_a);
        give_error();
	}
    tmp = ft_pop(stk_b);
    ft_push(stk_a, tmp);
	op_count->pa++;
	op_count->total++;
    ft_printf(1,"pa\n");
}

/*-------[ operations: pb ]----------*/

void    op_pb_stack(t_stack *stk_a, t_stack *stk_b, t_op_count	*op_count)
{
    t_node  	*tmp;
  
    if (!stk_a || !stk_b)
	{
		ft_free_stack(stk_a);
		ft_free_stack(stk_b);
        give_error();
	}
    tmp = ft_pop(stk_a);
    ft_push(stk_b, tmp);
	op_count->pb++;
	op_count->total++;
    ft_printf(1,"pb\n");
    
}



//-----------pstack----------//


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
// 		ft_lstadd_back(&b, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
//     i = 1;
// 	printf("Sorted:\n");
// 	ft_pushall_b(&b, &top);
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

