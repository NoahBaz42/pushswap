/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:57:38 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:27:11 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft_push_swap/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NOT_FOUND 0
# define FOUND 1

# define BOTTOM_HALF 0
# define TOP_HALF 1

# define NOT_SORTED 0
# define SORTED 1

# define INVALID 0
# define VALID 1

typedef t_node	*t_stack;

//--------------------------//
//--------Structs-----------//
//--------------------------//

typedef struct e_op_count
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		ss;
	int		rr;
	int		rrr;
	int		total;
	bool	checker;
}	t_op_count;

typedef enum e_flags
{
	DIFF_ADAPTIVE,
	DIFF_SIMPLE,
	DIFF_MEDIUM,
	DIFF_COMPLEX
}	t_diff;

typedef struct s_flags
{
	bool	has_bench;
	bool	has_diff;
	t_diff	difficulty;
	t_diff	chosen;
}		t_flags;

//--------------------------//
//--------Operations--------//
//--------------------------//

/*----------push------------*/

void	push_stack(t_stack *src, t_stack *dest, t_op_count *op_count,
			char stk_name);

/*----------swap------------*/

void	swap_stack(t_stack *stk, t_op_count *op_count, char stk_name);
void	op_ss(t_stack *a, t_stack *b, t_op_count *op_count);

/*----------rotate----------*/

void	rotate_stack(t_stack *stk, t_op_count *op_count, char stk_name);
void	rrotate_stack(t_stack *stk, t_op_count *op_count,
			char stk_name);

/*----------more rotations----------*/

void	op_rr(t_stack *src, t_stack *dest, t_op_count *op_count);
void	op_rrr(t_stack *src, t_stack *dest, t_op_count *op_count);
void	op_pushall_a(t_stack *b, t_stack *a, t_op_count *op_count);

//--------------------------//
//--------Parsing-----------//
//--------------------------//

void	ft_args_check(char **argv);
void	valid_args(char **argv, size_t i);
char	**ft_separate_and_validate(char **argv);
void	ft_valid_array(char *array);
int		ft_dup_check(char **array, int size);
int		arr_count(char **array);
t_node	*parsing(char **argv, t_flags *flags);
size_t	ft_count_new_args(char **argv, size_t i);
char	**ft_split_all(char **argv, size_t arg_index, size_t count);

//--------------------------//
//-------Parsing_utils------//
//--------------------------//

int		ft_isoperator(char c);
int		ft_isspace(char c);
long	ft_atol(char *array);
char	**ft_split_whitespace(char const *s);
void	flag_bench(t_flags *flags, char **argv);
size_t	count_new_args(char **argv, size_t i);

//--------------------------//
//-----------stack_a--------//
//--------------------------//

t_node	*array_to_stk(char **array, size_t count);
bool	dup_check(t_node *stack_a);

//--------------------------//
//----------Flags-----------//
//--------------------------//

void	flag_check(t_flags *flags, char **argv);
void	flag_diff(t_flags *flags, char *arg);
bool	is_diff_flags(char *flag);
void	flag_bench(t_flags *flags, char **argv);
bool	is_bench_flags(char *flag);
int		count_flags(t_flags *flags);
//--------------------------//
//----------Bench-----------//
//--------------------------//

float	disorder(t_node *stack);
int		disorder_decimals(t_node *stack);
void	ft_resolve_strategy(t_flags *flag, float disorder);
void	output_bench(t_op_count *bench, t_flags *flags, float disorder);
int		operations_output(t_op_count *bench);

//--------------------------//
//----------Error-----------//
//--------------------------//

void	give_error(void);
void	ft_free_array(char **array, size_t size);
// void    free_list(t_node *node);

//--------------------------//
//----------Exit------------//
//--------------------------//

void	exit_array(char **array, size_t size);
void	exit_stack(t_stack *stack);

//--------------------------//
//--------algorithms--------//
//--------------------------//

void	stack_is_3(t_stack *a, t_op_count *op_count);
void	stack_is_5(t_stack *a, t_stack *b, t_op_count *op_count);
void	chunk_sort(t_stack *a, t_stack *b, t_op_count *op_count);
void	radix_sort(t_stack *a, t_stack *b, t_op_count *op_count);
void	ft_simple(t_stack *a, t_stack *b, t_op_count *op_count);

//--------------------------//
//-----------Utils----------//
//--------------------------//
int		stk_is_sorted(t_node *stack);
void	ft_push(t_stack *top, t_node *new);
t_node	*ft_pop(t_stack *top);
void	index_stack(t_stack *a);
t_node	*ft_find_min(t_node *a);
int		get_target_half(t_node *a, t_node *target);
int		ft_sqrt(int nb);
t_node	*ft_find_max(t_node *a);
t_node	*stk_dup(t_node *stk);

int		ft_isoperator(char c);

//--------------------------//
//-----------print_list-----//
//--------------------------//

void	ft_print_lst(t_node *top);

/*----------push_swap----------*/

void	push_swap(char **argv);

int		ft_abs(ssize_t num);

#endif