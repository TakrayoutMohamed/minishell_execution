#include "./../libminishell.h"

void	print_strerror_set_status(char *strerr, int status)
{
	ft_putstr_fd(strerr, 2);
	t_stats.status = status;
}
