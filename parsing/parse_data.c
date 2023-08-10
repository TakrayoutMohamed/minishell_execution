#include "./libparse.h"

t_tree *parse_data(char *str)
{
	// t_tree	*tree;
	t_tree *tr1 = new_node("cd", "-", "~/Desktop/");
    // t_tree *tr2 = new_node("|",NULL, NULL);
    // t_tree *tr3 = new_node("grep",NULL, "a");
    // t_tree *tr4 = new_node("|",NULL, NULL);
    // t_tree *tr5 = new_node("grep",NULL, "a");
	// add_left(&tr2, tr1);
	// add_right(&tr2, tr3);
	// add_left(&tr1,tr4);
	// add_right(&tr1,tr5);
	// return (tr2);
	return (tr1);
}