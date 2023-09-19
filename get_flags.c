#include "main.h"

/**
 * get_flags - calculation of active flags
 * @format: format string arguments
 * @z: parameter values
 * Return: upon success flags
 */
int get_flags(const char *format, int *z)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int y, curr_m;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_m = *z + 1; format[curr_m] != '\0'; curr_m++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[curr_m] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*z = curr_m - 1;

	return (flags);
}







