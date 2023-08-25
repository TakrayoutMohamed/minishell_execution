#include "./../libminishell.h"

void	close_pipe(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
	{
		print_error(errno);
		status = errno;
	}
	if (close(pipe_fd[1]) == -1)
	{
		print_error(errno);
		status = errno;
	}
}
