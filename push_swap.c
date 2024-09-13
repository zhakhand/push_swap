/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:47:09 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:37 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a)
{
	t_stack *b;
	size_t	i;
	
	i = 0;
	if (is_sorted(*a))
		exit(error());
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
	free_nums(&b);
	free_struct(&b);
	while (i < (*a)->sz)
	{
		ft_printf("| %d |\n", (*a)->vals[i]->val);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		*nums;
	size_t	arr_size;
	t_stack	*a;

	a = NULL;
	nums = NULL;
	if (ac < 2)
		return error();
	if (ac == 2)
	{
		arr_size = word_count(av[1]);
		nums = split_n_fill(av[1], arr_size);
	}
	else if (ac > 2)
	{
		arr_size = ac - 1;
		nums = fill(av, ac - 1);
	}
	if (!nums)
		return error();
	a = init_stack(nums, arr_size);
	if (!a)
		return (free_all(&a), error());
	ft_free(&nums);
	push_swap(&a);
	free_nums(&a);
	free_struct(&a);
	return (0);
}
