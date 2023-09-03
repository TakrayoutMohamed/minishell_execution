/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:50 by takra             #+#    #+#             */
/*   Updated: 2023/09/03 05:07:06 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_middle_infile(t_list *lst)
{
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else if (lst->previous != NULL)
	{
		// fprintf(stderr, "not null\n");
		dup2(lst->previous->pipe[0], 0);
	}
}

static void	pipe_middle_outfile(t_list *lst)
{
	if (lst->outfile > 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else if (lst->next != NULL)
	{
		dup2(lst->pipe[1], 1);
	}
}

int	pipe_middle(t_list *lst, char **argv, char **envp)
{
	pid_t	pid;
	t_list	*tmp;

	tmp = lst;
	pid = fork();
	if (pid == -1)
	{
		return (print_error(errno), errno);
	}
	else if (pid == 0)
	{
		pipe_middle_infile(lst);
		// close(lst->previous->pipe[0]);
		pipe_middle_outfile(lst);
		close(lst->pipe[1]);
		close(lst->pipe[0]);
		// while (tmp->next != NULL)
		// 	tmp = tmp->next;
		// close(lst->next->pipe[0]);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		while (tmp->previous != NULL)
		{
			close(tmp->pipe[0]);
			tmp = tmp->previous;
		}
		execve(argv[0], argv, envp);
		t_stats.status = errno;
		exit(t_stats.status);
	}
	close(lst->pipe[1]);
	while (tmp->previous != NULL)
	{
		close(lst->previous->pipe[0]);
		tmp = tmp->previous;
	}
	return (t_stats.status);
}
