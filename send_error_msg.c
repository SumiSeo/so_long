#include "so_long.h"

void	send_error_msg(char *s)
{
	perror(s);
	printf("test %s", s);
}