#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void print_arg(va_list formatPtr, const char *format, int *i, int *len);
int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
void print_string(va_list formatPtr, int *len);
int print_number(long n, int flag);
void print_integer(va_list formatPtr, int *len, int flag);
int unsigned_to_binary(unsigned int num);
int print_octal(unsigned long num, int flag);
int print_unsignedNum(unsigned long num, int flag);
int print_hex(unsigned long num, int flag);
int print_HEX(unsigned long num, int flag);
int puts_with_HEX(char *str);
int check_int_flags(char flag, char spec);
int check_unsignedFlags(char flag, char spec);
int string_reverse(char *str);
int print_Address(void *address, int flag);
void extract_flags(const char *format, int *i, int *flags);
void extract_width(const char *format, int *i, int *width);
void extract_precision(const char *format, int *i, int *precision);
int _atoi(const char *s);
int is_digit(char c);
#endif
