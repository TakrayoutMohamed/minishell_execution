#include "./../../libminishell.h"

/*export the data or add the variable str to the env linked list*/
void	export_with_parameter(t_list *env, char *str)
{
	char	*key;
	char	*value;
	char	*variable_value;
	size_t	i;

	i = 0;
	if (!is_valid_identifier(str))
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
		return ;
	}
	key = get_variable_name(str);
	while (i < ft_strlen(key) && *str)
	{
		i++;
		str++;
	}
	if (*str != '\0')
	{
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
	}
	else
		value = NULL;
	if (is_variable_exists(key, env))
	{
		free(get_variable_value(key, env));
		update_env_value(key, value, env);
	}
	else
		ft_lstadd_back(&env, ft_lstnew(ft_strdup(key), ft_strdup(value)));
	free(value);
	free(key);
}

/*swap the data of the entered nodes lsta and lstb*/
void	ft_lstswap(t_list *lsta, t_list *lstb)
{
	char	*tmpkey;
	char	*tmpvalue;

	if (lsta != NULL && lstb != NULL)
	{
		tmpkey = lsta->key;
		tmpvalue = lsta->value;
		lsta->key = lstb->key;
		lsta->value = lstb->value;
		lstb->key = tmpkey;
		lstb->value = tmpvalue;
	}
}

void	export_no_parameter(t_list *env)
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
void	export(t_list *cmd_lst, t_list *env)
{
	t_list	*tmp;

	if (cmd_lst == NULL)
		return ;
	if (ft_lstsize(cmd_lst) > 1)
	{
		tmp = cmd_lst->next;
		while (tmp)
		{
			export_with_parameter(env, tmp->value);
			tmp = tmp->next;
		}
	}
	else
	{
		export_no_parameter(env);
	}
}
