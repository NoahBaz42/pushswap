/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:00:56 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/11 05:52:15 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    op_rr(t_stack *a, t_stack *b, t_op_count *op_count, char stk_name)
{
    if(a && *a)
        rotate_stack(a, op_count, stk_name);
    if(b && *b)
        rotate_stack(b, op_count, stk_name);
    
}

void    op_rrr(t_stack *a, t_stack *b, t_op_count *op_count,char stk_name)
{
    if (a && *a)
        rrotate_stack(a, op_count, stk_name);
    if (b && *b)
        rrotate_stack(b, op_count, stk_name);
}
void    op_pushall_a(t_stack *b, t_stack *a, t_op_count	*op_count, char stk_name)
{
    while (*b && b)
    {
        push_stack(b, a, op_count, stk_name);
    }
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