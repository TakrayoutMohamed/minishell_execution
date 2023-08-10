/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/07 16:51:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

int	echo(t_tree *tree, t_list *env)
{
	if (tree == NULL)
		return (printf("the tree passed to echo is not allocated\n"),-12);
	// expend_data(tree->message, env);
	if (tree->message != NULL)
	{
		ft_putstr_fd(tree->message, 1);
	}
	if (ft_strncmp(tree->option, "-n", ft_strlen(tree->option)) != 0)
	{
		printf("\n");
	}
	return (0);
}
