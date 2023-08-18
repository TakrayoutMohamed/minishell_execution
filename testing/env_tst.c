#include "./../libminishell.h"

void foo(void)
{
	system("leaks env");
}

int main(int argc, char **argv, char **env)
{
    t_list	*lst;
	t_list	*tmp;
	t_list	*cmd;
	atexit(foo);
	lst = NULL;
	cmd = NULL;
    t_list  *env_lst;

    env_lst = convert_env_to_list(env);
	// tmp = ft_lstnew("NULL", "NULL");
	// ft_lstadd_back(&lst, tmp);
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, "env"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, ""));
	// ft_lstadd_back(&lst, cmd);
	// lst->cmd = cmd;
    env_(env_lst);
	ft_lstclear(&env_lst,del);
    return (0);
}