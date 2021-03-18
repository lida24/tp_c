#include "input.h"

int parse_application(char buffer[MAX_STR_SIZE], char* name, char* function, int* version, int* install_day, int* install_month, int* install_year, int* update_day, int* update_month, int* update_year) {
   int buf_version, buf_install_day, buf_install_month, buf_install_year, buf_update_day, buf_update_month, buf_update_year;
if(sscanf(buffer, "%[a-zA-Z];%[a-zA-Z];%d;%d;%d;%d;%d;%d;%d", name, function, &buf_version, &buf_install_day, &buf_install_month, &buf_install_year, &buf_update_day, &buf_update_month, &buf_update_year) != 9){
        return DATA_ERR;
}
if(buf_version < 0) {
       return DATA_ERR;
}
if(buf_install_day < 0 || buf_install_day > 31 || buf_install_month < 0 || buf_install_month > 12 || buf_install_year < 0 || buf_install_year > 2021) {
  return DATA_ERR;
}
if(buf_update_day < 0 || buf_update_day > 31 || buf_update_month < 0 || buf_update_month > 12 || buf_update_year < 0 || buf_update_year > 2021) {
  return DATA_ERR;
}
*version = buf_version;
*install_day = buf_install_day;
*install_month = buf_install_month;
*install_year = buf_install_year;
*update_day = buf_update_day;
*update_month = buf_update_month;
*update_year = buf_update_year;
return 0;
}
