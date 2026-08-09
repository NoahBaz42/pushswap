/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos <bpassos@student.42.lisbon>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 04:50:30 by charlie           #+#    #+#             */
/*   Updated: 2026/07/06 04:50:30 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int stk_is_sorted(t_node *stack)
{
	t_node  *temp;

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
		return ;
	}
	new->next = *top;
	new->prev = NULL;
	*top = new;
	(*top)->prev = new;
}
t_node	*ft_pop(t_stack *top)
{
	t_node	*popped;

	if(!top)
		return (NULL);
	popped = *top;
	*top = (*top)->next;
	popped->next = NULL;
	return (popped);
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
// 	printf("%f\n", ft_disorder(top));

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