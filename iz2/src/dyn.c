#include "stat.h"
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
void count(int* counters, uint8_t* fileData, long fileLength, int num) {
    int usedThreads = 0, allThreads = get_nprocs();
     if ( allThreads < 1 ) {
        printf("Can't get number of working processors\n");
        exit(EXIT_FAILURE);
    }
    pthread_t threads[allThreads];
    // массив параметров для потоков
    struct TARGS targs[allThreads];
    // в цикла по количеству счётчиков...
    for ( int cnt = 0; cnt < num; ++cnt ) {
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
        if (pthread_create(&threads[usedThreads], NULL, func_count, &targs[usedThreads]) ) {
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
}

