/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:44 by takra             #+#    #+#             */
/*   Updated: 2023/09/03 17:49:47 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_end_infile(t_list *lst)
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

static void	pipe_end_outfile(t_list *lst)
{
	if (lst->outfile > 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	close(lst->pipe[1]);
}

int	pipe_end(t_list *lst, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (print_error(errno), errno);
	else if (pid == 0)
	{
		pipe_end_infile(lst);
		pipe_end_outfile(lst);
		execve(argv[0], argv, envp);
		t_stats.status = errno;
		exit(t_stats.status);
	}
	close_pipe(lst->pipe);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	t_stats.flag_sigint = 1;
	waitpid(pid, &(t_stats.status), 0);
	t_stats.flag_sigint = 0;
	return (t_stats.status);
}
