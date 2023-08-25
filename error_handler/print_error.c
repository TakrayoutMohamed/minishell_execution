#include "./liberror.h"

void	print_error(int error_nbr)
{
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(error_nbr), 2);
	ft_putstr_fd("\n", 2);
}
