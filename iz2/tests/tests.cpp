#include "gtest/gtest.h"

extern "C" {
 #include "stat.h"
}

TEST(test_algo, test_count_mp4){
	

        int *counters = (int*)malloc(sizeof(int) * NUM_COUNTERS);
	

        FILE *inputFile = fopen("clip.mp4", "rb");
	

        long fileLength = ftell(inputFile);

        long L1=sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
	

        uint8_t * fileData = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * fileLength));
	

        fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
	

        count(counters, fileData, fileLength, L1);
	

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

TEST(test_algo, test_count_txt){
	

        int *counters = (int*)malloc(sizeof(int) * NUM_COUNTERS);
	

        FILE *inputFile = fopen("file.txt", "rb");
	

        long fileLength = ftell(inputFile);
        
	      long L1=sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

        uint8_t * fileData = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * fileLength));
	

        fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
	

        count(counters, fileData, fileLength, L1);
	

        EXPECT_EQ(counters[0], 18);
	

        EXPECT_EQ(counters[1], 9);
	

        EXPECT_EQ(counters[2], 10);
	

        EXPECT_EQ(counters[3], 13);
	

        EXPECT_EQ(counters[4], 2);
	

        EXPECT_EQ(counters[5], 5);
	

        EXPECT_EQ(counters[6], 3);
	

        EXPECT_EQ(counters[7], 3);
	

        EXPECT_EQ(counters[8], 7);
	

        EXPECT_EQ(counters[9], 4);
	

        EXPECT_EQ(counters[10], 2);
}


TEST(test_algo, test_count_jpg){
	

        int *counters = (int*)malloc(sizeof(int) * NUM_COUNTERS);
	

        FILE *inputFile = fopen("image.jpg", "rb");
	

        long fileLength = ftell(inputFile);

	      long L1=sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

        uint8_t * fileData = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * fileLength));
	

        fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
	

        count(counters, fileData, fileLength, L1);
	

        EXPECT_EQ(counters[0], 4686);
	

        EXPECT_EQ(counters[1], 6758);
	

        EXPECT_EQ(counters[2], 6277);
	

        EXPECT_EQ(counters[3], 6037);
	

        EXPECT_EQ(counters[4], 6387);
	

        EXPECT_EQ(counters[5], 5700);
	

        EXPECT_EQ(counters[6], 5618);
	

        EXPECT_EQ(counters[7], 5658);
	

        EXPECT_EQ(counters[8], 6394);
	

        EXPECT_EQ(counters[9], 5750);
	

        EXPECT_EQ(counters[10], 5607);
}

int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
