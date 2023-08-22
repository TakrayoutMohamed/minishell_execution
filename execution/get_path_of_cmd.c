#include "./../libminishell.h"

/*return true if the program in the path is exist and its executable*/
bool	is_cmd_in_dir(char *path, char *program)
{
	char			*pseudo_path;
	char			*full_path;

	pseudo_path = ft_strjoin("/", program);
	full_path = ft_strjoin(path, pseudo_path);
	free(pseudo_path);
	if (access(full_path, X_OK | F_OK) == 0)
		return (free(full_path), true);
	free(full_path);
	return (false);

}

/*this function returns the executable of the command "cmd" with
* within its absolute path depending on the env variable $PATH
* exemple : if the cmd is "ls" than the  return will be like "/bin/ls" (in linux)
*/
char	*get_path_of_cmd(t_list *env, char *cmd)
{
	char	**matrix;
	char	*path;
	char	*pseudo_path;
	int		i;

	path = NULL;
	matrix = NULL;
	i = 0;
	if (is_cmd_in_dir("", cmd))
		return (ft_strdup(cmd));
	if (is_variable_exists("PATH", env))
	{
		matrix = ft_split(get_variable_value("PATH", env), ':');
		if (!matrix)
		{
			return (ft_freematrix(matrix), NULL);
		}
		while (matrix[i])
		{
			if (is_cmd_in_dir(matrix[i], cmd))
			{
				pseudo_path = ft_strjoin("/", cmd);
				path = ft_strjoin(matrix[i], pseudo_path);
				free(pseudo_path);
				break ;
			}
			i++;
		}
	}
	ft_freematrix(matrix);
	if (path == NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (path);
}