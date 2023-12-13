#include "shell.h"
/**
 * _str_cmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if the strings are equal, 1 otherwise
 */
int _str_cmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
