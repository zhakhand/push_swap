#include "push_swap.h"

void	add_cmd(t_comms **cmds, char *cmd)
{
	t_comms	*com;
	t_comms	*curr;

	if (!cmd)
		return ;
	com = malloc(sizeof(t_comms));
	if (!com)
		return ;
	com->command = cmd;
	com->next_cmd = NULL;
	if (!com->command)
		return ;
	if (!cmds || !(*cmds))
		*cmds = com;
	else
	{
		curr = *cmds;
		while (curr && curr->next_cmd)
			curr = curr->next_cmd;
		curr->next_cmd = com;
	}
}

void	print_cmds(t_comms **cmds)
{
	t_comms	*curr;
	t_comms	*to_free;

	curr = NULL;
	to_free = NULL;
	if (!cmds || !(*cmds))
		return ;
	curr = *cmds;
	while (curr)
	{
		ft_printf("%s", curr->command);
		to_free = curr;
		curr = curr->next_cmd;
		free(to_free);
	}
}