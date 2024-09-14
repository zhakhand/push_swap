/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:29:32 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 15:26:44 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char	**arr)
{
	size_t	i;
	
	i = 0;
	while (arr[i] != 0)
	{
		if (ft_atoi(arr[i]) > INT_MAX || ft_atoi(arr[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

static int	is_num(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (arr[i][j] != 0)
		{
			if (arr[i][j] < 48 || arr[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_duplicates(char **arr)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (arr[i] != 0)
	{
		if (strncmp(arr[i], arr[j], ft_strlen(arr[j])) == 0)
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	is_valid_arg(char **split_arg)
{
	if (has_duplicates(split_arg))
		return (0);
	if (!is_num(split_arg))
		return (0);
	if (!is_int(split_arg))
		return (0);
	return (1);
}