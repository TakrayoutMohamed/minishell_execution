#include "./../libminishell.h"

int main(int argc, char **argv, char **env)
{
    t_list	*lst;
	t_list	*tmp;
	t_list	*cmd;
	lst = NULL;
	cmd = NULL;
    t_list  *env_lst;

    env_lst = convert_env_to_list(env);
	tmp = ft_lstnew("NULL", "NULL");
	ft_lstadd_back(&lst, tmp);
	ft_lstadd_back(&cmd, ft_lstnew(NULL, "export"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, "ZZZ=alvaresNegredo"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, "GHHHHHHHHHHHHHH1"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, "AAA=THATISIT1"));
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, "BBB=THATISIT1"));
	ft_lstlast(cmd)->next = NULL;
	lst->cmd = cmd;
    export(cmd, env_lst);
    env_(env_lst);
	// ft_lstclear(&env_lst, del);
	// ft_lstclear(&cmd, del);
	// ft_lstclear(&lst, del);

    return (0);
}