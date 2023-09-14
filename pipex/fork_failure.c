/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:24:52 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:24:53 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	fork_failure(t_list *lst)
{
	close_pipe(lst->pipe);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	ft_putstr_fd("minishell : fork", 2);
	print_error(errno);
}
