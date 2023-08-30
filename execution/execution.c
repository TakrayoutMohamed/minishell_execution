#include "../libminishell.h"

// void	print_matrix(char **matrix)
// {
// 	int	i = 0;
// 	int j;

// 	ft_putchar_fd('{', 1);
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		ft_putchar_fd('[', 1);
// 		while (matrix[i][j])
// 		{
// 			ft_putchar_fd(matrix[i][j], 1);
// 			j++;
// 		}
// 		ft_putchar_fd(']', 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// 	ft_putchar_fd('}', 1);
// }

char	**get_term_value(t_list *env)
{
	char	**matrix;
	char	*key_value;

	matrix = NULL;
	if (is_variable_exists("TERM", env))
	{
		key_value = ft_strjoin("TERM=", get_variable_value("TERM", env));
		matrix = ft_split(key_value, ' ');
		free(key_value);
	}
	return (matrix);
}

void	execution(t_list *lst, t_list *env, int position)
{
	char	**matrix;
	char	**matrixp;
	char	*path;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	matrix = convert_list_to_matrix(lst_cmd);
	path = get_path_of_cmd(env, matrix[0]);
	free(matrix[0]);
	matrix[0] = path;
	matrixp = get_term_value(env);
	printf("the path of executable |%s| is |%s|\n",lst_cmd->value, matrix[0]);
	printf("the position is |%d|\n",position);
	if (matrix != NULL && *matrix != NULL)
	{
		if (position == 1)
		{
			pipe_beginning(lst, matrix, matrixp);
		}
		else if (position == 2)
		{
			pipe_middle(lst, matrix, matrixp);
		}
		else
		{
			pipe_end(lst, matrix, matrixp);
		}
	}
	ft_freematrix(matrix);
	ft_freematrix(matrixp);
	return ;
}
