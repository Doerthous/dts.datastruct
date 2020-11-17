#include <assert.h>
#include <dts/datastruct/bt.h>
#include <dts/datastruct/bst.h>

int main()
{
    bst_t *bst = NULL;
    bst_t n1 = BST_NODE(1, NULL);
    bst_t n2 = BST_NODE(2, NULL);

    bst = bst_static_insert(bst, &n1);
    bst = bst_static_insert(bst, &n2);

    dts_datastruct_bt_print((bt_t *)bst);

    return 0;
}