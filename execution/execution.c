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


void	execution(t_list *lst, t_list *env, int position)
{
	char	**matrix;
	char	*path;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	matrix = convert_list_to_matrix(lst_cmd);
	path = get_path_of_cmd(env, matrix[0]);
	free(matrix[0]);
	matrix[0] = path;
	if (matrix != NULL && *matrix != NULL)
	{
		if (position == 1)
		{
			pipe_beginning(lst, matrix); //still need to test this one
		}
		else if (position == 2)
		{
			pipe_middle(lst, matrix); //still need to test this one 
		}
		else
		{
			pipe_end(lst, matrix);
		}
	}
	ft_freematrix(matrix);
	return ;
}
