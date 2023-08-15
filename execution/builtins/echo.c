/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 16:52:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

int	echo(t_list *lst, t_list *env)
{
	if (lst == NULL)
		return (printf("the lst passed to echo is not allocated\n"),-12);
	// expend_data(lst->message, env);
	if (lst->cmd->message != NULL)
	{
		ft_putstr_fd(lst->cmd->message, 1);
	}
	if (ft_strcmp(lst->cmd->options, "-n") != 0)
	{
		printf("\n");
	}
	return (0);
}
