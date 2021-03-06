#ifndef LIST_H_
#define LIST_H_

#include "../../dts_datastruct_list.h"

#define list_t dts_datastruct_list_t

#define list_init dts_datastruct_list_init

#define list_push dts_datastruct_list_push
#define list_pop dts_datastruct_list_pop
#define list_enqueue dts_datastruct_list_enqueue
#define list_dequeue dts_datastruct_list_dequeue
#define list_queue_head dts_datastruct_list_queue_head
#define list_append dts_datastruct_list_append

#define list_add dts_datastruct_list_add
#define list_remove dts_datastruct_list_remove

#define list_length dts_datastruct_list_length

#define list_head dts_datastruct_list_head
#define list_next dts_datastruct_list_next

#define list_find dts_datastruct_list_find
#define list_traverse dts_datastruct_list_traverse

#define list_foreach_flag_rm (1<<0)
#define list_foreach_flag_continue (1<<1)
#define list_foreach_remove(node) \
    list_foreach_flags |= list_foreach_flag_rm; *node = (*node)->next;
#define list_foreach(type, node, list, do_something) do \
{ \
    int list_foreach_flags = 0; \
    for (type **node = (type **)&((list)->next); \
        *node; ) { \
        list_foreach_flags &= ~list_foreach_flag_rm; \
        /* if it continue, move to next */ \
        if (list_foreach_flags & list_foreach_flag_continue) { \
            list_foreach_flags &= ~list_foreach_flag_continue; \
            node = (type **)&((*node)->next); \
        } \
        /* we suppose it will continue */ \
        list_foreach_flags |= list_foreach_flag_continue; \
        do_something \
        /* if we can get here, then it do not continue */ \
        list_foreach_flags &= ~list_foreach_flag_continue; \
        if (*node && !(list_foreach_flags & list_foreach_flag_rm)) { \
            node = (type **)&((*node)->next); \
        } \
    } \
} while (0)

#define list_exists dts_datastruct_list_exists

#endif // LIST_H_
