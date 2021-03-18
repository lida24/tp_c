#include "gtest/gtest.h"
extern "C" {
    #include "applications.h"
    #include "input.h"
}
TEST(
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
