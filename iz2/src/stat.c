#include"stat.h"
void count(int* counters, uint8_t* fileData, long fileLength, int num){
 printf("\n\n\n\n\n %d \n\n\n\n\n", num);
 printf("\n\n\n\n\n %ld \n\n\n\n\n", fileLength);
    for ( int i = 0; i < num; ++i ) 
        for ( long j = 0; j < fileLength - 1; ++j )
            if ( abs(fileData[j] - fileData[j + 1]) == i )
                counters[i] += 1;
               
// освобождаем память с содержимым файла
    free(fileData);

}


    
