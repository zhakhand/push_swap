/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:19 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:19 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_num
{
	int		val;
	size_t	o_ind;
	size_t	t_ind;
}				t_num;

typedef struct s_stack
{
	t_num	**vals;
	size_t	sz;
	size_t	max_sz;
}				t_stack;

typedef struct s_chunks
{
	size_t	sz;
	size_t	chunks;
	size_t	ch_size;
	size_t	up;
	size_t	mid;
	size_t	low;
}				t_chunks;


typedef struct s_comms
{
	char	*command;
	struct s_comms	*next_cmd;
}				t_comms;

typedef struct s_structs
{
	t_stack		*a;
	t_stack		*b;
	t_chunks	*info;
	t_comms		*cmds;
}				t_structs;


//stack methods
t_stack	*init_stack(int *nums, size_t len);
void	erase(t_stack **stack, size_t pos);
void	push_back(t_stack **stack, t_num *num);
void	push_front(t_stack **stack, t_num *num);
//actions
void	swap(t_structs **all, int s);
void	ss(t_structs **all);
void	push(t_structs **all, int s);
void	rotate(t_structs **all, int s);
void	rr(t_structs **all);
void	reverse_rot(t_structs **all, int s);
void	rrr(t_structs **all);

void	push_swap(t_structs **all);
void	sort_two(t_structs **all);
void	sort_three(t_structs **all);
void	sort_four(t_structs **all);
void	sort_five(t_structs **all);
void	sort_any(t_stack **a);
void	sort_that_shi(t_structs **all);
/*HELPERS*/
int		is_sorted(t_stack *a);
int		find_min(t_stack *a);
int		is_valid_arg(char **split_arg);
int		error(void);
int		*split_n_fill(char	*arg, size_t sz);
int		*fill(char **arg, int len);
size_t	word_count(char *av);
void	free_nums(t_stack **stack);
void	free_struct(t_stack **stack);
void	free_all(t_stack **stack);
int		has_duplicates(char **arr);

t_chunks	*create_info(t_stack **stack);
void	add_cmd(t_comms **cmds, char *cmd);
void	print_cmds(t_comms **cmds);
#endif