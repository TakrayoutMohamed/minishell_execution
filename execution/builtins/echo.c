/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/06 00:25:53 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

int	get_variable_len(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (i);
	while (str && *str)
	{
		if (ft_isalpha(*str) || *str == '_' || ft_isdigit(*str))
		{
			i++;
			str++;
		}
		else
		{
			break ;
		}
	}
	return (i);
}

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
	ft_strlcpy(variable, str, var_len);
	return (variable);
}

char	*get_variable_value(char *key, t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (key != NULL && tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(key, tmp->key, ft_strlen(key)) == 0 )
			{
				return (ft_strdup(tmp->value));
			}
			tmp = tmp->next;
		}
	}
	return (ft_strdup(""));
}

void	print_data(char *message, t_list *env)
{
	char *str;

	if (message != NULL)
	{
		while (*message != '\0')
		{
			if (*message == '$')
			{
				message++;
				if (ft_isalpha(*message) || *message == '_')
				{
					ft_putstr_fd(get_variable_value(get_variable_name(message), env) , 1);
					while (ft_isalpha(*message) || *message == '_' || ft_isdigit(*message))
						message++;
				}
				else
				{
					ft_putchar_fd('$', 1);
				}
			}
			ft_putchar_fd(*message, 1);
			message++;
		}
	}
}

int	echo(t_tree *tree, t_list *env)
{
	if (tree == NULL)
		return (printf("the tree passed to echo is not allocated\n"),-12);
	if (tree->message != NULL)
	{
		if (ft_strchr(tree->message, '$'))
		{
			print_data(tree->message, env);
		}
		else
		{
			printf("%s",tree->message);
		}
	}
	if (strcmp(tree->option, "-n") != 0)//need to change strcmp to ft_strcmp
	{
		printf("\n");
	}
	return (0);
}
