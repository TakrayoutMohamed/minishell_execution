#include "./../libminishell.h"

static void	pipe_builtins_infile(t_list *lst)
{
	if (lst->infile >= 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else if (lst->previous != NULL)
	{
		dup2(lst->previous->pipe[0], 0);
		close(lst->previous->pipe[0]);
	}
}

static void	pipe_builtins_outfile(t_list *lst)
{
	if (lst->outfile >= 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else
	{
		// dup2(lst->pipe[1], 1);
		close(lst->pipe[1]);
	}
}

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
	return (EXIT_FAILURE);
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

	pid = fork();
	if (pid == -1)
		return (print_error(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		pipe_builtins_infile(lst);
		pipe_builtins_outfile(lst);
		t_stats.status = execut_output_builtins(lst->cmd, env);
		ft_lstclearall(lst);
		ft_lstclear(&env, del);
		exit (t_stats.status);
	}
	close(lst->pipe[1]);
	waitpid(pid, &(t_stats.status), WUNTRACED);
	return (t_stats.status);
}
