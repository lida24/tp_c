#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/sysinfo.h>
#include <pthread.h>

// Количество счётчиков.
#define NUM_COUNTERS 11 

// Структура для передачи параметров в функцию, запускаемую в потоке. По определению в неё можно передать
// только один параметр, он и будет указателем на экземпляр такой структуры.
struct TARGS {
    uint8_t * fileData;
    long fileLength;
    int * counters;
    int watchFor;
};

// мьютекс для доступа к разделяемой памяти
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Функция, которая запускается в потоке. Принимает единственный параметр (ту самую структуру, которая содержит всё необходимое).
// Возвращает указатель void*, но поскольку возвращать из неё нечего, вернётся NULL
void * func_count(void * ptr) {
    struct TARGS * pta = (struct TARGS*)ptr;
    
    // В цикле по содержимому файла сравниваются два байта, если их разность равна проверяемому значению, увеличивается соответствующий счётчик
    for ( int i = 0; i < pta->fileLength - 1; ++i ) {
        pthread_mutex_lock(&mutex);
        if ( abs(pta->fileData[i] - pta->fileData[i + 1]) == pta->watchFor )
            pta->counters[pta->watchFor] += 1;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;    
}

int main(int argc, char ** argv) {
    // программа должна вызываться с переданным параметром именем файла
    if ( argc < 2 ) {
        printf("USAGE: %s <file_name>\n", *argv);
        exit(EXIT_FAILURE);
    }

    int usedThreads = 0, allThreads = get_nprocs();
    if ( allThreads < 1 ) {
        printf("Can't get number of working processors\n");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[allThreads];
    // массив параметров для потоков
    struct TARGS targs[allThreads];
    // счётчики
    int counters[NUM_COUNTERS] = { 0 };

    // открываем файл, переданный параметром, проверяем результат.
    // необходимо  проверять все файловые операции, что мы далее и делаем
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

    // в цикла по количеству счётчиков...
    for ( int cnt = 0; cnt < NUM_COUNTERS; ++cnt ) {
        // если все потоки заняты, ждём, пока они завершатся
        if ( usedThreads == allThreads ) {
            for ( int i = 0; i < usedThreads; ++i )
                pthread_join(threads[i], NULL);
            usedThreads = 0;
        }

        // Заполняем поля структуры параметров.
        targs[usedThreads].fileData = fileData;
        targs[usedThreads].fileLength = fileLength;
        targs[usedThreads].counters = counters;
        targs[usedThreads].watchFor = cnt;
        // создаём очередной поток
        if ( pthread_create(&threads[usedThreads], NULL, func_count, &targs[usedThreads]) ) {
            printf("Can't create thread\n");
            exit(EXIT_FAILURE);
        }
        // увеличиваем счётчик задействованных потоков
        ++usedThreads;
    }
    // если после цикла остались работающие потоки, ждём их завершения
    if ( usedThreads ) {
        for ( int i = 0; i < usedThreads; ++i )
            pthread_join(threads[i], NULL);
    }

    // освобождаем память с содержимым файла
    free(fileData);

    // выводим значения счётчиков
    printf("Diff\tCount\n");
    for ( int i = 0; i < NUM_COUNTERS; ++i )
        printf("%d\t%d\n", i, counters[i]);
    
    // всё!
    return 0;
}
