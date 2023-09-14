#include "./liberror.h"

void	print_error_notfound(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	print_strerror_set_status(": command not found\n", 127);
}
