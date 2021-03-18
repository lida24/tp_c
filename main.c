#include "applications.h"
#include<time.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    application* a = malloc(n * sizeof(application));
    char* buffer = malloc(MAX_STR_SIZE *sizeof(char));
    if (a == NULL) {
        printf("Error\n");
        return MEM_ERR;
    }
    if (buffer == NULL) {
        printf("Error");
        free(a);
        return MEM_ERR;
        }

    for (int i = 0; i < n; i++) {
        if (malloc_application(&a[i])) {
            printf("Error\n");
            free(a);
            free(buffer);
            return MEM_ERR;
        }
        char name[NAME_SIZE];
        char function[FUNCTION_SIZE];
        int version;
        int install_day;
        int install_month;
        int install_year;
        int update_day;
        int update_month;
        int update_year;
        do {
            printf("Enter %d data of applications, in format:  name;function;version;date_install;date_update\n", i+1);
            scanf("%99s", buffer);
        } while (parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year) == DATA_ERR);
        add_to_application(&a[i], name, function, version, install_day, install_month, install_year, update_day, update_month, update_year);
        a[i].isUpdated = 0;

    }

    free(buffer);
    buffer = NULL;

    struct tm *u;
        char *f;
        const time_t timer = time(NULL);
        u = localtime(&timer);
        f = settime(u);
        puts(f);
        date k;
        parse_date(f, &k);
        printf("%d %d %d\n", k.day, k.month, k.year);
        for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                update(&a[i], &k);
                }
        }
        sort(a, n);
        for(int i = 0; i < n; i++){
              int h =  calculate(a[i].install.year, a[i].install.month, a[i].install.day);
              int l = calculate(k.year, k.month, k.day);
              if(l - h >= 182 && a[i].isUpdated == 0){
                 printf("%s %s %d %d.%d.%d %d.%d.%d\n", a[i].name, a[i].function, a[i].version, a[i].install.day, a[i].install.month, a[i].install.year, a[i].update.day, a[i].update.month, a[i].update.year);
              }
        }
     for(int i = 0; i < n; i++){
       free_application(&a[i]);
     }     
//free(d);
free(f);
  free(a);
  a = NULL;

    return 0;
}
