#include <assert.h>
#include <dts/datastruct/bt.h>
#include <dts/datastruct/rbt.h>

int main()
{
    rbt_t *rbt = NULL;
    rbt_t n[10];
    
    for (int i = 0; i < 10; ++i) {
        n[i] = RBT_NODE_EX(i, NULL);
        rbt = rbt_static_insert(rbt, n+i);
    }

    rbt_print(rbt);

    return 0;
}