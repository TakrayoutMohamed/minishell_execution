#include "./../libminishell.h"

int	pipe_middle(t_list *lst, char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		return (ft_freematrix(argv), print_error(errno), errno);
	}
	else if (pid == 0) // this is child
	{
		dup2(lst->previous->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close_pipe(lst->pipe);
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	return (ft_freematrix(argv), status);
}
