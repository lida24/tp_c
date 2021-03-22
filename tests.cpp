#include "gtest/gtest.h"
extern "C" {
    #include "applications.h"
    #include "input.h"
}
TEST(Parse_application, cin_from_keyboard) {
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
TEST(Parse_application, wrong_input_version) {
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
TEST(Parse_application, wrong_input_year_of_install) {
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
TEST(Parse_application, wrong_input_year_of_install) {
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
TEST(Parse_application, some_fields_was_not_input) {
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
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
