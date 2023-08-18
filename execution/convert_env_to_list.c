#include "./../libminishell.h"

// void	print_matrix(char **matrix)
// {
// 	int	i = 0;
// 	int j;

// 	ft_putchar_fd('{', 1);
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		ft_putchar_fd('[', 1);
// 		ft_putstr_fd(matrix[i], 1);
// 		ft_putchar_fd(']', 1);
// 		ft_putchar_fd(',', 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// 	ft_putchar_fd('}', 1);
// 	ft_putchar_fd('\n', 1);
// }

t_list	*convert_env_to_list(char **env)
{
	char	*value;
	char	*key;
	t_list	*new;
	t_list	*lst;

	lst = NULL;
	if (env && *env)
	{
		while (*env)
		{
			key = get_variable_name(*env);
			value = getenv(key);
			new = ft_lstnew(key, ft_strdup(value));
			if (new == NULL)
				return (NULL);
			ft_lstadd_back(&lst, new);
			env++;
		}
	}
	return (lst);
}
