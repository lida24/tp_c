#include "interface.h"



int count(int* counters, uint8_t* file_data, const long file_length, long L1) {
          if (counters == NULL || file_data == NULL) {
                     return COUNT_ERR;
          }

          int all_threads = get_nprocs();

          if (all_threads < 1) {
                     return SYS_ERR;
          }

          int* beg_counter = counters;

          int* end_counter = counters + NUM_COUNTERS;

          for (int* curr_counter = beg_counter; curr_counter < end_counter; curr_counter++) {
                     targs t = { 0 };

                     t.beg = file_data;

                     t.len = file_length;

                     t.diff_to_check = curr_counter - beg_counter;

                     t.counter = curr_counter;

                     process_interval_count(&t);
          }

          return 0;
}
