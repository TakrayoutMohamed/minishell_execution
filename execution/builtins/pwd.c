#include "./../../libminishell.h"

void	pwd(t_list *env)
{
	ft_putstr_fd(get_variable_value("PWD", env), 1);
}
