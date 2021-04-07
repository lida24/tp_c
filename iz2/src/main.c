 #include "stat.h"

int main(int argc, char ** argv)

{

          const char* filepath="clip.mp4";
         
          long L1=sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

          printf("cash L1 size = %ld \n",L1);

         
          
          // открываем файл, переданный параметром, проверяем результат.

          // вообще правильно проверять все файловые операции, что мы далее и делаем

          FILE * inputFile = fopen(filepath, "rb");

          if ( ! inputFile ) {

                     printf("Can't open input file\n");

                     return FILE_ERR;

          }

          // получаем длину файла, для этого перемещаем файловый указатель в конец, читаем его позицию, перемещаем указатель в начало.

          if ( fseek(inputFile, 0L, SEEK_END) ) {

                     printf("Can't find end of input file\n");

                     return FILE_ERR;

          }

          const long fileLength = ftell(inputFile);

          if ( fileLength < 2 ) {

                     printf("Input file too short or empty\n");

                     return FILE_ERR;

          }

          if ( fseek(inputFile, 0, SEEK_SET) ) {

                     printf("Can't find begin of input file\n");

                     return FILE_ERR;

          }

         

          // создаём массив нужной длины в динамической памяти и читаем в него содержимое файла


          uint8_t*   fileData=0;

          posix_memalign( (void**)&fileData, L1, sizeof(*fileData)*fileLength);

          if(fileData==0){
          printf( "fileData not allocated \n");
          return MEM_ALLOC_ERR;
          }

 
          if ( ! fileData ) {

                     printf("Not enough memory\n");

                     return MEM_ALLOC_ERR;

          }

          if ( fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile) != (size_t)fileLength ) {

                     printf("Can't get content of input file\n");

                     return FILE_ERR;

          }

          if ( fclose(inputFile) ) {

                     printf("Can't properly close input file\n");

                     return FILE_ERR;

          }

         


          int counters[NUM_COUNTERS] = {0};

         
	  count(counters, fileData, fileLength, L1);

         

          // освобождаем память с содержимым файла

          free(fileData);

         

          // выводим значения счётчиков

          printf("\nDiff\tCount\n");

          for ( int i = 0; i < NUM_COUNTERS; ++i )

          {

                     printf("%d\t%d\n", i, counters[i]);

          }

         

          // всё!

          return 0;

}
