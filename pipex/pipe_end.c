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
		t_stats.status = errno;
		exit(t_stats.status);
	}
	close(lst->pipe[1]);
	t_stats.flag_sigint = 1;
	waitpid(pid, &(t_stats.status), 0);
	t_stats.flag_sigint = 0;
	if (t_stats.status == 0)
		read_from_fd(lst->pipe[0]);
	return (t_stats.status);
}
