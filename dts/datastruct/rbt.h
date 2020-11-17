#ifndef RBT_H_
#define RBT_H_

#include "../../dts_datastruct_rbt.h"

#define rbt_t dts_datastruct_rbt_t

#define rbt_insert dts_datastruct_rbt_insert
#define rbt_remove dts_datastruct_rbt_remove
#define rbt_find dts_datastruct_rbt_find
#define rbt_delete dts_datastruct_rbt_delete
#define rbt_print dts_datastruct_rbt_print

#define rbt_static_insert dts_datastruct_rbt_static_insert
#define rbt_static_remove dts_datastruct_rbt_static_remove
#define RBT_NODE(_key, _value) \
{ \
    .left = ((rbt_t *)0), \
    .right = ((rbt_t *)0), \
    .key = _key, \
    .value = _value, \
    .parent = ((rbt_t *)0), \
    .color = 0, \
}
static rbt_t RBT_NODE_EX(int _key, void *_value)
{
    rbt_t n;
    n.left = ((rbt_t *)0);
    n.right = ((rbt_t *)0);
    n.key = _key;
    n.value = _value;
    n.parent = ((rbt_t *)0);
    n.color = 0;
    return n;
}

#endif // RBT_H_
