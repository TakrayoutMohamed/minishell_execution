#include "./../libminishell.h"

/*return a double pointer created from the list pointer entered (lst)*/
char **convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (tmp != NULL)
	{
		matrix[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}