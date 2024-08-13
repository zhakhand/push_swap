/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:37:39 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/12 12:46:19 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

void	reverse_rot(t_stack **stack, int s)
{
	int	tail;

	if ((*stack)->sz > 1)
	{
		tail = (*stack)->vals[(*stack)->sz - 1];
		erase(&(*stack), (*stack)->sz - 1);
		push_front(&(*stack), tail);
	}
	if (s == 1)
		ft_printf("rra\n");
	if (s == 2)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rot(&(*a), 0);
	reverse_rot(&(*b), 0);
	ft_printf("rrr\n");
}
