#! /bin/bash
make libmini.a
cc testing/export_tst.c libmini.a libft/libft.a -o export
cc testing/env_tst.c libmini.a libft/libft.a -o env
cc testing/cd_tst.c libmini.a libft/libft.a -o cd
cc testing/unset_tst.c libmini.a libft/libft.a -o unset

