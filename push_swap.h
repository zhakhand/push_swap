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

//stack methods
t_stack	*init_stack(int *nums, size_t len);
void	erase(t_stack **stack, size_t pos);
void	push_back(t_stack **stack, t_num *num);
void	push_front(t_stack **stack, t_num *num);
//actions
void	swap(t_stack **stack, int s);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **from, t_stack **to, int s);
void	rotate(t_stack **stack, int s);
void	rr(t_stack **a, t_stack **b);
void	reverse_rot(t_stack **stack, int s);
void	rrr(t_stack **a, t_stack **b);

void	push_swap(t_stack **a);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_any(t_stack **a);
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
int	has_duplicates(char **arr);

#endif