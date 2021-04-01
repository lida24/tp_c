#include "gtest/gtest.h"

extern "C" {
 #include "stat.h"
}

TEST(test_algo, test_count){
        int *counters = (int*)malloc(sizeof(int) * 11);
        FILE * inputFile = fopen64("/home/lida/TechnoPark/yz/tp_c/iz2/tests/clip.mp4", "rb");
        long fileLength = ftell(inputFile);
        uint8_t * fileData = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * fileLength));
        fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
        
        int num = NUM_COUNTERS;
        count(counters, fileData, fileLength, num);
        EXPECT_EQ(counters[0], 425185);
        EXPECT_EQ(counters[1], 414400);
        EXPECT_EQ(counters[2], 380482);
        EXPECT_EQ(counters[3], 343332);
        EXPECT_EQ(counters[4], 343950);
        EXPECT_EQ(counters[5], 335233);
        EXPECT_EQ(counters[6], 350155);
        EXPECT_EQ(counters[7], 332710);
        EXPECT_EQ(counters[8], 336482);
        EXPECT_EQ(counters[9], 327771);
        EXPECT_EQ(counters[10], 323957);
}

int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
