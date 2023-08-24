#include "./../libminishell.h"

static int	execut_output_builtins(t_list *lst_cmd, t_list *env)
{
	if (is_echo(lst_cmd->value))
	{
		return (echo(lst_cmd));
	}
	if (is_env(lst_cmd->value))
		return (env_(env), EXIT_SUCCESS);
	if (is_export(lst_cmd->value) && ft_lstsize(lst_cmd) == 1)
		return (export(lst_cmd, env), EXIT_SUCCESS);
	if (is_pwd(lst_cmd->value))
		return (pwd(), EXIT_SUCCESS);
	return (false);
}

int	pipe_builtins(t_list *lst, t_list *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (lst->next != NULL)
		{
			dup2(lst->pipe[0], 0);
			dup2(lst->pipe[1], 1);
			close_pipe(lst->pipe);
		}
		exit(execut_output_builtins(lst->cmd, env));
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	return (status);
}
