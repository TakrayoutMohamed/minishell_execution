#include "../libminishell.h"

static char	**convert_env_lst_to_env_matrix(t_list *env)
{
	char	**matrix;
	char	*str_helper;
	t_list	*tmp;
	int		i;

	tmp = env;
	i = 0;
	matrix = NULL;
	if (env == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (ft_lstsize(tmp) + 1));
	if (!matrix)
		return (NULL);
	while (tmp != NULL)
	{
		str_helper = ft_strjoin(tmp->key, "=");
		matrix[i] = ft_strjoin(str_helper, tmp->value);
		free(str_helper);
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
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
	matrixp = convert_env_lst_to_env_matrix(env);
	if (matrix != NULL && *matrix != NULL)
	{
		path = get_path_of_cmd(env, matrix[0]);
		free(matrix[0]);
		matrix[0] = path;
		if (position == 1)
			pipe_beginning(lst, matrix, matrixp);
		else if (position == 2)
			pipe_middle(lst, matrix, matrixp);
		else
			pipe_end(lst, matrix, matrixp);
	}
	ft_freematrix(matrix);
	ft_freematrix(matrixp);
	return ;
}
