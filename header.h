#ifndef __HEADER__
#define __HEADER__

/* This file contains all needed header files */

/* Headers */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/* Functions */
int len(char *s);
void w(char *s);
char *input(void);
int print_word(char *s, int arr[]);

#endif