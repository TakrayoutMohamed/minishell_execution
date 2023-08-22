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
	return (EXIT_SUCCESS);
}
