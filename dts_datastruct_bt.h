#ifndef DTS_DATASTRUCT_BT_H_
#define DTS_DATASTRUCT_BT_H_

typedef struct dts_datastruct_bt
{
    struct dts_datastruct_bt *left;
    struct dts_datastruct_bt *right;
    int key;
    void *value;
} dts_datastruct_bt_t;

int 
dts_datastruct_bt_preorder
(
    dts_datastruct_bt_t *bt, 
    int (*op)(dts_datastruct_bt_t *, void *), 
    void *d
);
int 
dts_datastruct_bt_inorder
(
    dts_datastruct_bt_t *bt, 
    int (*op)(dts_datastruct_bt_t *, void *), 
    void *d
);
int 
dts_datastruct_bt_postorder
(
    dts_datastruct_bt_t *bt, 
    int (*op)(dts_datastruct_bt_t *, void *), 
    void *d
);
int 
dts_datastruct_bt_bfs
(
    dts_datastruct_bt_t *bt, 
    int (*op)(dts_datastruct_bt_t *, void *), 
    void *d
);

dts_datastruct_bt_t *
dts_datastruct_bt_solve_from_inpostorder
(
    const char *in, 
    int in_len, 
    const char *post, 
    int post_len
);

dts_datastruct_bt_t *
dts_datastruct_bt_solve_from_inpreorder
(
    const char *in, 
    int in_len, 
    const char *pre, 
    int pre_len
);

void 
dts_datastruct_bt_delete
(
    dts_datastruct_bt_t *bt
);


typedef struct dts_datastruct_bt_ext
{
    int index;
    int level;
    dts_datastruct_bt_t *node;
    struct dts_datastruct_bt_ext *parent;
} dts_datastruct_bt_ext_t;

void
dts_datastruct_bt_ext_inorder
(
    dts_datastruct_bt_t *bt, 
    int (*op)(dts_datastruct_bt_ext_t *, void *), 
    void *data
);

void
dts_datastruct_bt_print
(
    dts_datastruct_bt_t *bt
);
void
dts_datastruct_bt_print_ext
(
    dts_datastruct_bt_t *bt, 
    void (*print)(dts_datastruct_bt_t *)
);


struct bt_info
{
    int depth;
    int node_count;
};

void dts_datastruct_bt_get_info
(
    dts_datastruct_bt_t *bt, 
    struct bt_info *bti
);

#endif // DTS_DATASTRUCT_BT_H_
