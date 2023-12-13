#include "main.h"
/**
 * write_func - print string
 * @s: string to print
 */
void write_func(const char *s)
{
	write(1, s, strlen(s));
}
