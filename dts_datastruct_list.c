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

void list_init(list_t * list)
{
    ASSERT(list != NULL);

    list->next = NULL;
}


void list_push(list_t * list, void *node)
{
    list_add(list, node);
}

void *list_pop(list_t * list)
{
    void *node = NULL;

    ASSERT(list != NULL);    

    node = list->next;

    if (node != NULL) {
        list->next = list->next->next;
    }

    return node;
}

void list_enqueue(list_t * list, void *node)
{
    list_add(list, node);
}

void *list_dequeue(list_t * list)
{
    void *head = NULL;

    list_foreach(list_t, node, list, {
        if ((*node)->next == NULL) {
            head = (void *)(*node);
            list_foreach_remove(node);
            break;
        }
    });

    return head;
}


void *list_queue_head(list_t *list)
{
    list_foreach(list_t, node, list, {
        if ((*node)->next == NULL) {
            return (void *)(*node);
        }
    });

    return NULL;
}

void list_append(list_t * list, void *node)
{
    if (!list_exists(list, node)) {
        list_foreach(list_t, n, list, {
            if ((*n)->next == NULL) {
                (*n)->next = node;
                ((list_t *)node)->next = NULL;
                break;
            }
        });
    }
}


void list_add(list_t * list, void *node)
{
    if (!list_exists(list, node)) {
        ((list_t *)node)->next = list->next;    
        list->next = node;
    }
}

void list_remove(list_t * list, void *target)
{
    list_foreach(list_t, node, list, {
        if ((*node) == target) {
            list_foreach_remove(node);
            break;
        }
    });
}


int list_length(list_t * list)
{
    int i = 0;

    ASSERT(list != NULL);

    while (list->next != NULL) {
        ++i;
        list = list->next;
    }

    return i;
}

void *list_head(list_t * list)
{
    return list->next;
}
void *list_next(void *node)
{
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


void *list_find(list_t * list, int (*match)(void *node, void *val), void *val)
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

void list_traverse(list_t * list, void (*operate)(void *node))
{
    ASSERT(list != NULL);
    ASSERT(operate != NULL);

    if (list->next) {
        list_traverse(list->next, operate);
        operate(list->next);
    }   
}

int list_exists(list_t * list, void *node)
{
    list_foreach(list_t, n, list, {
        if ((*n) == node) {
            return 1;
        }
    });

    return 0;
}

/****************************** Copy right 2019 *******************************/
