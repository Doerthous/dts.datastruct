#ifndef DTS_DATASTRUCT_BITMAP_H_
#define DTS_DATASTRUCT_BITMAP_H_

#include <stddef.h>
#include <stdint.h>

static inline void 
dts_datastruct_bitmap_set
(
    void *mem,
    size_t len,
    int i
)   
{
    if (i < len) {
        // bm[i / (4*8)] |= (1 << (i % (4*8)));
        ((uint32_t *)(mem))[i>>5] |= (1<<(i&0x1F)); 
    }
}

static inline void
dts_datastruct_bitmap_clear
(
    void *mem,
    size_t len,
    int i
)
{
    if (i < len) {
        ((uint32_t *)(mem))[i>>5] &= ~(1<<(i&0x1F));
    }
}

static inline int
dts_datastruct_bitmap_test
(
    void *mem,
    size_t len,
    int i
)
{
    if (i < len) {
        return !!(((uint32_t *)(mem))[i>>5] & (1<<(i&0x1F)));
    }
    return 0;
}

#endif // DTS_DATASTRUCT_BITMAP_H_
