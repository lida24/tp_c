#include "applications.h"

int add_to_application(application* a, char name[NAME_SIZE],
    char function[FUNCTION_SIZE], int version, int install_day, int install_month, int install_year, int update_day, int update_month, int update_year) {
    if (a == NULL) {
return MEM_ERR;
}
if (a->name == NULL) {
return MEM_ERR;
}
strcpy(a->name, name);
if (a->function == NULL) {
return MEM_ERR;
}
strcpy(a->function, function);
a->version = version;
a->install.day = install_day;
a->install.month = install_month;
a->install.year = install_year;
a->update.day = update_day;
a->update.month = update_month;
a->update.year = update_year;
    return 0;
}


date parse_date(char* buffer, date *date){
char* cal = strsep(&buffer, ".");
date->day = atoi(cal);
cal = strsep(&buffer, ".");
date->month = atoi(cal);
cal = strsep(&buffer, "\0");
date->year = atoi(cal);
return *date;
}

char* settime(struct tm *u)
  {  
    char s[40];
    char *tmp;
    for (int i = 0; i<40; i++) s[i] = 0;
    int length = strftime(s, 40, "%d.%m.%Y", u);
    tmp = (char*)malloc(sizeof(s));
    strcpy(tmp, s);
    return(tmp);
  }

int  calculate(int year, int month, int day){
       if (month < 3)
             year--, month +=12;

             return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

void update(application* a, date* k){
    a->update.day = k->day;
    a->update.month = k->month;
    a->update.year = k->year;
    a->isUpdated = 1;
    a->version++;
}

void sort(application* a, int n) {
       application* tmp = malloc(40 * sizeof(application));
  for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
                  if(strcmp(a[i].function, a[j].function) < 0){
                          tmp->name = a[i].name;
                          tmp->function = a[i].function;
                          tmp->version = a[i].version;
                          tmp->install.day = a[i].install.day;
                          tmp->install.month = a[i].install.month;
                          tmp->install.year = a[i].install.year;
                          tmp->update.day = a[i].update.day;
                          tmp->update.month = a[i].update.month;
                          tmp->update.year = a[i].update.year;
                          tmp->isUpdated = a[i].isUpdated;
                          a[i].name = a[j].name;
                          a[i].function = a[j].function;
                          a[i].version = a[j].version;
                          a[i].install.day = a[j].install.day;
                          a[i].install.month = a[j].install.month;
                          a[i].install.year = a[j].install.year;
                          a[i].update.day = a[j].update.day;
                          a[i].update.month = a[j].update.month;
                          a[i].update.year = a[j].update.year;
                          a[i].isUpdated = a[j].isUpdated;
                          a[j].name = tmp->name;
                          a[j].function = tmp->function;
                          a[j].version = tmp->version;
                          a[j].install.day = tmp->install.day;
                          a[j].install.month = tmp->install.month;
                          a[j].install.year = tmp->install.year;
                          a[j].update.day = tmp->update.day;
                          a[j].update.month = tmp->update.month;
                          a[j].update.year = tmp->update.year;
                          a[j].isUpdated = tmp->isUpdated;

                  }
          }
  }
  free(tmp);
}

int malloc_application(application* a) {
    a->name = malloc(NAME_SIZE * sizeof(char));
    if (a->name == NULL) {
        return MEM_ERR;
    }
    a->function = malloc(FUNCTION_SIZE * sizeof(char));
    if (a->function == NULL) {
        return MEM_ERR;
    }
    return 0;
}

int free_application(application* a) {
    if (a == NULL) {
        return MEM_ERR;
    }
    if (a->name != NULL) {
        free(a->name);
        a->name = NULL;
        }
    if (a->function != NULL) {
        free(a->function);
        a->function = NULL;
    }
    return 0;
}

