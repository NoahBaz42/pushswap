/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:01:00 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/07 06:02:22 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_sstack(t_stack *stack)
{
    int  temp;

    if (ft_lstsize(*stack) == 1)
        return ;
    if (!*stack)
	{
		ft_free_stack(stack);
        ft_give_error();
	}
    temp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = temp;
}
void    ft_ss(t_node *a, t_node *b)
{
    ft_sstack(&a);
    ft_sstack(&b);
}
void    ft_pstack(t_stack *src, t_stack *dest)
{
    t_node  *tmp;
  
    if (!src || !dest)
	{
		ft_free_stack(src);
		ft_free_stack(dest);
        ft_give_error();
	}
    tmp = ft_pop(src);
    ft_push(dest, tmp);
    
}
void    ft_rstack(t_stack *stack)
{
	t_node	*new_start;
	t_node *last;

    if (!stack && !*stack)
	{
		ft_free_stack(stack);
        ft_give_error();
	}
	new_start = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = ft_pop(stack);
	*stack = new_start;
}

void    ft_rr(t_stack *a, t_stack *b)
{
    ft_rstack(a);
    ft_rstack(b);
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
// 	ft_pstack(&top, &b);
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