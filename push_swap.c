/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:47:09 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/09 14:54:41 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a)
{
	t_stack *b;
	size_t	i;
	
	i = 0;
	b = init_stack(NULL, (*a)->sz);
	if (!b)
		exit(1);
	if ((*a)->sz == 2)
		sort_two(a);
	if ((*a)->sz == 3)
		sort_three(a);
	if ((*a)->sz == 4)
		sort_four(a, &b);
	if ((*a)->sz == 5)
		sort_five(a, &b);
	while (i < (*a)->sz)
		ft_printf("| %d |\n", (*a)->vals[i++]);
}

int	main(int ac, char **av)
{
	int	*nums;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = ac-1;
	nums = malloc(len);
	if (!nums)
		return (1);
	while (i < len)
	{
		nums[i] = ft_atoi(av[j]);
		i++;
		j++;
	}
	t_stack *a = init_stack(nums, len);
	if (!a)
		return (1);
	if (is_sorted(a))
		return (0);
	push_swap(&a);
}