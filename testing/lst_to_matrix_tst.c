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
		printf("**%s = %s** \n",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

void	print_matrix(char **matrix)
{
	int	i = 0;
	int j;

	ft_putchar_fd('{', 1);
	while (matrix[i])
	{
		j = 0;
		ft_putchar_fd('[', 1);
		ft_putstr_fd(matrix[i], 1);
		ft_putchar_fd(']', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

int main(int argc, char **argv, char **env)
{
    char **matrix = NULL;
    t_list  *env_lst = NULL;

    env_lst = convert_env_to_list(env);
    // print_lst(env_lst);
    // printf("\n****************the first matrix**********************\n");
    // print_matrix(env);
	// exit(0);
    // printf("\n****************end the first matrix**********************\n");
    printf("\n****************the second matrix**********************\n");
    matrix = convert_list_to_matrix(env_lst);

    // print_matrix(matrix);
    printf("\n****************end the second matrix**********************\n");
	// ft_putstr_fd("here sig befor freematrix\n", 1);
    ft_freematrix(matrix);
	ft_lstclear(&env_lst, del);
	// exit(88);
    return (0);
}