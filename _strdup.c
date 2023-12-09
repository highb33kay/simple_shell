#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * my_strdup - Entry point
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */
char *my_strdup(const char *str)
{
	int str_size;
	static char *dup;
	char *dup_offset;

	/* Allocate memory for duplicate */
	str_size = strlen(str);
	dup = (char *)malloc(sizeof(char) * str_size + 1);
	if (dup == NULL)
		return ((char *)NULL);

	/* Copy string */
	dup_offset = dup;
	while (*str)
	{
		*dup_offset = *str;
		dup_offset++;
		str++;
	}
	*dup_offset = '\0';

	return (dup);
}
