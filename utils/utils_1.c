/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_1.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/12 21:42:04 by username         #+#    #+#              */
/*   Updated: 2026/08/12 21:43:04 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos <bpassos@student.42.lisbon>            +#+  +:+
+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 04:50:30 by charlie           #+#    #+#             */
/*   Updated: 2026/07/06 04:50:30 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	stk_is_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (NOT_SORTED);
		temp = temp->next;
	}
	return (SORTED);
}

void	ft_push(t_stack *top, t_node *new)
{
	if (!top)
		return ;
	if (!*top)
	{
		*top = new;
		(*top)->prev = NULL;
		(*top)->next = NULL;
		return ;
	}
	new->next = *top;
	(*top)->prev = new;
	new->prev = NULL;
	*top = new;
}

t_node	*ft_pop(t_stack *top)
{
	t_node	*popped;

	if (!top || !*top)
		return (NULL);
	popped = *top;
	*top = (*top)->next;
	if (*top)
		(*top)->prev = NULL;
	popped->next = NULL;
	return (popped);
}

void	ft_print_lst(t_node *top)
{
	t_node	*stack;

	stack = top;
	while (stack)
	{
		printf("% 5ld: %3ld @ %1ld\n", stack->content, stack->index,
			stack->cost);
		stack = stack->next;
	}
}

int	ft_abs(ssize_t num)
{
	if (num < 0)
		return (num * -1);
	return (num);
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
// 	printf("Disorder:\n");
// 	printf("%f\n", disorder(top));

// }

// int main (int argc, char **argv)
// {
// 	int	nb;
// 	int sqr;

// 	if (argc != 2)
// 		return(printf("incorrect # of arguments"), 1);
// 	nb = ft_atoi(argv[1]);
// 	sqr = ft_sqr(nb);
// 	printf("Number: %d, SQR: %d\n", nb, sqr);
// 	return (0);
// }
