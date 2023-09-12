/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:14 by takra             #+#    #+#             */
/*   Updated: 2023/09/12 06:30:38 by takra            ###   ########.fr       */
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

int	get_position(t_list *lst, t_list *tmp)
{
	int	position;

	while (lst->previous != NULL)
		lst = lst->previous;
	position = 0;
	if (tmp == ft_lstlast(lst))
		position = 3;
	else if (tmp == lst)
		position = 1;
	else
		position = 2;
	return (position);
}

int	execute_pipes(t_list *lst, char **matrix, char **matrixp, t_list **p_ids)
{
	int	position;

	position = get_position(lst, lst);
	if (pipe(lst->pipe) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (EXIT_FAILURE);
	}
	if (position == 1)
		return (pipe_beginning(lst, matrix, matrixp, p_ids));
	else if (position == 2)
		return (pipe_middle(lst, matrix, matrixp, p_ids));
	else
		return (pipe_end(lst, matrix, matrixp, p_ids));
	return (EXIT_SUCCESS);
}

static char	*adding_path_to_argv(t_list *env, char **matrix)
{
	char	*path;

	path = get_path_of_cmd(env, matrix[0]);
	if (path != NULL)
	{
		free(matrix[0]);
		matrix[0] = path;
	}
	return (matrix[0]);
}

int	execution(t_list *lst, t_list *env, t_list **p_ids)
{
	char	**matrix;
	char	**matrixp;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	matrix = convert_list_to_matrix(lst_cmd);
	matrixp = convert_env_lst_to_env_matrix(env);
	if (matrix && *matrix)
	{
		matrix[0] = adding_path_to_argv(env, matrix);
	}
	if (matrix && *matrix && is_dir(matrix[0]))
	{
		t_stats.status = -2;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(matrix[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	else if (execute_pipes(lst, matrix, matrixp, p_ids) == EXIT_FAILURE)
		return (ft_freematrix(matrix), ft_freematrix(matrixp), EXIT_FAILURE);
	return (ft_freematrix(matrix), ft_freematrix(matrixp), EXIT_SUCCESS);
}
