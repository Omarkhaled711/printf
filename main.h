#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void print_arg(va_list formatPtr, const char *format, int *i, int *len);
int _putchar(char c);
int print_char(char c, int width);
int _printf(const char *format, ...);
int _puts(char *str);
void print_string(va_list formatPtr, int *len, int width);
int print_number(long n, int flag, int width);
void print_integer(va_list formatPtr, int *len, int flag, int width);
int unsigned_to_binary(unsigned int num);
int print_octal(unsigned long num, int flag, int width);
int print_unsignedNum(unsigned long num, int flag, int width);
int print_hex(unsigned long num, int flag, int width);
int print_HEX(unsigned long num, int flag, int width);
int puts_with_HEX(char *str);
int check_int_flags(char flag, char spec);
int check_unsignedFlags(char flag, char spec);
int string_reverse(char *str);
int print_Address(void *address, int flag);
void extract_flags(const char *format, int *i, int *flags);
void extract_width(const char *format, int *i, int *width,
		va_list formatPtr, int flags);
void extract_precision(const char *format, int *i, int *precision);
int _atoi(const char *s);
int is_digit(char c);
int rot13(const char *s);
int _strlen(char *s);
int deal_width(int len, int width, int *flag);
int count_hex_digits(unsigned long num);
int count_oct_digits(unsigned long num);
int count_undigits(unsigned long num);


#endif
