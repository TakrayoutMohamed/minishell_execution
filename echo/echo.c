/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/17 18:54:50 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libecho.h"

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

int	main(int argc, char **argv)
{
	char	**matrix;

	matrix = argv;
	if (argc == 1)
		ft_putstr_fd("\n", 1);
	else if (argc == 2 && !is_match_echo_options(argv[1]))
		ft_putendl_fd(argv[1], 1);
	else
	{
		matrix++;
		while (*matrix)
		{
			if (!is_match_echo_options(*matrix))
				break;
			matrix++;
		}
		if (is_match_echo_options(argv[1]))
			echo_no_line(matrix);
		else
			echo_new_line(matrix);
	}
}
