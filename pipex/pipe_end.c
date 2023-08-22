#include "./../libminishell.h"

int	pipe_end(t_list *lst, char **argv)
{
	pid_t	pid;
	int		numRead;
	char	buf;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		return (errno);
	}
	else if (pid == 0) // this is child
	{
		dup2(lst->previous->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close(lst->pipe[1]);
		close(lst->previous->pipe[0]);
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
		while (1)
		{
			numRead = read(lst->pipe[0], &buf, 1);
			if (numRead == -1)
			{
				print_error(errno);
				return (errno);
			}
			if (numRead == 0)
			{
				break ;
			}
			if (write (1, &buf, numRead) != numRead)
			{
				print_error(errno);
				return (errno);
			}
		}

	}
	return (EXIT_SUCCESS);
}