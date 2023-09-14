#include "./liberror.h"

void	print_error_permission(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	print_strerror_set_status(": Permission denied\n", 126);
}
