#include "main.h"
/**
 * get_width - calculates width to print
 * @format: parameter string to print the arguments.
 * @p: arguments list to be printed.
 * @list: argument list.
 * Return: upon success return width
 */
int get_width(const char *format, int *p, va_list list)
{
	int curr_m;
	int width = 0;

	for (curr_m = *p + 1; format[curr_m] != '\0'; curr_m++)
	{
		if (is_digit(format[curr_m]))
		{
			width *= 10;
			width += format[curr_m] - '0';
		}
		else if (format[curr_m] == '*')
		{
			curr_m++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*p = curr_m - 1;

	return (width);
}
