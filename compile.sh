#! /bin/bash
make re
# cc testing/export_tst.c libmini.a libft/libft.a -o export
# cc testing/echo_tst.c libmini.a libft/libft.a -o echo
# cc testing/env_tst.c libmini.a libft/libft.a -o env
# cc testing/cd_tst.c libmini.a libft/libft.a -o cd
# cc testing/unset_tst.c libmini.a libft/libft.a -o unset
# cc testing/shlvl_tst.c libmini.a libft/libft.a -o shlvl
# cc testing/pwd_tst.c libmini.a libft/libft.a -o pwd
# cc testing/get_path_of_cmd_tst.c libmini.a libft/libft.a -o path_cmd
# cc -fsanitize=address testing/lst_to_matrix_tst.c libmini.a libft/libft.a -o lst_to_matrix
# cc testing/execution_tst.c libmini.a libft/libft.a -o execution_tst
cc testing/execution_lst_tst.c libmini.a libft/libft.a -o execution_lst

