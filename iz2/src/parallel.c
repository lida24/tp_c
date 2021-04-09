#include "interface.h"



int count(int* counters, uint8_t* file_data, const long file_length, long L1) {
             if (counters == NULL || file_data == NULL) {
                          return COUNT_ERR;
             }

             int all_threads = 8;

             if (all_threads < 1) {
                          return SYS_ERR;
             }

             pthread_t* threads = NULL;

             if (!(threads = malloc(sizeof(*threads) * all_threads))) {
                          return MEM_ALLOC_ERR;
             }

             targs* targs = NULL;

             if (!(targs = malloc(sizeof(*targs) * all_threads))) {
                          return MEM_ALLOC_ERR;
             }

             int* beg_counter = counters;

             int* end_counter = beg_counter + NUM_COUNTERS;

             for (int* curr_counter = beg_counter; curr_counter < end_counter;) {
                          memset(threads, 0, sizeof(*threads) * all_threads);

                          memset(targs, 0, sizeof(*targs) * all_threads);

                          for (uint32_t i = 0; (i < (uint32_t)all_threads) && curr_counter < end_counter; i++, curr_counter++) {
                                       targs[i].beg = file_data;

                                       targs[i].len = file_length;

                                       targs[i].diff_to_check = curr_counter - beg_counter;

                                       targs[i].counter = curr_counter;

                                       if (pthread_create(&threads[i], NULL, func_count, &targs[i]) || !threads[i]) {
                                                    return THREAD_ERR;
                                       }
                          }

                          for (int i = 0; i < all_threads; ++i) {
                                       if (threads[i]) {
                                                    pthread_join(threads[i], NULL);
                                       }
                          }
             }

             free(targs); targs = NULL;

             free(threads); threads = NULL;

             return 0;
}
