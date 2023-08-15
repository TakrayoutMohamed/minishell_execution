#include "./../libminishell.h"

/*this function read from a fd_in's content and write it to fd_out*/
void	write_to_fd(t_list *lst)
{
	int		fd_out;
	int		numRead;
	char	buf[20];

	fd_out = open(lst->file->file_out, O_CREAT | O_WRONLY, 0644);
	dup2(lst->previous->pipe[0], 0);
	dup2(fd_out, 1);
	close_pipe(lst->previous->pipe);
	close(fd_out);
	if (fd_out == -1)
	{
		print_error(errno);
		exit(errno);
	}
	while (1)
	{
		numRead = read(0, buf, 20);
		if (numRead == -1)
		{
			fprintf(stderr,"error in read from pfd[0] end");
			exit(4);
		}
		if (numRead == 0)
		{
			fprintf(stderr,"EOFend!\n");
			break ;
		}
		if (write (1, buf, numRead) != numRead)
		{
			printf("child - partial/failed write \n");
			exit (5);
		}
	}
}