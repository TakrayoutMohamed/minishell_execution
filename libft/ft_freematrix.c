/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:20:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/21 04:03:11 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*free located memory for a matrix*/
void	ft_freematrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	matrix = temp;
	free(matrix);
}
