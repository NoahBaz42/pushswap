/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:37:15 by username         ##+#    #+#             */
/*   Updated: 2026/08/12 23:12:59 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_stack(t_stack *src, t_stack *dest, t_op_count *op_count,
		char stk_name)
{
	t_node	*tmp;

	if (!src || !dest)
	{
		ft_free_stack(dest);
		ft_free_stack(src);
		give_error();
	}
	if (!*src)
		return ;
	tmp = ft_pop(src);
	ft_push(dest, tmp);
	if (stk_name == 'a')
		op_count->pa++;
	else
		op_count->pb++;
	op_count->total++;
	ft_printf(1, "p%c\n", stk_name);
}

void	op_pushall_a(t_stack *b, t_stack *a, t_op_count *op_count)
{
	while (*b && b)
	{
		push_stack(b, a, op_count, 'a');
	}
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
