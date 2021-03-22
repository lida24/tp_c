#include "gtest/gtest.h"
extern "C" {
    #include "applications.h"
    #include "input.h"
}

TEST(Parse_application1, cin_from_keyboard) {
char name[NAME_SIZE];
char function[FUNCTION_SIZE];
int version;
int install_day;
int install_month;
int install_year;
int update_day;
int update_month;
int update_year;
char buffer[MAX_STR_SIZE] = "ljsdlj94852692698164";
ASSERT_EQ(parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year), DATA_ERR);
}
TEST(Parse_application2, wrong_input_version) {
char name[NAME_SIZE];
char function[FUNCTION_SIZE];
int version;
int install_day;
int install_month;
int install_year;
int update_day;
int update_month;
int update_year;
char buffer[MAX_STR_SIZE] = "fhgdfjg;beveqbvk;-10;02;09;2010;04;03;2020";
ASSERT_EQ(parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year), DATA_ERR);
}
TEST(Parse_application3, wrong_input_year_of_install) {
char name[NAME_SIZE];
char function[FUNCTION_SIZE];
int version;
int install_day;
int install_month;
int install_year;
int update_day;
int update_month;
int update_year;
char buffer[MAX_STR_SIZE] = "fhgdfjg;beveqbvk;10;02;09;2030;04;03;2020";
ASSERT_EQ(parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year), DATA_ERR);
}
TEST(Parse_application4, wrong_input_year_of_install) {
char name[NAME_SIZE];
char function[FUNCTION_SIZE];
int version;
int install_day;
int install_month;
int install_year;
int update_day;
int update_month;
int update_year;
char buffer[MAX_STR_SIZE] = "fhgdfjg;beveqbvk;10;02;09;2030;04;03;2020";
ASSERT_EQ(parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year), DATA_ERR);
}
TEST(Parse_application5, some_fields_was_not_input) {
char name[NAME_SIZE];
char function[FUNCTION_SIZE];
int version;
int install_day;
int install_month;
int install_year;
int update_day;
int update_month;
int update_year;
char buffer[MAX_STR_SIZE] = "fhgdfjg;;10;02;09;;04;;2020";
ASSERT_EQ(parse_application(buffer, name, function, &version, &install_day, &install_month, &install_year, &update_day, &update_month, &update_year), DATA_ERR);
}
TEST (sort, bubble1){
    application arr[3];
    arr[0].name = "qwerty";
    arr[0].function = "remove";
    arr[0].version = 1;
    arr[0].install.day = 12;
    arr[0].install.month = 1;
    arr[0].install.year = 2020;
    arr[0].update.day = 11;
    arr[0].update.month = 12;
    arr[0].update.year = 2019;
    arr[0].isUpdated = 1;
    
    arr[1].name = "ytrew";
    arr[1].function = "insert";
    arr[1].version = 4;
    arr[1].install.day = 4;
    arr[1].install.month = 5;
    arr[1].install.year = 2019;
    arr[1].update.day = 10;
    arr[1].update.month = 12;
    arr[1].update.year = 2017;
    arr[1].isUpdated = 0;
     
    arr[2].name = "ytrew";
    arr[2].function = "delete";
    arr[2].version = 4;
    arr[2].install.day = 4;
    arr[2].install.month = 5;
    arr[2].install.year = 2019;
    arr[2].update.day = 10;
    arr[2].update.month = 12;
    arr[2].update.year = 2020;
    arr[2].isUpdated = 0;
    sort(arr,3);
    ASSERT_STREQ(arr[0].function,"delete" );
    ASSERT_STREQ(arr[2].function,"remove");
    ASSERT_EQ(arr[2].version,1);
    ASSERT_EQ(arr[1].install.day,4);
}

TEST(memory_application, malloc_of_application ) {
  application* a = (application*)malloc(sizeof(application));
  EXPECT_EQ(malloc_application(a), 0);
  free(a->name);
  free(a->function);
  free(a);
}

TEST(mem_free, free_of_application) {
        application* a = (application*)malloc(sizeof(application));
        a->name = (char*)malloc(NAME_SIZE * sizeof(char));
        a->function = (char*)malloc(FUNCTION_SIZE * sizeof(char));
        EXPECT_EQ(free_application(a), 0);
        free(a);
}

TEST(application_add, null_of_application) {
      application* a = (application*)malloc(sizeof(application));
      a->name = NULL;
      a->function = NULL;
      char name[NAME_SIZE] = "excel";
      char function[FUNCTION_SIZE] = "table";
      EXPECT_EQ(add_to_application(a, name, function, 1, 2, 10, 2019, 3, 9, 2020), MEM_ERR);
      free(a);
}
TEST(application_add, null_of_aplication) {
        application* a = NULL;
        char name[NAME_SIZE] = "word";
        char function[FUNCTION_SIZE] = "text";
        ASSERT_EQ(add_to_application(a, name, function, 3, 4, 2, 2001, 3, 9, 2009), MEM_ERR);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

