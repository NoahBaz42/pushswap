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

#include "../push_swap.h"

float ft_disorder(t_node *stack)
{
	t_node  *temp;
	t_node  *temp2;
	float     disorder;
	float      total;

	temp = stack;
	disorder = 0;
	total = 0;
	while (temp)
	{
		temp2 = temp->next;
		while(temp2)
		{
			total++;
			if (temp->content > temp2->content)
				disorder++;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if(total == 0)
		return (0);
	return ((disorder/total) * 100);
}
void    ft_give_error(void)
{
	printf("Error\n");
	exit (1);
}
int ft_is_sorted(t_node *stack)
{
	t_node  *temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_push(t_node **top, t_node *new)
{
	if (!top)
		return ;
	if (!*top)
	{
		*top = new;
		return ;
	}
	new->next = *top;
	*top = new;
}
t_node	*ft_pop(t_node **top)
{
	t_node	*popped;

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