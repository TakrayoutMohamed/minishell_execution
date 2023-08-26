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
		printf("|%s|\n",lst->value);
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
    char str[] = "ls,-la,-a";
    char **matrix = ft_split(str, ',');
    t_list  *lst;
    // print_lst(env_lst);
    printf("\n****************the first matrix**********************\n");
    print_matrix(matrix);
	// exit(0);
    printf("\n****************end the first matrix**********************\n");
    printf("\n****************the list**********************\n");
	// ft_putstr_fd("here sig befor freematrix\n", 1);
    lst = convert_matrix_to_list(matrix);
    
    print_lst(lst);
    printf("\n****************end the list**********************\n");
    ft_freematrix(matrix);
	ft_lstclear(&lst, del);
	// exit(88);
    return (0);
}