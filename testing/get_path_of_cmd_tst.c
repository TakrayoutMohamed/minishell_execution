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
	// tmp = ft_lstnew(ft_strdup("NULL"), ft_strdup("NULL"));
	// ft_lstadd_back(&lst, tmp);
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, ft_strdup("cd")));
    char *path = get_path_of_cmd(env_lst, "clear");
    printf("the path of the cmd ls=|%s|",path);
    // env_(env_lst);
    free(path);
	ft_lstclear(&env_lst, del);
	// ft_lstclear(&cmd, del);
	// ft_lstclear(&lst, del);
	// print_lst(cmd);
	exit(errno);
    return (0);
}