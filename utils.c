/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:50:11 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:12:54 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char	*str)
{
	while (str && *str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	*split_n_fill(char *arg, size_t sz)
{
	char	**split_arg;
	int		*nums;
	size_t	i;

	i = 0;
	split_arg = ft_split(arg, ' ');
	if (!split_arg || !is_valid_arg(split_arg))
		return (NULL);
	nums = malloc(sz);
	if (!nums)
		return (NULL);
	while (split_arg[i] != 0)
	{
		nums[i] = ft_atoi(split_arg[i]);
		i++;
	}
	free(split_arg);
	return (nums);
}

int	*fill(char **arg, int len)
{
	int		*nums;
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 1;
	nums = malloc(sizeof(int) * len);
	if (has_duplicates(arg))
		return (NULL);
	if (!nums)
		return (NULL);
	while (i < len)
	{
		if (!is_num(arg[j]))
			return (NULL);
		num = ft_atoi(arg[j]);
		nums[i] = num;
		i++;
		j++;
	}
	return (nums);	
}

size_t	word_count(char *av)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (av[i + 1] != '\0')
	{
		if ((av[i] == 32) && (av[i + 1] != 32 && av[i + 1] != 0))
			count++;
		i++;
	}
	return (count);
}
