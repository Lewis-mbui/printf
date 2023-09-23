#include "main.h"
/**
 * is_printable - check for printable character
 * @c: character to be checked
 *
 * Return: 1 if successfule, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - add  ascci in hexadecimal code to buffer
 * @buffer: array buffer
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: upon success 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[asscii_code % 16];

	return (3);
}

/**
 * is_digit - check for digit
 * @c: character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
