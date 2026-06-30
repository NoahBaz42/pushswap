/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:57:26 by noah-baz          #+#    #+#             */
/*   Updated: 2026/06/30 21:48:12 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

static long int	ft_atol(char *array)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (array[i] == ' ' || (array[i] >= 9 && array[i] <= 13))
		i++;
	if (array[i] == '-' || array[i] == '+')
	{
		if (array[i] == '-')
			sign *= -1;
		i++;
	}
	if (!(array[i] >= '0' && array[i] <= '9'))
		return (0);
	while (array[i] >= '0' && array[i] <= '9')
	{
		result = (result * 10) + (array[i] - '0');
		i++;
	}
	return (result * sign);
}

int	arr_count(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**other_parsing(int argc, char **argv)
{
	char	**split_result;
	char	**array;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (strchr(argv[i], ' '))
	{
		split_result = ft_split(argv[i], ' ');
		i++;
	}
	while (split_result)
	{
		array[j] = split_result[j];
		j++;
	}
	return (array);
}

int	ft_dup_check(char **array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*simple_parsing(int argc, char **argv)
{
	int				i;
    int				j;
    int				k;
	char		**array;
	t_list	lst_a;

	i = 1;
	j = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		flag_checker(argc, argv);
	if (argc < 2)
		give_error();
	if (ft_strchr(argv[i], ' '))
		array = other_parsing(argc, argv);
	k = arr_count(array);
	while (i < argc)
	{
		array[k] = argv[i];
		i++;
		k++;
	}
	k = arr_count(array);
	if (ft_dup_check(array, k) == 1)
		give_error();
	//create list a <<ft_lstnew>>!we need to change the libft to make a new ft_lstnew
	return (&lst_a);
}
