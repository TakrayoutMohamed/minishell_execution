#include "./../../libminishell.h"

bool	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
	{
		return (false);
	}
	if (!ft_isalpha(*str) && *str != '_')
		return (false);
	while (*str && *str != '=')
	{
		if (ft_isalpha(*str) || *str == '_' || ft_isdigit(*str))
		{
			i++;
			str++;
		}
		else
			return (false);
	}
	return (true);
}

void	export_with_parameter(t_list *env, char *str)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	if (!is_valid_identifier(str))
	{
		ft_putstr_fd("export: `",1);
		ft_putstr_fd(str,1);
		ft_putstr_fd("\': not a valid identifier\n",1);
		return ;
	}
	key = get_variable_name(str);
	while (i < ft_strlen(key) && *str)
	{
		i++;
		str++;
	}
	// if (*str && *str == '=')
	// 	str++;
	if (*str != '\0')
	{
		str++;
		value = ft_strdup(str);
	}
	else
		value = NULL;

	// printf("key = |%s|, value = |%s| isexist = |%d|\n",key, value, is_variable_exists(key, env));
	// exit(88);

	if (is_variable_exists(key, env))
		update_env_value(key, value, env);
	else
	{

		// if (strcmp(key, "BBB") == 0)
			// printf("llllll key = |%s|, value = |%s| isexist = |%d|\n",key, value, is_variable_exists(key, env));
		ft_lstadd_back(&env, ft_lstnew(key, value));
			// if (strcmp(key, "BBB") == 0)
		// printf("llllll key = |%s|, value = |%s| isexist = |%d|\n",key, value, is_variable_exists(key, env));

	}
}

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

void	print_export(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (env == NULL)
		return ;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->key, 1);
		if (tmp->value != NULL)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}

void	export_no_parameter(t_list *env)
{
	t_list	*sorted_list;
	t_list	*tmp;
	t_list	*tmp1;

	sorted_list = NULL;
	tmp1 = NULL;
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
	sorted_list = NULL;
	tmp = NULL;
}

void	export(t_list *lst, t_list *env)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	if (ft_lstsize(lst) > 1)
	{
		tmp = lst->next;
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
	// export_no_parameter(env);// when i finished testing i need to remove this line
}