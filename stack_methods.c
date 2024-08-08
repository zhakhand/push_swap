/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:27 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/08 15:37:03 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_stack	*init_stack(int *nums, size_t len)
{
	t_stack	*new_stack;
	
	new_stack->vals = malloc(len + 1);
	if (!new_stack->vals)
		return NULL;
	new_stack->max_sz = len;
	new_stack->sz = 0;
	while (new_stack->sz < len)
		new_stack->vals[new_stack->sz++] = *nums++;
	return new_stack;
}

void	erase(t_stack *stack, int pos)
{
	int		*temp;
	size_t	i;
	size_t	j;
	
	temp = malloc(stack->max_sz);
	if (!temp)
		return ;
	i = 0;
	j = 0;
	while (i < stack->sz - 1)
	{
		if (i != pos)
			temp[j++] = stack->vals[i];
		i++;
	}
	ft_free(&stack->vals);
	stack->vals = temp;
	stack->sz--;
}

void	push_back(t_stack *stack, int num)
{
	stack->vals[stack->sz++] = num;
}

void	push_front(t_stack *stack, int num)
{
	int		*temp;
	size_t	i;

	temp = malloc(stack->max_sz);
	if (!temp)
		return ;
	i = 0;
	temp[0] = num;
	while (i < stack->sz)
		temp[i + 1] = stack->vals[i++];
	stack->sz++;
	ft_free(&stack->vals);
	stack->vals = temp;
}