#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces output based on a specific format
 * @format: Format string
 * Return:  Number of characters printed
 */

int _printf(const char *format, ...)
{
	int y, printd = 0, printd_chars = 0;
	int width, flags, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (y = 0; format && format[y] != '\0'; y++)
	{
		if (format[y] != '%')
		{
			buffer[buff_ind++] = format[y];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[y], 1);*/
			 printd_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &y);
			width = get_width(format, &y, list);
			precision = get_precision(format, &y, list);
			size = get_size(format, &y);
			++y;
			printd = handle_print(format, &y, list, buffer,
				flags, width, precision, size);
			if (printd == -1)
				return (-1);
			printd_chars += printd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printd_chars);
}

/**
 * print_buffer - prints buffer contents
 * @buffer: character array
 * @buff_ind: adds next charactier.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
