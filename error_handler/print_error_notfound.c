/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_notfound.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:16:22 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:16:23 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liberror.h"

void	print_error_notfound(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	print_strerror_set_status(": command not found\n", 127);
}
