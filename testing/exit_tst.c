#include "./../libminishell.h"

void foo(void)
{
	system("leaks export");
}
int main(int argc, char **argv, char **env)
{
    t_list	*lst;
	t_list	*tmp;
	t_list	*cmd;
	lst = NULL;
	cmd = NULL;
    t_list  *env_lst;

	// atexit(foo);
    env_lst = convert_env_to_list(env);
	// tmp = ft_lstnew(ft_strdup("NULL"), ft_strdup("NULL"));
	// ft_lstadd_back(&lst, tmp);
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("exit")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-922")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-922")));


    exit_(cmd);
    // export(ft_lstnew(NULL, ft_strdup("export")), env_lst);
    // env_(env_lst);
	ft_lstclear(&env_lst, del);
	ft_lstclear(&cmd, del);
	// ft_lstclear(&lst, del);
    return (0);
}