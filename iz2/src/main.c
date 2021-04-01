#include "stat.h"

int main(int argc, char ** argv) {
    // программа должна вызываться с переданным параметром именем файла
    if ( argc < 2 ) {
        printf("USAGE: %s <file_name>\n", *argv);
        exit(EXIT_FAILURE);
    }

    // счётчики
    int counters[NUM_COUNTERS] = { 0 };
    

    // открываем файл, переданный параметром, проверяем результат.
    // необходимо проверять все файловые операции, что мы далее и делаем
    FILE * inputFile = fopen(argv[1], "rb");
    if ( ! inputFile ) {
        printf("Can't open input file\n");
        exit(EXIT_FAILURE);
    }
    // получаем длину файла, для этого перемещаем файловый указатель в конец, читаем его позицию, перемещаем указатель в начало.
    if ( fseek(inputFile, 0L, SEEK_END) ) {
        printf("Can't find end of input file\n");
        exit(EXIT_FAILURE);
    }
    long fileLength = ftell(inputFile);
    if ( fileLength < 2 ) {
        printf("Input file too short or empty\n");
        exit(EXIT_FAILURE);
    }
    if ( fseek(inputFile, 0, SEEK_SET) ) {
        printf("Can't find begin of input file\n");
        exit(EXIT_FAILURE);
    }
    // создаём массив нужной длины в динамической памяти и читаем в него содержимое файла
    uint8_t * fileData = malloc(sizeof(uint8_t) * fileLength);
    if ( ! fileData ) {
        printf("Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    if ( fread(fileData, sizeof(uint8_t), (size_t)fileLength, inputFile) != (size_t)fileLength ) {
        printf("Can't get content of input file\n");
        exit(EXIT_FAILURE);
    }
    if ( fclose(inputFile) ) {
        printf("Can't properly close input file\n");
        exit(EXIT_FAILURE);
    }
    
    int num = NUM_COUNTERS;

    count(counters, fileData, fileLength, num);

  
    // выводим значения счётчиков
    printf("Diff\tCount\n");
    for ( int i = 0; i < NUM_COUNTERS; ++i )
        printf("%d\t%d\n", i, counters[i]);
        
        
        
        
    // всё!
    return 0;
}
