#include "./../../libminishell.h"

int	open_the_right_fds(t_list *lst)
{
	if (lst->cmd != NULL)
	{		
		if (lst->previous != NULL)
		{
			dup2(lst->previous->pipe[0], 0);
			close_pipe(lst->previous->pipe);
		}
		if (lst->next != NULL)
		{
			dup2(lst->pipe[1], 1);
			close_pipe(lst->pipe);
		}
		if (lst->previous != NULL && lst->next != NULL)
		{
			dup2(lst->previous->pipe[0], 0);
			close_pipe(lst->previous->pipe);
			dup2(lst->pipe[1], 1);
			close_pipe(lst->pipe);
		}
	}
	return (EXIT_SUCCESS);
}

/*execute one of the builtind depending on the first lst node's value*/
void	builtins(t_list *lst ,t_list *env, int position)
{
	char	**matrix;
	char	*path;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	if (lst_cmd != NULL)
		open_the_right_fds(lst);
	if (is_env(lst_cmd->value))
		env_(env);
	else if (is_cd(lst_cmd->value))
	{
		cd(lst_cmd, env);
		env_(env);

	}
	else if (is_export(lst_cmd->value))
	{
		export(lst_cmd, env);
	}
}
