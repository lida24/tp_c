#include "interface.h"



void process_interval_count(targs* t) {
    (*(t->counter)) = 0;

    if (t->len < 2) return;

    const uint8_t* end = t->beg + t->len - 1;

    for (const uint8_t* curr = t->beg; curr != end; curr++) {
        const uint8_t by1 = *curr;

        const uint8_t by2 = *(curr + 1);

        if (

            (by2 >= by1 && by2 - by1 == t->diff_to_check) ||

            (by1 >= by2 && by1 - by2 == t->diff_to_check)

            ) {
            (*(t->counter))++;
        }
    }
}

void* func_count(void* thread_params_pointer) {
    process_interval_count((targs*)thread_params_pointer);

    return NULL;
}
