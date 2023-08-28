#include "./../libminishell.h"

static int	execut_output_builtins(t_list *cmd_lst, t_list *env)
{
	if (is_echo(cmd_lst->value))
	{
		return (echo(cmd_lst));
	}
	if (is_env(cmd_lst->value))
		return (env_(env), EXIT_SUCCESS);
	if (is_export(cmd_lst->value) && ft_lstsize(cmd_lst) == 1)
		return (export(cmd_lst, env), EXIT_SUCCESS);
	if (is_pwd(cmd_lst->value))
		return (pwd(), EXIT_SUCCESS);
	return (false);
}

void	ft_lstclearall(t_list *lst)
{
	t_list	*tmp;

	while (lst->previous != NULL)
		lst = lst->previous;
	tmp = lst;
	while (tmp)
	{
		ft_lstclear(&(tmp->cmd), del);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
}

int	pipe_builtins(t_list *lst, t_list *env)
{
	pid_t	pid;
	int		result;

	pid = fork();
	if (pid == -1)
		return (print_error(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		if (lst->next != NULL)
		{
			dup2(lst->pipe[0], 0);
			dup2(lst->pipe[1], 1);
			close_pipe(lst->pipe);
		}
		result = execut_output_builtins(lst->cmd, env);
		ft_lstclearall(lst);
		ft_lstclear(&env, del);
		exit (status);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	return (status);
}
