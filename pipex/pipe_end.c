/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:44 by takra             #+#    #+#             */
/*   Updated: 2023/09/11 20:08:16 by mohtakra         ###   ########.fr       */
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
	{
		dup2(lst->previous->pipe[0], 0);
		close(lst->previous->pipe[0]);
	}
	close(lst->pipe[0]);
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
		return (close_pipe(lst->pipe), print_error(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_end_infile(lst);
		pipe_end_outfile(lst);
		execve(argv[0], argv, envp);
		exit(127);
	}
	close_pipe(lst->pipe);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	t_stats.flag_sigint = 1;
	waitpid(pid, &(t_stats.status), 0);
	if (WIFSIGNALED(t_stats.status))
		t_stats.status = WTERMSIG(t_stats.status) + 128;
	t_stats.flag_sigint = 0;
	return (EXIT_SUCCESS);
}
