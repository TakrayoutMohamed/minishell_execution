#include "./../libminishell.h"

int	pipe_beginning(t_list *lst, char **argv)
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
		dup2(lst->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close_pipe(lst->pipe);
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	return (status);
}
