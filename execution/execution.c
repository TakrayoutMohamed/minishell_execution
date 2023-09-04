/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:14 by takra             #+#    #+#             */
/*   Updated: 2023/09/04 17:05:01 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	is_dir(char *str)
{
	struct stat	detail;

	if (stat(str, &detail) != -1)
	{
		if (S_ISDIR(detail.st_mode))
			return (true);
	}
	return (false);
}

void	execute_pipes(t_list *lst, char **matrix, char **matrixp, int position)
{
	if (position == 1)
		pipe_beginning(lst, matrix, matrixp);
	else if (position == 2)
		pipe_middle(lst, matrix, matrixp);
	else
		pipe_end(lst, matrix, matrixp);
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
		if (is_dir(matrix[0]))
		{
			t_stats.status = -2;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(matrix[0], 2);
			ft_putstr_fd(": Is a directory\n", 2);
		}
		else
			execute_pipes(lst, matrix, matrixp, position);
	}
	ft_freematrix(matrix);
	ft_freematrix(matrixp);
}
