#include "shell.h"
/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL.
 */
char *_strdup(const char *str)
{
	int str_size;
	char *dup;
	char *dup_offset;

	str_size = strlen(str);
	dup = (char *)malloc(sizeof(char) * (str_size + 1));
	if (dup == NULL)
		return (NULL);

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
