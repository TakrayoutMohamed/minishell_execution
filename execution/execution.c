#include "../libminishell.h"

void	execution(t_list *lst, t_list *env, int position)
{
	char	**matrix;
	char	*path;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	matrix = convert_list_to_matrix(lst_cmd);
	if (matrix != NULL && *matrix != NULL)
	{
		if (position == 1)
		{
			ft_pipe_begain(lst, matrix); //still need to create this one 
		}
		else if (position == 2)
		{
			ft_pipe_middle(lst, matrix); //still need to create this one 
		}
		else
		{
			ft_pipe_end(lst, matrix); //still need to create this one 
		}
	}
	
	return ;
}
