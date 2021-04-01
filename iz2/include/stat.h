#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include<malloc.h>

//количество счетчиков
#define NUM_COUNTERS 11

void count(int* counters, uint8_t* fileData, long fileLength, int num);
void * func_count(void * ptr);
