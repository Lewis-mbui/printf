#include "main.h"
/**
 * get_precision - function to calculated precisiong
 * @format: format parameter string to print
 * @p: List of arguments to be printed.
 * @list: arguments list
 * Return: upon success to return precision.
 */
int get_precision(const char *format, int *p, va_list list)
{
	int curr_y = *p + 1;
	int precision = -1;

	if (format[curr_y] != '.')
		return (precision);

	precision = 0;

	for (curr_y += 1; format[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(format[curr_y]))
		{
			precision *= 10;
			precision += format[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*p = curr_y - 1;

	return (precision);
}


