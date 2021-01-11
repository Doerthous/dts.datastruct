#ifndef DTS_DATASTRUCT_BST_H_
#define DTS_DATASTRUCT_BST_H_

typedef struct dts_datastruct_bst 
{
    struct dts_datastruct_bst *left;
    struct dts_datastruct_bst *right;
    int key;
    void *value;
    struct dts_datastruct_bst *parent;
} dts_datastruct_bst_t;


dts_datastruct_bst_t *
dts_datastruct_bst_insert
(
    dts_datastruct_bst_t *bst,
    int key
);

dts_datastruct_bst_t *
dts_datastruct_bst_remove
(
    dts_datastruct_bst_t *bst, 
    int key
);

dts_datastruct_bst_t *
dts_datastruct_bst_find
(
    dts_datastruct_bst_t *bst, 
    int key
);

void 
dts_datastruct_bst_delete
(
    dts_datastruct_bst_t *bst
);

void *
dts_datastruct_bst_try_insert
(
    void *bst, 
    int key, 
    void *(*bst_node_new)()
);
int 
dts_datastruct_bst_try_remove
(
    dts_datastruct_bst_t **bst, 
    int key, 
    dts_datastruct_bst_t ***v, 
    dts_datastruct_bst_t **u
);

dts_datastruct_bst_t *
dts_datastruct_bst_static_insert
(
    dts_datastruct_bst_t *bst,
    dts_datastruct_bst_t *node
);

dts_datastruct_bst_t *
dts_datastruct_bst_static_remove
(
    dts_datastruct_bst_t *bst,
    int key
);

#endif // DTS_DATASTRUCT_BST_H_
