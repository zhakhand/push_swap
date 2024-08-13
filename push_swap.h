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

# include "container.h"

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
int		*split_n_fill(char	*arg);
int		*fill(char **arg, int len);
int		arr_size(int *nums);

#endif