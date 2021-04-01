#include"stat.h"
void count(int* counters, uint8_t* fileData, long fileLength, int num){
    for ( int i = 0; i < num; ++i ) 
        for ( long j = 0; j < fileLength - 1; ++j )
            if ( abs(fileData[j] - fileData[j + 1]) == i )
                counters[i] += 1;
// освобождаем память с содержимым файла
    free(fileData);

}


    
