#include "./../libminishell.h"

/*return a double pointer created from the list pointer entered (lst)*/
char **convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	char	*str;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(ft_lstsize(lst) + 1);
	//this function for some reason does not work proprely
	while (tmp != NULL)
	{

		str = ft_strjoin(tmp->key, "=");
		matrix[i] = ft_strjoin(str, tmp->value);
		free(str);
		i++;
		tmp = tmp->next;
	}
	matrix[ft_lstsize(lst)] = NULL;
	return (matrix);
}