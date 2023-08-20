#include "./../libminishell.h"

bool	is_cmd_in_dir(char *path, char *cmd)
{
	char			*psuedo_path;
	char			*full_path;

	psuedo_path = ft_strjoin("/", cmd);
	full_path = ft_strjoin(path, psuedo_path);
	free(psuedo_path);
	if (access(full_path, X_OK | F_OK) == 0)
		return (free(full_path), true);
	free(full_path);
	return (false);

}

/*this function returns the path of entred cmd depending on the env $PATH*/
char	*get_path_of_cmd(t_list *env, char *cmd)
{
	char	**matrix;
	char	*path;
	char	*psuedo_path;
	int		i;

	path = NULL;
	matrix = NULL;
	i = 0;
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
				psuedo_path = ft_strjoin("/", cmd);
				path = ft_strjoin(matrix[i], psuedo_path);
				free(psuedo_path);
				break ;
			}
			i++;
		}
	}
	ft_freematrix(matrix);
	if (path == NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);;
	}
	return (path);
}