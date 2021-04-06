#include "stat.h"
//функция для подсчёта на интервале массива, исходные данные в targs

void ProcessIntervalCountInterval(targs* t)

{

          (*t->counter)=0;

         

          if(t->len<2)return;

         

          const uint8_t* end=t->beg + t->len - 1;

          for(const uint8_t* curr=t->beg; curr!=end; curr++)

          {

                     const uint8_t by1=*curr;

                     const uint8_t by2=*(curr+1);

                    

                     if(

                        (by2>=by1 && by2-by1==t->diff_to_check)||

                        (by1>=by2 && by1-by2==t->diff_to_check)

                        )

                     {

                               (*t->counter)++;

                     }

          }

}

 

// Функция, которая запускается в потоке. Принимает единственный параметр (ту самую структуру, которая содержит всё необходимое).

// Возвращает указатель void*, но поскольку возвращать из неё нечего, вернётся NULL

void * func_count(void * ptr)

{

          ProcessIntervalCountInterval((targs*)ptr);

          return NULL;

}


int count(int* counters, uint8_t* fileData, const long fileLength, long L1)

{      
	if(counters == NULL || fileData == NULL) {
	  return COUNT_ERR;
	}

	int allThreads = 8;
	if ( allThreads < 1 ) {
	printf("Can't get number of working processors\n");
	return SYS_ERR;
	}

          printf("allThreads = %d \n",allThreads);

	  
          pthread_t* threads=0;

          posix_memalign( (void**)&threads, L1, sizeof(*threads)*allThreads);

          if(threads==0) {
          printf(  "threads not allocated \n");
          return MEM_ALLOC_ERR;
          }

         

          // массив параметров для потоков

          targs*  targs=0;

          posix_memalign((void**)&targs, L1, sizeof(*targs)*allThreads);

          if(targs==0) {
          printf("targs not allocated \n");
          return MEM_ALLOC_ERR;
          }

         

          //пробегаем по всем счётчикам

          int* beg_counter=counters;

          int* end_counter=counters+NUM_COUNTERS;

          for (int* curr_counter=beg_counter; curr_counter<end_counter; /*curr_counter++*/)

          {

                     //очистка массивов

                     memset(threads,0,sizeof(*threads)*allThreads);

                     memset(targs  ,0,sizeof(*targs  )*allThreads);

                    

                     //запускаем текущую пачку потоков

                     for(uint32_t i=0; (i<(uint32_t)allThreads) && curr_counter<end_counter; i++,curr_counter++)

                     {

                               targs[i].beg=fileData;

                               targs[i].len=fileLength;

                               targs[i].diff_to_check=curr_counter-beg_counter;

                               targs[i].counter=curr_counter;

                              

                               //запуск потока

                               if ( pthread_create(&threads[i], NULL, func_count, &targs[i]) ) {

                                          printf("Can't create thread\n");

                                          return THREAD_ERR;

                               }

                     }

                    

                     // если после цикла остались работающие потоки, ждём их завершения

                     for ( int i = 0; i < allThreads; ++i )

                     {if(threads[i]){pthread_join(threads[i], NULL);}}

          }

         

          free(targs); targs=0;

          free(threads); threads=0;

	  return 0;

}
