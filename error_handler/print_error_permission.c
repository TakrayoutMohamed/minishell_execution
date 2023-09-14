/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_permission.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:16:30 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:16:31 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liberror.h"

void	print_error_permission(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	print_strerror_set_status(": Permission denied\n", 126);
}
