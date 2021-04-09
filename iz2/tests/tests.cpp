#include "gtest/gtest.h"

extern "C" {
#include "interface.h"
}

struct s_counterX {
    const uint32_t diff;

    int counter;
};

typedef struct s_counterX s_counterX;


// увеличивает счётчик
//
// увеличивает число и возвращает его

uint8_t Testing_ApplyCounterX_add(const uint8_t numX, s_counterX* counterX) {
          counterX->counter++;

          return (uint8_t)(numX+counterX->diff);
}

// увеличивает счётчик

// уменьшает число и возвращает его

uint8_t Testing_ApplyCounterX_sub(const uint8_t numX, s_counterX* counterX) {
          counterX->counter++;

          return (uint8_t)(numX-counterX->diff);
}

TEST(test_process_interval_count, test_count_diff_345) {
      // набор тестируемых разниц

                     s_counterX counter3 {3, 0};

                     s_counterX counter4 {4, 0};

                     s_counterX counter5 {5, 0};

                     // заполнение элементов и контрольных счётчиков разниц

                     const uint8_t num0 = 0;

                     // add

                     const uint8_t num1 = Testing_ApplyCounterX_add(num0, &counter3);

                     const uint8_t num2 = Testing_ApplyCounterX_add(num1, &counter5);

                     const uint8_t num3 = Testing_ApplyCounterX_add(num2, &counter3);

                     const uint8_t num4 = Testing_ApplyCounterX_add(num3, &counter4);

                     const uint8_t num5 = Testing_ApplyCounterX_add(num4, &counter5);

                     const uint8_t num6 = Testing_ApplyCounterX_add(num5, &counter5);

                     // sub

                     const uint8_t num7 = Testing_ApplyCounterX_sub(num6, &counter4);

                     const uint8_t num8 = Testing_ApplyCounterX_sub(num7, &counter5);

                     const uint8_t num9 = Testing_ApplyCounterX_sub(num8, &counter4);

                     // тестируемый массив

                     const uint8_t  array[] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

                     const uint32_t array_len = sizeof(array)/sizeof(*array);
                     // массив с тестовыми счётчиками

                     const s_counterX arrayX[] = {counter3, counter4, counter5};

                     const uint32_t arrayX_len = sizeof(arrayX)/sizeof(*arrayX);

                     for (size_t i_X = 0; i_X < arrayX_len; i_X++) {
                               const s_counterX* counterX = &arrayX[i_X];

                               int counter = 0;
                               {
                                          targs t { array, array_len, counterX->diff, &counter};

                                         process_interval_count(&t);
                               }

                               EXPECT_EQ(counter, counterX->counter);
                     }
}
TEST(test_process_interval_count, test_count_diff_567) {
      // набор тестируемых разниц

                     s_counterX counter5 {5, 0};

                     s_counterX counter6 {6, 0};

                     s_counterX counter7 {7, 0};

                     // заполнение элементов и контрольных счётчиков разниц

                     const uint8_t num0 = 0;

                     // add

                     const uint8_t num1 = Testing_ApplyCounterX_add(num0, &counter5);

                     const uint8_t num2 = Testing_ApplyCounterX_add(num1, &counter6);

                     const uint8_t num3 = Testing_ApplyCounterX_add(num2, &counter6);

                     const uint8_t num4 = Testing_ApplyCounterX_add(num3, &counter5);

                     const uint8_t num5 = Testing_ApplyCounterX_add(num4, &counter7);

                     const uint8_t num6 = Testing_ApplyCounterX_add(num5, &counter7);

                     // sub

                     const uint8_t num7 = Testing_ApplyCounterX_sub(num6, &counter7);

                     const uint8_t num8 = Testing_ApplyCounterX_sub(num7, &counter5);

                     const uint8_t num9 = Testing_ApplyCounterX_sub(num8, &counter6);

                     // тестируемый массив

                     const uint8_t  array[] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

                     const uint32_t array_len = sizeof(array)/sizeof(*array);

                     // массив с тестовыми счётчиками

                     const s_counterX arrayX[] = {counter5, counter6, counter7};

                     const uint32_t arrayX_len = sizeof(arrayX)/sizeof(*arrayX);

                     for (size_t i_X = 0; i_X < arrayX_len; i_X++) {
                               const s_counterX* counterX = &arrayX[i_X];

                               int counter = 0;
                               {
                                        targs t { array, array_len, counterX->diff, &counter};

                                         process_interval_count(&t);
                               }


                               EXPECT_EQ(counter, counterX->counter);
                     }
}

