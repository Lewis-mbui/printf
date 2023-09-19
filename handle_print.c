#include "main.h"
/**
 * handle_print - prints argument of  its type
 * @formt: string format to print the arguments.
 * @list: argument list to be printed.
 * @ind: ind
 * @buffer: buffer array to hold print.
 * @flags: calculates active flags
 * @width: gets width.
 * @precision: precision parameter specification
 * @size:size specifier
 * Return: either 1 or 2 upon success
 */
int handle_print(const char *formt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int y, un_len = 0, printed_chars = -1;
	 formt_t formt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'y', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (y = 0; formt_types[y].formt != '\0'; y++)
		if (formt[*ind] == formt_types[y].formt)
			return (formt_types[y].fn(list, buffer, flags, width, precision, size));

	if (formt_types[y].formt == '\0')
	{
		if (formt[*ind] == '\0')
			return (-1);
		un_len += write(1, "%%", 1);
		if (formt[*ind - 1] == ' ')
			un_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formt[*ind] != ' ' && formt[*ind] != '%')
				--(*ind);
			if (formt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		un_len += write(1, &formt[*ind], 1);
		return (un_len);
	}
	return (printed_chars);
}
