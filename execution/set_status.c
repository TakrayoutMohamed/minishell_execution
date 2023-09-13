/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:56:41 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/13 02:56:59 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	set_status(int status)
{
	if (WIFEXITED(status))
		t_stats.status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		t_stats.status = WTERMSIG(status) + 128;
		if (t_stats.status == 131)
			ft_putstr_fd("Quit (core dumped)\n", 1);
	}
	else if (WIFSTOPPED(status))
		t_stats.status = WSTOPSIG(status) + 128;
	else
	{
		if (WIFCONTINUED(status))
			ft_putstr_fd("child continued\n", 1);
	}
	if (status == -2)
		t_stats.status = 126;
}
