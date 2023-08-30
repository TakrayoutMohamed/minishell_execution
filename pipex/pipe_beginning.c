#include "./../libminishell.h"

static void	pipe_beginning_infile(t_list *lst)
{
	if (lst->infile >= 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else
	{
		dup2(lst->pipe[0], 0);
		close(lst->pipe[0]);
	}
}

static void	pipe_beginning_outfile(t_list *lst)
{
	if (lst->outfile >= 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else
	{
		dup2(lst->pipe[1], 1);
		close(lst->pipe[1]);
	}
}

int	pipe_beginning(t_list *lst, char **argv, char **envp)
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
		pipe_beginning_infile(lst);
		pipe_beginning_outfile(lst);
		execve(argv[0], argv, envp);
		status = errno;
		exit(status);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	return (status);
}
