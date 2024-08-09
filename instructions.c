/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:14:55 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/09 14:56:54 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->vals[0] > (*a)->vals[1])
	{
		swap(a, 1);
	}
}

void	sort_three(t_stack **a)
{
	int	min;

	min = find_min(*a);
	if (min == 0)
	{
		reverse_rot(a, 1);
		swap(a, 1);
	}
	if (min == 1)
	{
		if ((*a)->vals[0] > (*a)->vals[2])
			rotate(a, 1);
		if ((*a)->vals[2] > (*a)->vals[0])
			swap(a, 1);
	}
	if (min == 2)
	{
		if ((*a)->vals[0] > (*a)->vals[1])
		{
			swap(a, 1);
			reverse_rot(a, 1);
		}
		else
			reverse_rot(a, 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	if (min == 1)
		swap(a, 1);
	if (min == 2)
	{
		rotate(a, 1);
		swap(a, 1);
	}
	if (min == 3)
		reverse_rot(a, 1);
	push(a, b, 2);
	sort_three(a);
	push(b, a, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push(a, b, 2);
	push(a, b, 2);
	sort_three(a);
	while((*b)->sz > 0)
	{
		push(b, a, 1);
		if ((*a)->vals[0] > (*a)->vals[3])
			rotate(a, 1);
		if ((*a)->vals[0] < (*a)->vals[2] && (*a)->vals[0] > (*a)->vals[1])
			swap(a, 1);
		if ((*a)->vals[0] > (*a)->vals[2] && (*a)->vals[0] < (*a)->vals[3])
		{
			swap(a, 1);
			rotate(a, 1);
			swap(a, 1);
			reverse_rot(a, 1);
		}
	}
}
