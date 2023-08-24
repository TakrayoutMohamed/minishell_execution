/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/24 22:22:33 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_match_echo_options(char *str)
{
	if (!str || !*str)
		return (false);
	if (str[0] != '-')
		return (false);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}

void	echo_new_line(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) != 0)
			ft_putstr_fd(matrix[i], 1);
		i++;
		if (matrix[i])
			ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\n", 1);
}

void	echo_no_line(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) != 0)
			ft_putstr_fd(matrix[i], 1);
		i++;
		if (matrix[i])
			ft_putstr_fd(" ", 1);
	}
}

int	echo(t_list *cmd_lst)
{
	char	**matrix;
	char	**argv;

	cmd_lst = cmd_lst->next;
	matrix = convert_list_to_matrix(cmd_lst);
	argv = matrix;
	if (ft_lstsize(cmd_lst) == 1 && !is_match_echo_options(argv[0]))
		ft_putendl_fd(argv[0], 1);
	else
	{
		while (*matrix)
		{
			if (!is_match_echo_options(*matrix))
				break;
			matrix++;
		}
		if (is_match_echo_options(argv[0]))
			echo_no_line(matrix);
		else
			echo_new_line(matrix);
	}
	return (ft_freematrix(argv), EXIT_SUCCESS);
}
