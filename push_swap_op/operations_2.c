/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:00:56 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/06 06:56:41 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "libft_pushswap/libft.h"

void    ft_rrstack(t_node **stack)
{
    t_node *b4last;
    t_node *new_top;
    
    if (!stack || !*stack)
    {
        printf("rrs\n");
        ft_free_stack(stack);
        ft_give_error();
    }
    b4last = ft_lstb4last(*stack);
    new_top = ft_lstlast(*stack);
    new_top->next = *stack;
    b4last->next = NULL;
    (*stack) = new_top;
}

void    ft_rrr(t_node **a, t_node **b)
{
    if (a && *a)
        ft_rrstack(a);
    if (b && *b)
        ft_rrstack(b);
}
void    ft_pushall_a(t_node **b, t_node **a)
{
    while (*b)
    {
        ft_pstack(b, a);
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