TEST(test_process_interval_count, test_count_diff_148) {
      // набор тестируемых разниц

                     s_counterX counter1 {1, 0};

                     s_counterX counter4 {4, 0};

                     s_counterX counter8 {8, 0};

                     // заполнение элементов и контрольных счётчиков разниц

                     const uint8_t num0 = 0;

                     // add

                     const uint8_t num1 = Testing_ApplyCounterX_add(num0, &counter8);

                     const uint8_t num2 = Testing_ApplyCounterX_add(num1, &counter4);

                     const uint8_t num3 = Testing_ApplyCounterX_add(num2, &counter1);

                     const uint8_t num4 = Testing_ApplyCounterX_add(num3, &counter4);

                     const uint8_t num5 = Testing_ApplyCounterX_add(num4, &counter8);

                     const uint8_t num6 = Testing_ApplyCounterX_add(num5, &counter1);

                     // sub

                     const uint8_t num7 = Testing_ApplyCounterX_sub(num6, &counter1);

                     const uint8_t num8 = Testing_ApplyCounterX_sub(num7, &counter8);

                     const uint8_t num9 = Testing_ApplyCounterX_sub(num8, &counter4);
                     // тестируемый массив

                     const uint8_t  array[] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

                     const uint32_t array_len = sizeof(array)/sizeof(*array);

                     // массив с тестовыми счётчиками

                     const s_counterX arrayX[] = {counter1, counter4, counter8};

                     const uint32_t arrayX_len = sizeof(arrayX)/sizeof(*arrayX);

                     for (size_t i_X = 0; i_X < arrayX_len; i_X++) {
                               const s_counterX* counterX = &arrayX[i_X];

                               int counter = 0;

                               {
                                         targs t { array, array_len, counterX->diff, &counter};

                                         process_interval_count(&t);
                               }

                               EXPECT_EQ(counter, counterX->counter);
                     }
}

TEST(test_algo, test_count_mp4) {

    const char* filePath = "clip.mp4";
    
    long L1 = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

    FILE * inputFile = fopen(filePath, "rb");
    
    fseek(inputFile, 0L, SEEK_END);

    const long fileLength = ftell(inputFile);

    fseek(inputFile, 0, SEEK_SET);

    uint8_t* fileData = NULL;

    posix_memalign( (void**)&fileData, L1, sizeof(*fileData)*fileLength );

    fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
    
    int counters[NUM_COUNTERS] = {0};
    
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
    
    free(fileData);

}   

TEST(test_algo, test_count_txt) {

    const char* filePath = "file.txt";
    
    long L1 = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

    FILE * inputFile = fopen(filePath, "rb");
    
    fseek(inputFile, 0L, SEEK_END);

    const long fileLength = ftell(inputFile);

    fseek(inputFile, 0, SEEK_SET);

    uint8_t* fileData = NULL;

    posix_memalign( (void**)&fileData, L1, sizeof(*fileData)*fileLength );

    fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
    
    int counters[NUM_COUNTERS] = {0};
    
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
    
    free(fileData);
}

TEST(test_algo, test_count_jpg) {

    const char* filePath = "image.jpg";
    
    long L1 = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

    FILE * inputFile = fopen(filePath, "rb");
    
    fseek(inputFile, 0L, SEEK_END);

    const long fileLength = ftell(inputFile);

    fseek(inputFile, 0, SEEK_SET);

    uint8_t* fileData = NULL;

    posix_memalign( (void**)&fileData, L1, sizeof(*fileData)*fileLength );

    fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile);
    
    int counters[NUM_COUNTERS] = {0};
    
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
    
    free(fileData);
}
int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
