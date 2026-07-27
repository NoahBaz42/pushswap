
#include "push_swap.h"

static void ft_print_flags(t_flags *flags)
{
		printf("has_bench: %d, has_diff: %d, diff: %d\n", flags->has_bench, flags->has_diff, flags->difficulty);
		printf("flag_count: %d\n", ft_count_flags(flags));
}

int main (int argc, char **argv)
{
	t_flags	flags;

	(void)argc;
	flags = (t_flags){false, false, DIFF_ADAPTIVE};
	ft_flag_check(&flags, argv);
	ft_print_flags(&flags);
	return (0);
}
/*
int	main(int ac, char **argv)
{
	t_list	*list;
	t_node	*tmp;
	int		i;

	if (ac < 2)
		return (1);
	list = ft_parsing(argv);
	tmp = list->home;
	i = 0;
	while (tmp)
	{
		printf("node[%d]> %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
*\