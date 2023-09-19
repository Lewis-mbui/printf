#include "main.h"
/*print character function*/
/**
 * print_char - prints a character
 * @types: argument parameters
 * @buffer: array buffer to hold print values
 * @flags:  counter of  flags
 * @width: width
 * @precision: precision specification details
 * @size: specifies size
 * Return: characters printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*string function*/
/**
 * print_string - prints a string
 *  @types: argument parameters
 * @buffer: array buffer to hold print values
 * @flags:  counter of flags
 * @width: width
 * @precision: precision specification details
 * @size: specifies size
 * Return: printed string
 */
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int len = 0, y;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
		if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (y = width - len; y > 0; y--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (y = width - len; y > 0; y--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/*function percent sign*/
/**
 * print_percent - prints a percent sign
 *  @types: argument parameters
 * @buffer: array buffer to hold print values
 * @flags:  counter of flags
 * @width: width
 * @precision: precision specification details
 * @size: specifies size
 * Return: percentage sign
 */
int print_percent(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	return (write(1, "%%", 1));
}
/*function print int*/
/**
 * print_int - prints an interger
 * @types: argument parameters
 * @buffer: array buffer to hold print values
 * @flags:  counter of flags
 * @width: width
 * @precision: precision specification details
 * @size: specifies size
 * Return: integer
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int is_negtv = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_negtv = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_number(is_negtv, y, buffer, flags, width, precision, size));
}
/*function print binary*/
/**
 * print_binary - prints an unsigned number
 * @types: argument parameters
 * @buffer: array buffer to hold print values
 * @flags:  counter of flags
 * @width: width
 * @precision: precision specification details
 * @size: specifies size
 * Return: unsigned number.
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int n, m, y, sum;
	unsigned int z[32];
	int counter;

	UNUSED(buffer);
UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	z[0] = n / m;
	for (y = 1; y < 32; y++)
	{
		m /= 2;
		z[y] = (n / m) % 2;
	}
	for (y = 0, sum = 0, counter = 0; y < 32; y++)
	{
		sum += z[y];
		if (sum || y == 31)
		{
			char a = '0' + z[y];

			write(1, &a, 1);
			counter++;
		}
	}
	return (counter);
}
