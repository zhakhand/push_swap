#include "push_swap.h"

t_chunks	*create_info(t_stack **stack)
{
	t_chunks	*info;

	info = malloc(sizeof(t_chunks));
	if (!info)
		return (NULL);
	if ((*stack)->sz <= 10)
		info->chunks = 5;
	else if ((*stack)->sz <= 150)
		info->chunks = 8;
	else
		info->chunks = 18;
	info->ch_size = (*stack)->sz / info->chunks;
	info->mid = (*stack)->sz / 2;
	info->up = info->mid + info->ch_size;
	info->low = info->mid - info->ch_size;
	return (info);
}