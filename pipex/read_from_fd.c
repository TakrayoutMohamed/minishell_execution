#include "./../libminishell.h"

int	read_from_fd(int fd)
{
	int		numRead;
	char	buf;

	while (1)
	{
		numRead = read(fd, &buf, 1);
		if (numRead == -1)
		{
			status = errno;
			return (print_error(errno), errno);
		}
		if (numRead == 0)
		{
			break ;
		}
		if (write (1, &buf, numRead) != numRead)
		{
			status = errno;
			return (print_error(errno), errno);
		}
	}
	status = 0;
	return (EXIT_SUCCESS);
}
