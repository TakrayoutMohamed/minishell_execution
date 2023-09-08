/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:56:41 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/08 23:00:07 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	set_status(int status)
{
	if (WIFEXITED(status))
		t_stats.status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		t_stats.status = WTERMSIG(status) + 128;
		if (status == -2)
			t_stats.status = 126;
	}
	if (t_stats.status == 131)
	{
		ft_putstr_fd("Quit: 3\n", 1);
	}
}
