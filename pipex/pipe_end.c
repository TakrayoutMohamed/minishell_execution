#include "./../libminishell.h"

int	pipe_end(t_list *lst, char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (print_error(errno), errno);
	else if (pid == 0)
	{
		if (lst->previous != NULL)
		{
			dup2(lst->previous->pipe[0], 0);
			close(lst->previous->pipe[0]);
		}
		dup2(lst->pipe[1], 1);
		close(lst->pipe[1]);
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	close(lst->pipe[1]);
	waitpid(pid, &status, WUNTRACED);
	if (read_from_fd(lst->pipe[0]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
