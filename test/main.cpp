extern "C" {
#include "dts/datastruct/bt.h"
#include "dts/datastruct/bst.h"
#include "dts/datastruct/rbt.h"
}

#include <stdio.h>

int bt_node_print(bt_t *bt, void *_)
{
    printf("%c", bt->key);
    return 1;
}

int bt_node_print_d(bt_t *bt, void *_)
{
    printf("%d ", bt->key);
    return 1;
}

int bif_print(bt_ext_t *bif, void *data)
{
    printf("%d %d %p\n", bif->index, bif->level, bif->parent);
    return 1;
}

void bt_node_print_1_c(bt_t *_bt)
{
    printf("%c", ((bt_t *)_bt)->key);
}



int main()
{
    const char *in = "1234567";
    const char *post = "2315764";
    const char *pre = "4132657";

    bt_t *bt = bt_solve_from_inpostorder(in, 7, post, 7);
    bt_preorder(bt, bt_node_print, NULL);
    bt_delete(bt);

    printf("\n");

    bt = bt_solve_from_inpreorder(in, 7, pre, 7);
    bt_postorder(bt, bt_node_print, NULL);

    printf("\n");

    bst_t *bst = NULL;
    bst = bst_insert(bst, 40);
    bst = bst_insert(bst, 20);
    bst = bst_insert(bst, 70);
    bst = bst_insert(bst, 60);
    bst = bst_insert(bst, 75);
    bst = bst_insert(bst, 71);
    bst = bst_insert(bst, 73);

    bt_preorder((bt_t *)bst, bt_node_print_d, NULL);
    printf("\n");
    bt_print((bt_t *)bst);
    bt_bfs((bt_t *)bst, bt_node_print_d, NULL);
    printf("\n");

    bst = bst_remove(bst, 70);

    bt_preorder((bt_t *)bst, bt_node_print_d, NULL);
    printf("\n");

    bt_print((bt_t *)bst);
    bst = bst_remove(bst, 75);
    bt_print((bt_t *)bst);
    bst = bst_remove(bst, 71);
    bt_print((bt_t *)bst);
    bst = bst_remove(bst, 60);
    bst = bst_remove(bst, 73);
    bt_print((bt_t *)bst);
    bst = bst_insert(bst, 15);
    bt_print((bt_t *)bst);
    bst = bst_insert(bst, 13);
    bst = bst_insert(bst, 17);
    bst = bst_insert(bst, 70);
    bst = bst_insert(bst, 61);
    bst = bst_insert(bst, 50);
    bst = bst_insert(bst, 63);
    bst = bst_insert(bst, 71);
    bst = bst_insert(bst, 73);
    bt_print((bt_t *)bst);


    bt_ext_inorder((bt_t *)bst, bif_print, NULL);

    bt_print_ext(bt, bt_node_print_1_c);
    bt_delete(bt);


    struct bt_info bti;
    bt_get_info((bt_t *)bst, &bti);

    printf("depth: %d, node count: %d\n", bti.depth, bti.node_count);
    bst_delete(bst);

    rbt_t *rbt = NULL;
    rbt = rbt_insert(rbt, 20);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 15);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 15);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 13);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 12);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 11);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 10);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 9);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 8);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 7);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 6);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 5);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 4);
    rbt_print(rbt);
    rbt = rbt_insert(rbt, 3);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 2);
    rbt_print(rbt);

    rbt = rbt_insert(rbt, 1);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 1);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 2);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 9);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 11);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 14);
    rbt_print(rbt);

    rbt = rbt_remove(rbt, 7);
    rbt_print(rbt);



    return 0;
}
