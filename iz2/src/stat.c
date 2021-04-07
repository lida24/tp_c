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

	  int allThreads = get_nprocs();

	  if ( allThreads < 1 ) {
	  printf("Can't get number of working processors\n");
	  return SYS_ERR;
	  }


          printf("allThreads = %d \n",allThreads);
	   
	  int* beg_counter=counters;

          int* end_counter=counters+NUM_COUNTERS;

          for (int* curr_counter=beg_counter; curr_counter<end_counter; curr_counter++)

          {

              	     targs t = {0};

 

                     t.beg=fileData;

                     t.len=fileLength;

                     t.diff_to_check=curr_counter-beg_counter;

                     t.counter=curr_counter;

                              

                     //запуск

                     ProcessIntervalCountInterval(&t);

          }
          
          return 0;

}
