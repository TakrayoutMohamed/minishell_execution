#! /bin/bash
make libmini.a
cc testing/export_tst.c libmini.a libft/libft.a -o export
cc testing/env_tst.c libmini.a libft/libft.a -o env
cc testing/cd_tst.c libmini.a libft/libft.a -o cd
cc testing/unset_tst.c libmini.a libft/libft.a -o unset
cc testing/shlvl_tst.c libmini.a libft/libft.a -o shlvl
cc testing/pwd_tst.c libmini.a libft/libft.a -o pwd
cc testing/get_path_of_cmd_tst.c libmini.a libft/libft.a -o path_cmd
cc testing/lst_to_matrix_tst.c libmini.a libft/libft.a -o lst_to_matrix

