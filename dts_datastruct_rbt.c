#include <dts/datastruct/rbt.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <dts/datastruct/bt.h>
#include <dts/datastruct/bst.h>

static void left_rotate(rbt_t *x)
{
    rbt_t *p = x->parent;
    rbt_t *y = x->right;
    rbt_t *t = y->left;

    x->right = t;
    if (t) {
        t->parent = x;
    }
    y->parent = x->parent;
    y->left = x;
    x->parent = y;

    if (p) {
        if (p->left == x) {
            p->left = y;
        }
        else {
            p->right = y;
        }
    }
}
static void right_rotate(rbt_t *x)
{
    rbt_t *p = x->parent;
    rbt_t *y = x->left;
    rbt_t *t = y->right;

    x->left = t;
    if (t) {
        t->parent = x;
    }
    y->parent = x->parent;
    y->right = x;
    x->parent = y;

    if (p) {
        if (p->left == x) {
            p->left = y;
        }
        else {
            p->right = y;
        }
    }
}

#define RED 0
#define BLACK 1

#define IS_RED(x) ((x) && (x)->color == RED)
#define IS_BLACK(x) (!(x) || (x)->color == BLACK)
#define HAS_RED_CHILDREN(x) ((x) && (IS_RED(x->left) || IS_RED(x->right)))
#define RECOLOR(s, c) if (s) { (s)->color = c; } // NIL node cannot be recolor

static rbt_t *rbt_rotate_and_recolor(rbt_t *x)
{
    rbt_t *p = x->parent;
    while (IS_RED(p)) {
        rbt_t *g = p->parent;
        rbt_t *u = g->left == p ? g->right : g->left;
        if (IS_RED(u)) {
            RECOLOR(g, RED);
            RECOLOR(p, BLACK);
            RECOLOR(u, BLACK);
            x = g;
            p = x->parent;
        }
        else {
            if (g->left == p) {
                if (p->right == x) {
                    left_rotate(p);
                    x = p;
                    p = x->parent;
                }
                right_rotate(g);
            }
            else {
                if (p->left == x) {
                    right_rotate(p);
                    x = p;
                    p = x->parent;
                }
                left_rotate(g);
            }
            RECOLOR(g, RED);
            RECOLOR(p, BLACK);
        }
    }

    while (x->parent) {
        x = x->parent;
    }
    RECOLOR(x, BLACK);

    return x;
}
rbt_t *dts_datastruct_rbt_static_insert(rbt_t *rbt, rbt_t *node)
{
    rbt_t *x;

    x = (rbt_t *)bst_find((bst_t *)rbt, node->key);
    if (x) {
        return rbt;
    }

    rbt = (rbt_t *)bst_static_insert((bst_t *)rbt, (bst_t *)node);
    x = (rbt_t *)bst_find((bst_t *)rbt, node->key);

    return rbt_rotate_and_recolor(x);
}
static void *rbt_node_new()
{
    rbt_t *rbt = (rbt_t *)malloc(sizeof(rbt_t));
    assert(rbt);
    rbt->left = NULL;
    rbt->right = NULL;
    rbt->value = NULL;
    rbt->key = 0;
    rbt->parent = NULL;
    rbt->color = RED;
    return rbt;
}
rbt_t *dts_datastruct_rbt_insert(rbt_t *rbt, int key)
{
    rbt_t *x;

    x = (rbt_t *)bst_find((bst_t *)rbt, key);
    if (x) {
        return rbt;
    }

    rbt = (rbt_t *)bst_try_insert((bst_t *)rbt, key, rbt_node_new);
    x = (rbt_t *)bst_find((bst_t *)rbt, key);

    return rbt_rotate_and_recolor(x);
}
rbt_t *dts_datastruct_rbt_remove(rbt_t *rbt, int key)
{
    rbt_t **v, *u, *r, *s, *p;

    // Let **v be the node to be deleted and *u be the child that replaces **v
    if (bst_try_remove((bst_t **)&rbt, key, (bst_t ***)&v, (bst_t **)&u)) {
        // delete v
        p = (*v)->parent;
        if (u) {
            u->parent = (*v)->parent;
        }
        r = (*v);
        (*v) = u;

        if (IS_RED(r) || IS_RED(u)) {
            RECOLOR(u, BLACK);
        }
        else {
            while (p && IS_BLACK(u)) {
                s = p->left == u ? p->right : p->left;
                if (IS_BLACK(s)) {
                    if (HAS_RED_CHILDREN(s)) {
                        if (p->right == s) {
                            if (IS_BLACK(s->right)) { // RL3R
                                s->color = RED;
                                s->left->color = BLACK;
                                right_rotate(s);
                                s = s->parent;
                            }
                            s->right->color = BLACK; // RR3R
                            left_rotate(p);
                        }
                        else {
                            if (IS_BLACK(s->left)) { // LR3R
                                s->color = RED;
                                s->right->color = BLACK;
                                left_rotate(s);
                                s = s->parent;
                            }
                            s->left->color = BLACK; // LL3R
                            right_rotate(p);
                        }
                        break;
                    }
                    else {
                        RECOLOR(s, RED);
                        u = p;
                        p = u->parent;
                    }
                }
                else {
                    RECOLOR(p, RED);
                    RECOLOR(s, BLACK);
                    if (p->left == s) {
                        right_rotate(p);
                    }
                    else {
                        left_rotate(p);
                    }
                    p = s;
                }
            }
        }

        free(r);
    }

    while (rbt && rbt->parent) {
        rbt = rbt->parent;
    }
    rbt->color = BLACK;

    return rbt;
}
rbt_t *dts_datastruct_rbt_find(rbt_t *rbt, int key)
{
    return (rbt_t *)bst_find((bst_t *)rbt, key);
}
void dts_datastruct_rbt_delete(rbt_t *rbt)
{
    bt_delete((bt_t *)rbt);
}


static void rbt_node_print(bt_t *_bt)
{
    printf("%d|%c", ((rbt_t *)_bt)->key,
        ((rbt_t *)_bt)->color == RED ? 'R' : 'B');
}
void dts_datastruct_rbt_print(rbt_t *rbt)
{
    bt_print_ext((bt_t *)rbt, rbt_node_print);
}
