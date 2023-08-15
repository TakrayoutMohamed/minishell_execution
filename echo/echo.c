/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 21:48:57 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libecho.h"

void	echo_new_line(char **matrix)
{
	int	i;

	i = 1;
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

	i = 2;
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
	int	i;

	i = 1;
	if (argc == 1)
		ft_putstr_fd("\n", 1);
	else if (argc == 2 && ft_strcmp(argv[1], "-n") != 0)
		ft_putendl_fd(argv[1], 1);
	else
	{
		if (ft_strcmp(argv[1], "-n") == 0)
			echo_no_line(argv);
		if (ft_strcmp(argv[1], "-n") != 0)
			echo_new_line(argv);
	}
}
