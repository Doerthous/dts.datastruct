#include <dts/datastruct/bt.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int
dts_datastruct_bt_preorder
(
    bt_t *bt,
    int (*op)(bt_t *, void *),
    void *d
)
{
    if (bt)
        if (op(bt, d))
            if (dts_datastruct_bt_preorder(bt->left, op, d))
                return dts_datastruct_bt_preorder(bt->right, op, d);
    return 1;
}

int
dts_datastruct_bt_inorder
(
    bt_t *bt,
    int (*op)(bt_t *, void *),
    void *d
)
{
    if (bt)
        if (dts_datastruct_bt_inorder(bt->left, op, d))
            if (op(bt, d))
                return dts_datastruct_bt_inorder(bt->right, op, d);
    return 1;
}

int
dts_datastruct_bt_postorder
(
    bt_t *bt,
    int (*op)(bt_t *, void *),
    void *d
)
{
    if (bt)
        if (dts_datastruct_bt_postorder(bt->left, op, d))
            if (dts_datastruct_bt_postorder(bt->right, op, d))
                return op(bt, d);
    return 1;
}

static int
bt_ext_inorder_recur(bt_ext_t *me, int (*op)(bt_ext_t *, void *), void *data)
{
    bt_ext_t child;

    if (me->node) {
        child.level = me->level+1;
        child.parent = me;

        child.index = me->index;
        child.node = me->node->left;
        if (!bt_ext_inorder_recur(&child, op, data)) {
            return 0;
        }
        me->index = child.index;

        if (!op(me, data)) {
            return 0;
        }
        me->index += 1;

        child.index = me->index;
        child.node = me->node->right;
        if (!bt_ext_inorder_recur(&child, op, data)) {
            return 0;
        }
        me->index = child.index;
    }

    return 1;
}
void
dts_datastruct_bt_ext_inorder
(
    bt_t *bt,
    int (*op)(bt_ext_t *, void *),
    void *data
)
{
    bt_ext_t me;

    me.parent = NULL;
    me.level = 1;
    me.index = 0;
    me.node = bt;

    bt_ext_inorder_recur(&me, op, data);
}

static void bt_print_recur(bt_ext_t *bt, bt_ext_t *me, void (*print)(bt_t *))
{
    if (bt) {
        bt_ext_t *p = bt->parent;
        bt_print_recur(p, me, print);
        if (p) {
            bt_ext_t *g = p->parent;
            if (g && (g->node->left == bt->parent->node && p->node->right == bt->node ||
                g->node->right == bt->parent->node && p->node->left == bt->node)) {
                printf(" | ");
                if (bt == me) {
                    printf("%s", p->node->left == me->node ? " / " : " \\ ");
                    print(me->node);
                    printf("\n");
                }
            }
            else {
                printf("   ");
                if (bt == me) {
                    printf("%s", p->node->left == me->node ? " / " : " \\ ");
                    print(me->node);
                    printf("\n");
                }
            }
        }
        else {
            if (bt == me) {
                printf("   ");
                print(me->node);
                printf("\n");
            }
        }
    }
}
static int bt_print_iter(bt_ext_t *me, void *print)
{
    bt_print_recur(me, me, (void (*)(bt_t *))print);
    return 1;
}
void
dts_datastruct_bt_print_ext
(
    bt_t *bt,
    void (*print)(bt_t *)
)
{
    dts_datastruct_bt_ext_inorder(bt, bt_print_iter, (void *)print);
    printf("\n");
}
static int bt_node_print(bt_t *bt)
{
    printf("%d ", bt->key);
    return 1;
}
void
dts_datastruct_bt_print
(
    bt_t *bt
)
{
    dts_datastruct_bt_print_ext(bt, bt_node_print);
}


static int bt_get_info_iter(bt_ext_t *bt, void *_bti)
{
    struct bt_info *bti = (struct bt_info *)_bti;
    if (bt->index+1 > bti->node_count) {
        bti->node_count = bt->index+1;
    }
    if (bt->level > bti->depth) {
        bti->depth = bt->level;
    }
    return 1;
}
void
dts_datastruct_bt_get_info
(
    bt_t *bt,
    struct bt_info *bti
)
{
    dts_datastruct_bt_ext_inorder(bt, bt_get_info_iter, (void *)bti);
}


// memory alloc enable

bt_t *
dts_datastruct_bt_solve_from_inpostorder
(
    const char *in,
    int in_len,
    const char *post,
    int post_len
)
{
    if (post_len > 0) {
        int i;
        bt_t *r = (bt_t *)malloc(sizeof(bt_t));
        assert(r);

        r->key = post[post_len-1];
        for (i = 0; i < in_len && in[i] != r->key; ++i);
        r->left = dts_datastruct_bt_solve_from_inpostorder(in, i, post, i);
        r->right = dts_datastruct_bt_solve_from_inpostorder(in+i+1, in_len-i-1,
            post+i, post_len-i-1);
        return r;
    }

    return NULL;
}

bt_t *
dts_datastruct_bt_solve_from_inpreorder
(
    const char *in,
    int in_len,
    const char *pre,
    int pre_len
)
{
    if (pre_len > 0) {
        int i;
        bt_t *r = (bt_t *)malloc(sizeof(bt_t));
        assert(r);

        r->key = pre[0];
        for (i = 0; i < in_len && in[i] != r->key; ++i);
        r->left = dts_datastruct_bt_solve_from_inpreorder(in, i, pre+1, i);
        r->right = dts_datastruct_bt_solve_from_inpreorder(in+i+1, in_len-i-1,
            pre+1+i, pre_len-i-1);
        return r;
    }

    return NULL;
}


static int bt_free_op(bt_t *bt, void *_)
{
    free(bt);
    return 1;
}
void
dts_datastruct_bt_delete
(
    bt_t *bt
)
{
    dts_datastruct_bt_postorder(bt, bt_free_op, NULL);
}

#include "dts/datastruct/list.h"
struct list_node
{
    struct list_node *next;
    bt_t *bt;
};
static inline struct list_node *list_node_new(bt_t *bt)
{
    struct list_node *list = (struct list_node *)malloc(sizeof(struct list_node));
    list->next = NULL;
    list->bt = bt;
    return list;
}
int
dts_datastruct_bt_bfs
(
    bt_t *bt,
    int (*op)(bt_t *, void *),
    void *d
)
{
    list_t list;
    struct list_node *node;

    if (bt) {
        list_init(&list);
        list_enqueue(&list, list_node_new(bt));
    }

    while (list_length(&list)) {
        node = list_dequeue(&list);
        if (!op(node->bt, d)) {
            free(node);
            return 0;
        }

        if (node->bt->left) {
            list_enqueue(&list, list_node_new(node->bt->left));
        }
        if (node->bt->right) {
            list_enqueue(&list, list_node_new(node->bt->right));
        }

        free(node);
    }

    return 1;
}
