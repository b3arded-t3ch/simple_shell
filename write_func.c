#include "main.h"

void write_func(char *s)
{
	write(1, s, strlen(s));
}
