#include "main.h"

/* get_exact_print - Calculates the exact print*/
int get_exact_print(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int exact_print = -1;

	if (format[curr_i] != '.')
		return (exact_print);

	exact_print = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			exact_print *= 10;
			exact_print += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			exact_print = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (exact_print);
}
