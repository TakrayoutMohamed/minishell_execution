/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:50:41 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/17 22:00:10 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*return the name of a variable with allocation for its return*/
char	*get_variable_name(char *str)
{
	int		var_len;
	char	*variable;

	if (!str || !*str)
		return (ft_strdup(""));
	var_len = get_variable_len(str);
	if (var_len == 0)
	{
		return (ft_strdup(""));
	}
	variable = (char *)malloc(sizeof(char) * var_len + 1); //malloc here
	if (variable == NULL)
		return (NULL);
	ft_strlcpy(variable, str, var_len + 1);
	return (variable);
}
