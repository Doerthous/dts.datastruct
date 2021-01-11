#ifndef BST_H_
#define BST_H_

#include "../../dts_datastruct_bst.h"

#define bst_t dts_datastruct_bst_t

#define bst_insert dts_datastruct_bst_insert
#define bst_remove dts_datastruct_bst_remove
#define bst_find dts_datastruct_bst_find
#define bst_delete dts_datastruct_bst_delete

#define bst_try_insert dts_datastruct_bst_try_insert
#define bst_try_remove dts_datastruct_bst_try_remove

#define bst_static_insert dts_datastruct_bst_static_insert
#define BST_NODE(_key, _value) \
{ \
    .left = NULL, \
    .right = NULL, \
    .parent = NULL, \
    .key = _key, \
    .value = _value, \
}

#endif // BST_H_
