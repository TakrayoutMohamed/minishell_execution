#include "./../libminishell.h"

char **convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(ft_lstsize(lst) + 1);
	while (lst != NULL)
	{
		matrix[i] = (char *)malloc(ft_strlen(tmp) + 1);
		if (!matrix[i])
		{
			ft_freematrix(matrix);
			return (NULL);
		}
		ft_strlcpy(matrix[i], tmp->value, ft_strlen(tmp) + 1);
		i++;
		tmp = tmp->next;
	}
	return (matrix);
}