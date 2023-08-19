#include "./../libminishell.h"
void foo(void)
{
	// system("leaks cd");
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%s = %s** ",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

int main(int argc, char **argv, char **env)
{
    t_list	*lst;
	t_list	*tmp;
	t_list	*cmd;
	lst = NULL;
	cmd = NULL;
    t_list  *env_lst = NULL;

	atexit(foo);
    env_lst = convert_env_to_list(env);
	if (is_variable_exists("SHLVL", env_lst))
    {
		printf("the variable is exists\n");
		printf("shlvl= |%s|\n",get_variable_value("SHLVL", env_lst));
    }
	else
		printf("the variable not exists\n");

    update_shlvl(env_lst);
	if (is_variable_exists("SHLVL", env_lst))
    {
		printf("the variable is exists\n");
		printf("shlvl= |%s|\n",get_variable_value("SHLVL", env_lst));
    }
	else
		printf("the variable not exists\n");
	ft_lstclear(&env_lst, del);
	// ft_lstclear(&cmd, del);
	// ft_lstclear(&lst, del);
	// print_lst(cmd);
	// exit(88);
    return (0);
}