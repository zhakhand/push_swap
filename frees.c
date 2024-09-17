#include "push_swap.h"

void	free_nums(t_stack **stack)
{
	if (stack && *stack)
	{
		free((*stack)->vals);
		(*stack)->vals = NULL;
	}
}

void	free_struct(t_stack **stack)
{
	if (stack && *stack)
	{
		free(*stack);
		stack = NULL;
	}
}

void	free_all(t_stack **stack)
{
	free_nums(stack);
	free_struct(stack);
}

void	free_arr(char **array, int i)
{
	if (array && *array)
	{
		while (i > 0)
		{
			i--;
			free(*(array + i));
		}
		free(array);
	}
}
