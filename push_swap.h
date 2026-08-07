/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:57:38 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/07 09:31:20 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft_pushswap/libft.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

//--------------------------//
//--------Structs-----------//
//--------------------------//

typedef struct s_ops
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total_ops;
}              t_ops;

typedef enum e_flags
{
	DIFF_ADAPTIVE,
	DIFF_SIMPLE,
	DIFF_MEDIUM,
	DIFF_COMPLEX
    
}	e_diff;

typedef struct s_flags
{
	bool    has_bench;
	bool	has_diff;
	e_diff difficulty;
}	t_flags;


//--------------------------//
//--------Operations--------//
//--------------------------//

void    ft_sstack(t_node *stack);
void    ft_ss(t_node *stack_a, t_node *stack_b);
void    ft_pstack(t_node *stack_1, t_node *stack_2);
void    ft_rstack(t_node *stack);
void    ft_rr(t_node *stack_a, t_node *stack_b);
void    ft_rrstack(t_node *stack);
void    ft_rrr(t_node *stack_a, t_node *stack_b);

//--------------------------//
//--------Parsing-----------//
//--------------------------//

void	ft_valid_args(char **argv, size_t   i);
void	ft_valid_flag(char **argv);
t_list	*ft_parsing(char **argv);

//--------------------------//
//-------Parsing_utils------//
//--------------------------//

size_t	ft_count_args(const char *arg);
size_t	ft_count_new_args(char **argv, size_t	i);
int		ft_isoperator(char c);
int		ft_isspace(char c);
long int	ft_atol(char *array);

//--------------------------//
//-------Parsing_split------//
//--------------------------//

size_t	ft_split_arg(char **array, char *arg, size_t size);
char	**ft_split_all(char **argv, size_t arg_index, size_t count);

//--------------------------//
//----------Flags-----------//
//--------------------------//

void	ft_flag_check(t_flags *flags, char **argv);
void 	ft_flag_diff(t_flags *flags, char *arg);
bool	ft_is_diff_flags(char *flag);
void	ft_flag_bench(t_flags *flags, char **argv);
bool	ft_is_bench_flags(char *flag);
int		ft_count_flags(t_flags *flags);

//--------------------------//
//----------Error-----------//
//--------------------------//

void    ft_give_error(void);
void	ft_free_array(char **array, int size);
void	ft_exit_array(char **array, int size);
void    ft_free_stack(t_list **stack);
void	ft_exit_stack(t_list **stack);

//--------------------------//
//---------Stack_a----------//
//--------------------------//

t_list	*ft_array_to_stack(char **array);
bool	ft_integer_check(t_list *stack_a);

//--------------------------//
//---------Output-----------//
//--------------------------//

float	ft_disorder(t_node *stack);
e_diff	ft_resolve_strategy(float disorder);
void	ft_print_bench(t_ops *bench, t_flags *flags, float disorder);
void	ft_output(t_node *stack, t_ops *bench, t_flags *flags);


#endif