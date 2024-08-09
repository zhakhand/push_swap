/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:27 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/09 14:51:50 by dzhakhan         ###   ########.fr       */
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
	ft_bzero(new_stack->vals, len);
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
	int		*temp;
	size_t	i;
	size_t	j;

	temp = malloc((*stack)->max_sz);
	if (!temp)
		return ;
	i = 0;
	j = 0;
	while (i < (*stack)->sz - 1)
	{
		if (i != pos)
			temp[j++] = (*stack)->vals[i];
		i++;
	}
	ft_free(&(*stack)->vals);
	(*stack)->vals = temp;
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
	while (i < (*stack)->sz)
		temp[i++] = (*stack)->vals[j++];
	(*stack)->sz++;
	ft_free(&(*stack)->vals);
	(*stack)->vals = temp;
}
