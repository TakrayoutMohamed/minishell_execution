/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:58 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/10 15:50:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpipex.h"

/*this function read from a fd_in's content and write it to fd_out*/
void	read_from_fd(int fd_in, int fd_out)
{
	char	buff;
	size_t	readedbuf;

	while (1)
	{
		readedbuf = read(fd_in, &buff, 1);
		if (readedbuf == 0 || readedbuf == -1)
		{
			free(buff);
			exit(errno);
		}
		if (readedbuf == 0)
			break;
		ft_putchar(buff, fd_out);
	}
}
