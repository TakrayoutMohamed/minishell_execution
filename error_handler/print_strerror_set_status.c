/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strerror_set_status.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:06 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:47:07 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	print_strerror_set_status(char *strerr, int status)
{
	ft_putstr_fd(strerr, 2);
	t_stats.status = status;
}
