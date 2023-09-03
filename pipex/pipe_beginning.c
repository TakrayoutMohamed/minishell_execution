/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_beginning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:33 by takra             #+#    #+#             */
/*   Updated: 2023/09/03 05:07:22 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_beginning_infile(t_list *lst)
{
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else
	{
		// dup2(lst->pipe[0], 0);
	}
}

static void	pipe_beginning_outfile(t_list *lst)
{
	if (lst->outfile > 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else
	{
		dup2(lst->pipe[1], 1);
	}
}

int	pipe_beginning(t_list *lst, char **argv, char **envp)
{
	pid_t	pid;
	t_list	*tmp;

	tmp = lst;
	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		pipe_beginning_infile(lst);
		pipe_beginning_outfile(lst);
		close(lst->pipe[0]);
		close(lst->pipe[1]);
		while (tmp->next != NULL)
		{
			close(tmp->pipe[0]);
			tmp = tmp->next;
		}
		// while (tmp->previous != NULL)
		// {
		// 	close(tmp->previous->pipe[0]);
		// 	tmp = tmp->previous;
		// }
		execve(argv[0], argv, envp);
		t_stats.status = errno;
		exit(t_stats.status);
	}
	close(lst->pipe[1]);
	return (t_stats.status);
}
