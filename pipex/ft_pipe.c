
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:27:44 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/08 19:12:51 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpipex.h"

void	close_pipe(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
	if (close(pipe_fd[1]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
}

void	ft_pipe_begain(char *cmd1[], char *cmd2[])
{
	int	pipe_fd[2];
	// int	pipe_fd2[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)//create the pipe
	{
		print_error(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(status);
	}
	else if (pid == 0) // this is child
	{
		dup2(pipe_fd[1], 1);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd1[0], cmd1, NULL);
	}
	else //this is parent
	{
		dup2(pipe_fd[0], 0);
		close_pipe(pipe_fd);
		waitpid(pid, &status, WUNTRACED);
		execve(cmd1[0], cmd1, NULL);
	}
}
