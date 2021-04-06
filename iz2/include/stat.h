#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <pthread.h>

#include <unistd.h>

#include <sys/sysinfo.h>

//количество счетчиков
#define NUM_COUNTERS 11

#define MEM_ALLOC_ERR 101

#define FILE_ERR 201

#define SYS_ERR 301

#define THREAD_ERR 401

#define COUNT_ERR 21

// Структура для передачи параметров в функцию, запускаемую в потоке.

struct targs

{

          const uint8_t* beg;//указатель на первый байт

          uint32_t len;//длина интервала

          uint32_t diff_to_check;//проверяемый интервал

          int* counter;//счётчик

};

typedef struct targs targs;

void ProcessIntervalCountInterval(targs* t);
void * func_count(void * ptr);
int count(int* counters, uint8_t* fileData, const long fileLength, long L1);
