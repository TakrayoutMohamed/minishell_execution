#include "./libparse.h"

t_list *parse_data(char *str)
{
	t_list	*lst;
	t_list	*tmp;
	t_list	*cmd;
	lst = NULL;
	cmd = NULL;
	tmp = ft_lstnew("NULL", "NULL");
	ft_lstadd_back(&lst, tmp);
	ft_lstadd_back(&cmd, ft_lstnew(NULL, "export"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, ""));
	// ft_lstadd_back(&lst, cmd);
	lst->cmd = cmd;
	// ft_putstr_fd("here no sigfault\n",2);
	
	
	return (lst);
}