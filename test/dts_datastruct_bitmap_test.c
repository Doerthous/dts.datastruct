#include <stdio.h>
#include <assert.h>
#include <dts/datastruct/bitmap.h>

int main()
{
    uint8_t mem[128];

    memset(mem, 0, 128);

    for (int i = 0; i < 128; ++i)
        assert(!bitmap_test(mem, 128, i));
    
    bitmap_set(mem, 128, 127);
    bitmap_set(mem, 128, 64);
    bitmap_set(mem, 128, 63);
    bitmap_set(mem, 128, 0);

    assert(bitmap_test(mem, 128, 127));
    assert(bitmap_test(mem, 128, 64));
    assert(bitmap_test(mem, 128, 63));
    assert(bitmap_test(mem, 128, 0));

    bitmap_clear(mem, 128, 127);
    bitmap_clear(mem, 128, 64);
    bitmap_clear(mem, 128, 63);
    bitmap_clear(mem, 128, 0);

    assert(!bitmap_test(mem, 128, 127));
    assert(!bitmap_test(mem, 128, 64));
    assert(!bitmap_test(mem, 128, 63));
    assert(!bitmap_test(mem, 128, 0));

    return 0;
}