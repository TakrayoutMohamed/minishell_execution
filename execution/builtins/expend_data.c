/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:06:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/07 16:00:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*print the data with the value of the variables from env*/
void	print_data(char *message, t_list *env)
{
	char *str;

	if (message == NULL)
		return ;
	while (*message != '\0')
	{
		if (*message == '$' && message++)
		{
			if (ft_isalpha(*message) || *message == '_')
			{
				str = get_variable_name(message);
				ft_putstr_fd(get_variable_value(str, env) , 1);
				free(str);
				while (ft_isalpha(*message) || *message == '_' || ft_isdigit(*message))
					message++;
			}
			// else if (*message == '$')
			// 	ft_putnbr_fd(getpid(), 1);
			else
				ft_putchar_fd('$', 1);
		}
		if (*message != '$')
			ft_putchar_fd(*message, 1);
		message++;
	}
}

void	expend_data(char *str, t_list *env)
{
	if (str != NULL)
	{
		if (ft_strchr(str, '$'))
		{
			print_data(str, env);
		}
		else
		{
			printf("%s",str);
		}
	}
}
