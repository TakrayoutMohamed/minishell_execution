#include "./../libminishell.h"
void foo(void)
{
	system("leaks execution_lst");
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
	t_list	*cmd, *cmd1, *cmd2;
	lst = NULL;
	cmd = NULL;
	cmd1 = NULL;
	cmd2 = NULL;
    t_list  *env_lst = NULL;

	atexit(foo);
    env_lst = convert_env_to_list(env);

	ft_lstadd_back(&lst, ft_lstnew(NULL, NULL));
	lst->infile =-2;
	lst->outfile =-2;
	// ft_lstadd_back(&lst, ft_lstnew(NULL, NULL));
	// ft_lstlast(lst)->infile =-2;
	// ft_lstlast(lst)->outfile =-2;
	// ft_lstadd_back(&lst, ft_lstnew(NULL, NULL));
	// ft_lstlast(lst)->infile =-2;
	// ft_lstlast(lst)->outfile =-2;

	/*the first command*/
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("fadsfads")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("fadsfad")));
	ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("fadsfas")));
	lst->cmd = cmd;

	// /*the second command*/
	// ft_lstadd_back(&cmd1, ft_lstnew(NULL, ft_strdup("env")));
	// // ft_lstadd_back(&cmd1, ft_lstnew(NULL, ft_strdup("PWD")));
	// // ft_lstadd_back(&cmd1, ft_lstnew(NULL, ft_strdup("-a")));
	// lst->next->cmd = cmd1;

	// /*the third command*/
	// ft_lstadd_back(&cmd2, ft_lstnew(NULL, ft_strdup("grep")));
	// ft_lstadd_back(&cmd2, ft_lstnew(NULL, ft_strdup("PWD")));
	// // ft_lstadd_back(&cmd2, ft_lstnew(NULL, ft_strdup("-a")));
	// ft_lstlast(lst)->cmd = cmd2;
	tmp = lst;

   execute_list(lst, &env_lst);
	// fprintf(stderr,"here is \n");


	ft_lstclear(&cmd, del);
	ft_lstclear(&cmd1, del);
	ft_lstclear(&cmd2, del);
	ft_lstclear(&tmp, del);
	ft_lstclear(&env_lst, del);
    return (0);
}