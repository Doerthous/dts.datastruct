#ifndef DTS_DATASTRUCT_RBT_H_
#define DTS_DATASTRUCT_RBT_H_

typedef struct dts_datastruct_rbt
{
    struct dts_datastruct_rbt *left;
    struct dts_datastruct_rbt *right;
    int key;
    void *value;
    struct dts_datastruct_rbt *parent;
    int color;
} dts_datastruct_rbt_t;

dts_datastruct_rbt_t *
dts_datastruct_rbt_insert(dts_datastruct_rbt_t *rbt, int key);

dts_datastruct_rbt_t *
dts_datastruct_rbt_static_insert
(
    dts_datastruct_rbt_t *rbt, 
    dts_datastruct_rbt_t *node
);

dts_datastruct_rbt_t *
dts_datastruct_rbt_remove(dts_datastruct_rbt_t *rbt, int key);

dts_datastruct_rbt_t *
dts_datastruct_rbt_find(dts_datastruct_rbt_t *rbt, int key);

void
dts_datastruct_rbt_delete(dts_datastruct_rbt_t *rbt);

void
dts_datastruct_rbt_print(dts_datastruct_rbt_t *rbt);

#endif // DTS_DATASTRUCT_RBT_H_
