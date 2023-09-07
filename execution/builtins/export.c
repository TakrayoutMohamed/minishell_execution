/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:30 by takra             #+#    #+#             */
/*   Updated: 2023/09/07 18:04:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*return the exit status of 1 and print error that the identifier is not valid*/
static int	not_valid_identifier(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	t_stats.status = 256;
	return (t_stats.status);
}

/*return an allocated string with value of the variable in the
* concatenating stats
*/
static char	*get_value(char *str, char *key, t_list *env)
{
	char	*variable_value;
	char	*value;

	if (ft_strncmp(str, "+=", 2) == 0)
	{
		str = str + 2;
		variable_value = ft_strdup(get_variable_value(key, env));
		value = ft_strjoin(variable_value, str);
		free(variable_value);
	}
	else
	{
		str++;
		value = ft_strdup(str);
	}
	return (value);
}

/*export the data or add the variable str to the env linked list*/
static int	export_with_parameter(t_list **env, char *str)
{
	char	*key;
	char	*value;
	size_t	i;

	i = -1;
	if (!is_valid_identifier(str))
		return (not_valid_identifier(str), t_stats.status);
	key = get_variable_name(str);
	while (++i < ft_strlen(key) && *str)
		str++;
	if (*str != '\0')
		value = get_value(str, key, *env);
	else
		value = NULL;
	if (is_variable_exists(key, *env))
	{
		free(get_variable_value(key, *env));
		update_env_value(key, value, *env);
	}
	else
		ft_lstadd_back(env, ft_lstnew(ft_strdup(key), ft_strdup(value)));
	return (free(value), free(key), EXIT_SUCCESS);
}

/*create a list with sorted alphabeticlly data of env  than free it 
* after using it.
*/
static void	export_no_parameter(t_list *env)
{
	t_list	*sorted_list;
	t_list	*tmp;
	t_list	*tmp1;

	sorted_list = NULL;
	tmp = env;
	while (tmp)
	{
		tmp1 = ft_lstnew(ft_strdup(tmp->key), ft_strdup(tmp->value));
		ft_lstadd_back(&sorted_list, tmp1);
		tmp = tmp->next;
	}
	tmp = sorted_list;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->key, tmp->next->key) > 0)
		{
			ft_lstswap(tmp, tmp->next);
			tmp = sorted_list;
		}
		else
			tmp = tmp->next;
	}
	print_export(sorted_list);
	ft_lstclear(&sorted_list, del);
}

/*execute export function */
int	export(t_list *cmd_lst, t_list **env)
{
	t_list	*tmp;

	if (cmd_lst == NULL)
		return (EXIT_FAILURE);
	if (ft_lstsize(cmd_lst) > 1)
	{
		tmp = cmd_lst->next;
		while (tmp)
		{
			export_with_parameter(env, tmp->value);
			tmp = tmp->next;
		}
		return (t_stats.status);
	}
	else
	{
		return (export_no_parameter(*env), EXIT_SUCCESS);
	}
}
