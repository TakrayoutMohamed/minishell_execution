#include "./../libminishell.h"

t_list	*convert_env_to_list(char **env)
{
	char	**str;
	t_list	*new;
	t_list	*lst;

	lst = NULL;
	if (env && *env)
	{
		while (*env)
		{
			str = ft_split(*env, '=');
			if (str == NULL)
				return (NULL);
			new = ft_lstnew(*str, *(++str));
			if (new == NULL)
				return (NULL);
			ft_lstadd_back(&lst, new);
			env++;
		}
	}
	return (lst);
}
