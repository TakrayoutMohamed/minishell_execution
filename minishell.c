#include "libminishell.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%s = %s** \n",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
	// printf("\n");
}

int main(int argc, char **argv, char **env)
{
    t_list  *lst;

    lst = convert_env_to_list(env);
    print_lst(lst);
    exit(44);
    prompt(argc, argv, env);
    return (0);
}