#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define DATA_ERR 200
#define MAX_STR_SIZE 100

int parse_application(char buffer[MAX_STR_SIZE], char* name, char* function, int* version, int* install_day, int* install_month, int* install_year, int* update_day, int* update_month, int* update_year);

