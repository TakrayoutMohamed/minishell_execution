/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:58 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 15:06:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

/*this function read from a file descriptor in list struct */
void	read_from_fd(t_list *lst)
{
	char	buff[20];
	size_t	readedbuf;
	pid_t	pid;
	int		fd_in;


	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		fd_in = open(lst->file->file_in, O_RDONLY, 0644);
		if (fd_in == -1)
		{
			print_error(errno);
			exit(errno);
		}
		dup2(fd_in, 0);
		dup2(lst->pipe[1], 1);
		close(fd_in);
		close(lst->pipe[1]);
		while (1)
		{
			readedbuf = read(0, buff, 20);
			if (readedbuf == -1)
			{
				fprintf(stderr,"error in read from pfd[0] end");
				exit(4);
			}
			if (readedbuf == 0)
			{
				fprintf(stderr,"EOFend!\n");
				break ;
			}
			if (write(1, buff, readedbuf) != readedbuf)
			{
				printf("child - partial/failed write \n");
				exit (5);
			}
		}
		exit(0);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
	}
}
