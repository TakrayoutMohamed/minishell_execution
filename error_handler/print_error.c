#include "./liberror.h"

void	print_error(int error_nbr)
{
	printf("%s\n",strerror(error_nbr));
}
