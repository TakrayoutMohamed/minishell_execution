/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:55 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:49:56 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

int	read_from_fd(int fd)
{
	int		numread;
	char	buf;

	while (1)
	{
		numread = read(fd, &buf, 1);
		if (numread == -1)
		{
			t_stats.status = errno;
			return (print_error(errno), errno);
		}
		if (numread == 0)
		{
			break ;
		}
		if (write (1, &buf, numread) != numread)
		{
			t_stats.status = errno;
			return (print_error(errno), errno);
		}
	}
	return (EXIT_SUCCESS);
}
