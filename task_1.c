#include "main.h"
#include <stdlib.h>

/**
 * get_func - returns the correct func or null
 * @id: char
 * Return: function
 */

int (*get_func(const char id))(va_list args)
{
	prv_t prv[] = {
		{'d', pr_dec},
		{'i', pr_dec},
	};

	const int PRV_LEN = 13;
	int i = 0;

	while (i < PRV_LEN)
	{
		if (id == prv[i].id)
			return (prv[i].f);
		i++;
	}

	return (NULL);
}
