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

#include "container.h"

t_stack	*init_stack(int *nums, size_t len)
{
	t_stack	*new_stack;
	size_t	i;

	i = 0;
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->vals = malloc(len);
	if (!new_stack->vals)
		return (NULL);
	new_stack->max_sz = len;
	new_stack->sz = 0;
	if (nums && *nums)
	{
		while (new_stack->sz < len)
			new_stack->vals[new_stack->sz++] = nums[i++];
	}
	return (new_stack);
}

void	erase(t_stack **stack, size_t pos)
{
	size_t	i;

	i = 0;
	if (pos == 0)
	{
		while (i < (*stack)->sz - 1)
		{
			(*stack)->vals[i] = (*stack)->vals[i + 1];
			i++;
		}
	}
	(*stack)->sz--;
}

void	push_back(t_stack **stack, int num)
{
	(*stack)->vals[(*stack)->sz++] = num;
}

void	push_front(t_stack **stack, int num)
{
	int		*temp;
	size_t	i;
	size_t	j;

	temp = malloc((*stack)->max_sz);
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
	ft_free(&(*stack)->vals);
	(*stack)->vals = temp;
}
