/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:47 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/09 14:52:18 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

void	swap(t_stack **stack, int s)
{
	int	temp;

	if ((*stack)->sz >= 2)
	{
		temp = (*stack)->vals[0];
		(*stack)->vals[0] = (*stack)->vals[1];
		(*stack)->vals[1] = temp;
	}
	if (s == 1)
		ft_printf("sa\n");
	if (s == 2)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a , 0);
	swap(b, 0);
	ft_printf("ss\n");
}

void	push(t_stack **from, t_stack **to, int s)
{
	int	head;

	if ((*from)->sz > 0)
	{
		head = (*from)->vals[0];
		erase(from, 0);
		push_front(to, head);
	}
	if (s == 1)
		ft_printf("pa\n");
	if (s == 2)
		ft_printf("pb\n");
}

void	rotate(t_stack **stack, int s)
{
	int	head;

	if ((*stack)->sz >= 2)
	{
		head = (*stack)->vals[0];
		erase(stack, 0);
		push_back(stack, head);
	}
	if (s == 1)
		ft_printf("ra\n");
	if (s == 2)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}
