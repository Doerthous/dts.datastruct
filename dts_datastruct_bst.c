#include "dts_datastruct_bst.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dts/datastruct/bt.h"

#define bst_t dts_datastruct_bst_t

static bst_t *bst_find_min(bst_t *bst)
{
    if (bst) {
        while (bst->left) {
            bst = bst->left;
        }
    }

    return bst;
}

int dts_datastruct_bst_try_remove(bst_t **bst, int key, bst_t ***v, bst_t **u)
{
    bst_t *real, *try;

    if ((try = dts_datastruct_bst_find(*bst, key)) == NULL) {
        return 0;
    }
    if (try->left == NULL || try->right == NULL) {
        real = try;
    }
    else {
        real = bst_find_min(try->right);
    }
    if (try != real) {
        try->key = real->key;
    }

    if (real->parent == NULL) {
        *v = bst;
    }
    else if (real->parent->left == real) {
        *v = &(real->parent->left);
    }
    else {
        *v = &(real->parent->right);
    }

    if (real->left == NULL && real->right == NULL) {
        *u = NULL;
    }
    else {
        *u = real->left != NULL ? real->left : real->right;
    }

    return 1;
}

bst_t *dts_datastruct_bst_find(bst_t *bst, int key)
{
    if (bst == NULL || bst->key == key) {
        return bst;
    }
    if (key < bst->key) {
        return dts_datastruct_bst_find(bst->left, key);
    }
    else {
        return dts_datastruct_bst_find(bst->right, key);
    }
}

bst_t *dts_datastruct_bst_static_insert(bst_t *bst, bst_t *node)
{
    if (bst == NULL) {
        return node;
    }

    if (bst->key == node->key) {
        return bst;
    }

    if (node->key < bst->key) {
        bst->left = dts_datastruct_bst_static_insert(bst->left, node);
        bst->left->parent = bst;
    }
    else {
        bst->right = dts_datastruct_bst_static_insert(bst->right, node);
        bst->right->parent = bst;
    }

    return bst;
}

bst_t *dts_datastruct_bst_static_remove(bst_t *bst, int key)
{
    bst_t **v, *u, *r;

    if (dts_datastruct_bst_try_remove(&bst, key, &v, &u)) {
        if (u != NULL) {
            u->parent = (*v)->parent;
        }
        r = (*v);
        (*v) = u;
    }

    return bst;
}

// memory alloc enable

void *dts_datastruct_bst_try_insert(void *_bst, int key, void *(*bst_node_new)())
{
    bst_t *bst = (bst_t *)_bst;
    if (bst == NULL) {
        assert(bst = (bst_t *)bst_node_new());
        bst->key = key;
        return bst;
    }

    if (bst->key == key) {
        return bst;
    }

    if (key < bst->key) {
        bst->left = dts_datastruct_bst_try_insert(bst->left, key, bst_node_new);
        bst->left->parent = bst;
    }
    else {
        bst->right = dts_datastruct_bst_try_insert(bst->right, key, bst_node_new);
        bst->right->parent = bst;
    }

    return (void *)bst;
}
static void *bst_node_new()
{
    bst_t *bst = (bst_t *)malloc(sizeof(bst_t));
    assert(bst);
    bst->left = NULL;
    bst->right = NULL;
    bst->value = NULL;
    bst->key = 0;
    bst->parent = NULL;
    return bst;
}
bst_t *dts_datastruct_bst_insert(bst_t *bst, int key)
{
    return (bst_t *)dts_datastruct_bst_try_insert(bst, key, bst_node_new);
}
bst_t *dts_datastruct_bst_remove(bst_t *bst, int key)
{
    bst_t **v, *u, *r;

    if (dts_datastruct_bst_try_remove(&bst, key, &v, &u)) {
        if (u != NULL) {
            u->parent = (*v)->parent;
        }
        r = (*v);
        (*v) = u;
        free(r);
    }

    return bst;
}

void dts_datastruct_bst_delete(bst_t *bst)
{
    bt_delete((bt_t *)bst);
}
