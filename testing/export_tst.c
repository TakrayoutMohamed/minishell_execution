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
	// ft_lstadd_back(&cmd, ft_lstnew(NULL, ""));
	// ft_lstadd_back(&lst, cmd);
	lst->cmd = cmd;
    export(cmd, env_lst);
    return (0);
}