/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:14:55 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 14:29:08 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->vals[0]->val > (*a)->vals[1]->val)
	{
		swap(&(*a), 1);
	}
}

void	sort_three(t_stack **a)
{
	int	min;

	min = find_min(*a);
	if (min == 0)
	{
		reverse_rot(&(*a), 1);
		swap(&(*a), 1);
	}
	if (min == 1)
	{
		if ((*a)->vals[0]->val > (*a)->vals[2]->val)
			rotate(&(*a), 1);
		else if ((*a)->vals[2]->val > (*a)->vals[0]->val)
			swap(&(*a), 1);
	}
	if (min == 2)
	{
		if ((*a)->vals[0]->val > (*a)->vals[1]->val)
		{
			swap(&(*a), 1);
			reverse_rot(&(*a), 1);
		}
		else
			reverse_rot(&(*a), 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	if (min == 1)
		swap(&(*a), 1);
	if (min == 2)
	{
		rotate(&(*a), 1);
		swap(&(*a), 1);
	}
	if (min == 3)
		reverse_rot(&(*a), 1);
	push(&(*a), &(*b), 2);
	sort_three(&(*a));
	push(&(*b), &(*a), 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	
	min = find_min(*a);
	if (min == 1)
		rotate(&(*a), 1);
	else if (min == 2)
	{
		rotate(&(*a), 1);
		rotate(&(*a), 1);
	}
	else if (min == 3)
	{
		reverse_rot(&(*a), 1);
		reverse_rot(&(*a), 1);
	}
	else if (min == 4)
		reverse_rot(&(*a), 1);
	push(&(*a), &(*b), 2);
	sort_four(&(*a), &(*b));
	push(&(*b), &(*a), 1);
}

// void	sort_any(t_stack **a, t_stack **b)
// {
	
// }
