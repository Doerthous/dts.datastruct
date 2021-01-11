#ifndef DTS_ALGORITHM_QSORT_H_
#define DTS_ALGORITHM_QSORT_H_

#include <stddef.h>

void
dts_algorithm_qsort
(
    void *base, 
    size_t nitems, 
    size_t size, 
    int (*compar)(const void *, const void*, void *), 
    void *data
);

#endif // DTS_ALGORITHM_QSORT_H_
