/**
  ******************************************************************************
  * \brief      list
  * \file       list.c
  * \author     doerthous
  * \date       2019-09-03
  * \details    
  ******************************************************************************
  */

#include <dts/datastruct/list.h>

#define DEBUG
#ifdef DEBUG
  #define ASSERT(expr) do {;} while (!(expr))
#else
  #define ASSERT(expr)
#endif

#undef NULL
#define NULL (void *)0

void dts_datastruct_list_init(list_t * list)
{
    ASSERT(list != NULL);

    list->next = NULL;
}


void dts_datastruct_list_push(list_t * list, void *node)
{
    dts_datastruct_list_add(list, node);
}

void *dts_datastruct_list_pop(list_t * list)
{
    void *node = NULL;

    ASSERT(list != NULL);    

    node = list->next;

    if (node != NULL) {
        list->next = list->next->next;
    }

    return node;
}

void dts_datastruct_list_enqueue(list_t * list, void *node)
{
    dts_datastruct_list_add(list, node);
}

void *dts_datastruct_list_dequeue(list_t * list)
{
    void *node = NULL;

    ASSERT(list != NULL);

    if (list->next != NULL) {
        while (list->next->next != NULL) {
            list = list->next;
        }

        node = list->next;
        list->next = NULL;
    }

    return node;
}

void dts_datastruct_list_append(list_t * list, void *node)
{
    ASSERT(list != NULL);
    ASSERT(node != NULL);

    while (list->next != NULL) {
        if (list->next == node) { // node already in the list
            return;
        }
        list = list->next;
    }

    list->next = node;
    ((list_t *)node)->next = NULL; 
}


void dts_datastruct_list_add(list_t * list, void *node)
{
    // make sure node is not in the list.    
    dts_datastruct_list_remove(list, node);

    ((list_t *)node)->next = list->next;    
    list->next = node;    
}

void dts_datastruct_list_remove(list_t * list, void *node)
{
    ASSERT(list != NULL);
    ASSERT(node != NULL);

    while (list->next != NULL) {
        if (list->next == node) {
            list->next = ((list_t *)node)->next; 
            return;
        }
        list = list->next;
    }
}


int dts_datastruct_list_length(list_t * list)
{
    int i = 0;

    ASSERT(list != NULL);

    while (list->next != NULL) {
        ++i;
        list = list->next;
    }

    return i;
}

void *dts_datastruct_list_head(list_t * list)
{
    ASSERT(list != NULL);

    return list->next;
}
void *dts_datastruct_list_next(void *node)
{
    ASSERT(node != NULL);

    return node == NULL ? node : ((list_t *)node)->next;
}


#ifdef LIST_USING_MALLOC
list_t * dts_datastruct_list_new()
{
    list_t * l;

    if ((l = list_malloc(sizeof(list_t *))) != NULL) {
        list_init(l);
    }

    return l;
}

void dts_datastruct_list_delete(list_t * list)
{
    list_free(list);
}
#endif


void *dts_datastruct_list_find(list_t * list, int (*match)(void *node, void *val), void *val)
{
    ASSERT(list != NULL);
    ASSERT(match != NULL);

    while (list->next != NULL) {
        if (match(list->next, val)) {
            return list->next;
        }
        list = list->next;
    }

    return NULL;
}

void dts_datastruct_list_traverse(list_t * list, void (*operate)(void *node))
{
    ASSERT(list != NULL);
    ASSERT(operate != NULL);

    if (list->next) {
        dts_datastruct_list_traverse(list->next, operate);
        operate(list->next);
    }   
}

/****************************** Copy right 2019 *******************************/
