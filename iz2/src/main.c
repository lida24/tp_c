#include "interface.h"



int main() {
          const char* file_path = "file.txt";

          long L1 = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

          printf("cash L1 size = %ld \n", L1);

          FILE* input_file = fopen(file_path, "rb");

          if (!input_file) {
                     printf("Can't open input file\n");

                     return FILE_ERR;
          }

          if (fseek(input_file, 0L, SEEK_END)) {
                     printf("Can't find end of input file\n");

                     return FILE_ERR;
          }

          const long file_length = ftell(input_file);

          if (file_length < 2) {
                     printf("Input file too short or empty\n");

                     return FILE_ERR;
          }

          if (fseek(input_file, 0, SEEK_SET)) {
                     printf("Can't find begin of input file\n");

                     return FILE_ERR;
          }

          uint8_t* file_data = NULL;

          posix_memalign((void**)&file_data, L1, sizeof(*file_data) * file_length);

          if (file_data == NULL) {
                     printf("fileData not allocated \n");

                     return MEM_ALLOC_ERR;
          }

          if (!file_data) {
                     printf("Not enough memory\n");

                     return MEM_ALLOC_ERR;
          }

          if (fread(file_data, sizeof(uint8_t), (size_t)file_length, input_file) != (size_t)file_length) {
                     printf("Can't get content of input file\n");

                     return FILE_ERR;
          }

          if (fclose(input_file)) {
                     printf("Can't properly close input file\n");

                     return FILE_ERR;
          }

          int counters[NUM_COUNTERS] = { 0 };

          count(counters, file_data, file_length, L1);

          free(file_data);

          printf("\nDiff\tCount\n");

          for (int i = 0; i < NUM_COUNTERS; ++i) {
                     printf("%d\t%d\n", i, counters[i]);
          }

          return 0;
}
