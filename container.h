/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:50:17 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/08 14:15:15 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*vals;
	size_t	sz;
	size_t	max_sz;
}				t_stack;

//stack methods
t_stack	*init_stack(int *nums, size_t len);
void	erase(t_stack *stack, int pos);
void	push_back(t_stack *stack, int num);
void	push_front(t_stack *stack, int num);
//actions
void	swap(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	reverse_rot(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

#endif