#include "./../libminishell.h"
void foo(void)
{
	system("leaks echo");
}

// void	print_lst(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (lst != NULL)
// 	{
// 		printf("**%s = %s** ",lst->key, lst->value);
// 		lst = lst->next;
// 	}
// 	lst = tmp;
// 	printf("\n");
// }

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

	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("echo")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-n")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-ns")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-nnnnnnn")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-nn")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("-nm")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("hello all")));
	// ft_lstlast(cmd)->next = NULL;
	// lst->cmd = cmd;
    echo(cmd->next);
	// ft_lstclear(&cmd, del);
    // export(ft_lstnew(NULL, ft_strdup("export")), env_lst);
    // env_(env_lst);
	ft_lstclear(&env_lst, del);
	ft_lstclear(&cmd, del);
	// ft_lstclear(&lst, del);
	// print_lst(cmd);
	// exit(88);
    return (0);
}