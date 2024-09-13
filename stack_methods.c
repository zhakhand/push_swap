/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:27 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/12 12:56:12 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int *nums, size_t len)
{
	t_stack	*new_stack;
	size_t	i;

	i = 0;
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		exit(error());
	new_stack->vals = malloc(sizeof(t_num*) * len);
	new_stack->sz = 0;
	if (!new_stack->vals)
		return (NULL);
	while (i < len && nums)
	{
		new_stack->vals[i] = malloc(sizeof(t_num));
		if (!new_stack->vals[i])
			return (NULL);
		new_stack->vals[i]->val = nums[i];
		new_stack->vals[i]->o_ind = i;
		new_stack->sz++;
		i++;
	}
	new_stack->max_sz = len;
	return (new_stack);
}

void	erase(t_stack **stack, size_t pos)
{
	size_t	i;
	t_num	**vals;

	i = 0;
	vals = malloc(sizeof(t_num*) * (*stack)->max_sz);
	if (!vals)
		exit (error());
	if (pos == 0)
	{
		while (i < (*stack)->sz - 1)
		{
			vals[i] = (*stack)->vals[i + 1];
			i++;
		}
	}
	else
	{
		while (i < pos)
		{
			vals[i] = (*stack)->vals[i];
			i++;
		}
	}
	free_nums(stack);
	(*stack)->vals = vals;
	(*stack)->sz--;
}

void	push_back(t_stack **stack, t_num *num)
{
	(*stack)->vals[(*stack)->sz++] = num;
}

void	push_front(t_stack **stack, t_num *num)
{
	t_num	**temp;
	size_t	i;
	size_t	j;

	temp = malloc(sizeof(t_num) * (*stack)->max_sz);
	if (!temp)
		return ;
	i = 1;
	j = 0;
	temp[0] = num;
	while (j < (*stack)->sz)
	{
		temp[i] = (*stack)->vals[j];
		i++;
		j++;
	}
	(*stack)->sz++;
	free_nums(stack);
	(*stack)->vals = temp;
}
