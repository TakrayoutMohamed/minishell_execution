#include "../libminishell.h"

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
	return ;
}
