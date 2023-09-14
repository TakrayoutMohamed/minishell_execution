/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_nofiledir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:16:15 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:50:31 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liberror.h"

void	print_error_nofiledir(char *cmd)
{
	if (is_dir(cmd) == false)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		print_strerror_set_status(": No such file or directory\n", 127);
	}
}
