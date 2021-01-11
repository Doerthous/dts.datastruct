#include <dts/algorithm/qsort.h>
#include <stdlib.h>

#define ARR(i) (((unsigned char *)base)+((i)*(ele_sz)))
static void SWAP(void *i, void *j, size_t ele_sz, void *sw_mem)
{
    memcpy(sw_mem, i, ele_sz);
    memcpy(i, j, ele_sz);
    memcpy(j, sw_mem, ele_sz);
}


void
dts_algorithm_qsort
(
    void *base,
    size_t ele_cnt,
    size_t ele_sz,
    int (*compar)(const void *, const void*, void *),
    void *data
)
{
    void *sw_mem;
    int p, r, l;


    if (ele_cnt <= 1) {
        return;
    }

    sw_mem = malloc(ele_sz);

    // 1. find pivot
    p = 0;

    // 2. swap pivot to last position
    SWAP(ARR(p), ARR(ele_cnt-1), ele_sz, sw_mem);

    // 3. compare all elements with pivot
    p = ele_cnt-1;
    l = 0;
    r = p;
    while (l < r) {
        if (compar(ARR(l), ARR(p), data) > 0) {
            --r;
            SWAP(ARR(l), ARR(r), ele_sz, sw_mem);
        }
        else {
            ++l;
        }
    }

    if (compar(ARR(l), ARR(p), data) > 0) {
        SWAP(ARR(l), ARR(p), ele_sz, sw_mem);
    }

    free(sw_mem);

    // 4. recur for sub-problem
    dts_algorithm_qsort(ARR(0), l, ele_sz, compar, data);
    dts_algorithm_qsort(ARR(l+1), ele_cnt-l-1, ele_sz, compar, data);
}
