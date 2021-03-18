#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include<time.h>


#define MEM_ERR 305

#define NAME_SIZE 30
#define FUNCTION_SIZE 30

struct date {
    int year;
    int month;
    int day;
};

typedef struct date date;

struct application {
        char* name;
        char* function;
        int version;
        struct date install;
        struct date update;
        int isUpdated;
};

typedef struct application application;



char* settime(struct tm *u);

int calculate(int year, int month, int day);

void update(application* a, date* k);

void sort(application* a, int n);

date parse_date(char* buffer, date *date);

int add_to_application(application* a, char name[NAME_SIZE],
    char function[FUNCTION_SIZE], int version, int install_day, int install_month, int install_year, int update_day, int update_month, int update_year);

int malloc_application(application* a);

int free_application(application* a);
