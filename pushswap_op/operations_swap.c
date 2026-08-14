/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:31:47 by charlie           #+#    #+#             */
/*   Updated: 2026/08/14 02:02:32 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//--------------------------//
//----------SWAP------------//
//--------------------------//

/*-------[ operations: sa ]----------*/

void	swap_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
	int	temp;

	if (ft_lstsize(*stk) == 1)
		return ;
	if (!*stk)
	{
		ft_free_stack(stk);
		give_error();
	}
	temp = (*stk)->content;
	(*stk)->content = (*stk)->next->content;
	(*stk)->next->content = temp;
	if (stk_name == 'a')
		op_count->sa++;
	else
		op_count->sb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "s%c\n", stk_name);
}

void	op_ss(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (a && *a)
		swap_stack(a, op_count, 'a');
	if (b && *b)
		swap_stack(b, op_count, 'b');
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
