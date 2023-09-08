/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:50 by takra             #+#    #+#             */
/*   Updated: 2023/09/08 22:41:54 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_middle_infile(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else if (lst->previous != NULL)
		dup2(lst->previous->pipe[0], 0);
	close(lst->pipe[0]);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->previous != NULL)
	{
		close(tmp->pipe[0]);
		tmp = tmp->previous;
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
	close(lst->pipe[1]);
}

int	pipe_middle(t_list *lst, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		return (print_error(errno), errno);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_middle_infile(lst);
		pipe_middle_outfile(lst);
		execve(argv[0], argv, envp);
		exit(127);
	}
	close(lst->pipe[1]);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	return (t_stats.status);
}
