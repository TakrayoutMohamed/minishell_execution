#include "./libminishell.h"

t_list  *convert_parsing_lst_to_execution(t_llist *tmp_lst)
{
	t_list	*lst;

	lst = NULL;

	while (tmp_lst)
	{
		ft_lstadd_back(&lst, ft_lstnew(NULL, NULL));
		if (tmp_lst->content != NULL)
		{
			lst->cmd = convert_matrix_to_list(tmp_lst->content->argument_cmd);
			lst->infile = tmp_lst->content->infile;
			lst->outfile = tmp_lst->content->outfile;
		}
		tmp_lst = tmp_lst->next;
	}
	return (lst);    
}
