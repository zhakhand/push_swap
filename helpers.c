/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:27:38 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:02 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_size(int *nums)
{
	return (sizeof(nums)/sizeof(nums[0]));
}

int	is_sorted(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->sz - 1)
	{
		if (a->vals[i] > a->vals[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int		min;
	size_t	i;
	size_t	offset;

	min = a->vals[0];
	i = 1;
	offset = 0;
	while (i < a->sz)
	{
		if (min > a->vals[i])
			min = a->vals[i];
		i++; 
	}
	while (offset < a->sz)
	{
		if (a->vals[offset] == min)
			break ;
		offset++;
	}
	return (offset);
}

int	error(void)
{
	ft_printf("Error\n");
	return (0);
}