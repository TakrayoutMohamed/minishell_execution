#include "./../libminishell.h"

t_list	*convert_matrix_to_list(char **matrix)
{
	t_list	*lst;

	lst = NULL;
	if (!matrix)
		return (NULL);
	while (*matrix)
	{
		ft_lstadd_back(&lst, ft_lstnew(NULL, ft_strdup(*matrix)));
		matrix++;
	}
	return (lst);
}
