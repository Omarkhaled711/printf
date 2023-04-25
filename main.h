#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


void print_arg(va_list formatPtr, const char *format, int *i, int *len);
int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
int print_number(int n, int flag);
int unsigned_to_binary(unsigned int num);
int print_octal(unsigned int num, int flag);
int print_unsignedNum(unsigned int num);
int print_hex(unsigned int num, int flag);
int print_HEX(unsigned int num, int flag);
int puts_with_HEX(char *str);
int check_int_flags(char flag, char spec);
int check_unsignedFlags(char flag, char spec);
void string_reverse(char *str);

#endif
