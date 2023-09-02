#include "./../libminishell.h"

int	read_from_fd(int fd)
{
	int		numread;
	char	buf;

	while (1)
	{
		numread = read(fd, &buf, 1);
		if (numread == -1)
		{
			t_stats.status = errno;
			return (print_error(errno), errno);
		}
		if (numread == 0)
		{
			break ;
		}
		if (write (1, &buf, numread) != numread)
		{
			t_stats.status = errno;
			return (print_error(errno), errno);
		}
	}
	return (EXIT_SUCCESS);
}
