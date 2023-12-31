/* Main header files*/
#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*defining sizes*/
#define S_LONG 2
#define S_SHORT 1

/* defining Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct formt - Struct op
 * @formt: The format.
 * @func: The function associated.
 */
struct formt
{
	char formt;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formt formt_t - Struct op
  * @formt: The format
 * @ formt_t: The function associated.
 */
typedef struct formt formt_t;

int _printf(const char *format, ...);
int handle_print(const char * formt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*defining Functions*/

/* printing characters and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* printing numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* printing non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* printing memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*printing string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*printing a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*printing width handler */
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind,
char buffer[],int flags, int width, int precision, int size);

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);



/*Util definition*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int no, int size);
long int convert_size_unsgnd(unsigned long int no, int size);

#endif












