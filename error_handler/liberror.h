/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberror.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 03:23:07 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 04:12:09 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERROR_H
# define LIBERROR_H
# ifndef LIBMINISHELL_H
#  include "./../libminishell.h"
# endif

void	print_error(int error_nbr);
void	print_strerror_set_status(char *strerr, int status);

#endif
