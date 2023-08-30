#include "./../libminishell.h"

static void	pipe_end_infile(t_list *lst)
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

static void	pipe_end_outfile(t_list *lst)
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

int	pipe_end(t_list *lst, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (print_error(errno), errno);
	else if (pid == 0)
	{
		pipe_end_infile(lst);
		pipe_end_outfile(lst);
		execve(argv[0], argv, envp);
		status = errno;
		exit(status);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	if (read_from_fd(lst->pipe[0]) != EXIT_SUCCESS)
		return (status);
	return (status);
}
