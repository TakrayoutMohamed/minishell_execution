/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:12:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/11 16:16:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIPEX_H_
#define LIBPIPEX_H_

#ifndef LIBMINISHELL_H_
#include "./../libminishell.h"
#endif

void	ft_pipe(t_list *cmds);
void	read_from_fd(int fd_in, int fd_out);

#endif
