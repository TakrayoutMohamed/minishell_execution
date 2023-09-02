#include "./../libminishell.h"

/*return true if the program in the path is exist and its executable*/
static bool	is_cmd_in_dir(char *path, char *program)
{
	char			*pseudo_path;
	char			*full_path;

	if (access(program, F_OK | X_OK) == 0)
		return (true);
	pseudo_path = ft_strjoin("/", program);
	full_path = ft_strjoin(path, pseudo_path);
	free(pseudo_path);
	if (access(full_path, F_OK) == 0)
	{
		if (access(full_path, X_OK) == 0)
		{
			t_stats.status = 0;
			return (free(full_path), true);
		}
		else
		{
			t_stats.status = 126;
			return (free(full_path), true);
		}
	}
	free(full_path);
	return (false);
}

static char	*path_of_cmd(t_list *env, char *cmd)
{
	char	*path;
	char	*pseudo_path;
	char	**matrix;
	int		i;

	i = -1;
	path = NULL;
	matrix = NULL;
	matrix = ft_split(get_variable_value("PATH", env), ':');
	if (!matrix)
		return (ft_freematrix(matrix), NULL);
	while (matrix[++i])
	{
		if (is_cmd_in_dir(matrix[i], cmd))
		{
			pseudo_path = ft_strjoin("/", cmd);
			path = ft_strjoin(matrix[i], pseudo_path);
			free(pseudo_path);
			break ;
		}
	}
	if (path == NULL)
		t_stats.status = 127;
	return (ft_freematrix(matrix), path);
}

/*this function returns the executable of the command "cmd" with
* within its absolute path depending on the env variable $PATH
* exemple : if the cmd is "ls" than the  return will be like "/bin/ls" (in linux)
*/
char	*get_path_of_cmd(t_list *env, char *cmd)
{
	char	*path;

	path = NULL;
	if (is_cmd_in_dir("", cmd))
		return (ft_strdup(cmd));
	if (is_variable_exists("PATH", env))
	{
		path = path_of_cmd(env, cmd);
		if (path == NULL || (path != NULL && t_stats.status == 126))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd, 2);
			if (path == NULL)
				ft_putstr_fd(": command not found\n", 2);
			else
				ft_putstr_fd(": Permission denied\n", 2);
		}
		return (path);
	}
	t_stats.status = 127;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (path);
}
