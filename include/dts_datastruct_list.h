/**
  ******************************************************************************
  * \brief      list
  * \file       list.h
  * \author     doerthous
  * \date       2019-09-03
  * \details    
  *             list:
  *                 head --------------------------------------- tail
  *                  ^                                            ^   
  *                  |                                            |
  *                 push/pop/enqueue/add                        dequeue/append 
  *              
  *             usage:
  *                 struct your_node
  *                 {
  *                     void *next; // or "struct list list" whatever,
  *                                 // this member is required by list,
  *                                 // and must be the first palce of
  *                                 // your node.
  *                     ... // other data of your node
  *                 };
  *                 ...
  *                 
  *                 struct list list; // void *__list; void **list;
  *                 struct your_node n1, n2;
  *                 
  *                 list_init(&list);
  *                 list_add(&list, &n1);
  *                 list_remove(&list, &n1);
  *                 ...
  ******************************************************************************
  */

#ifndef DTS_DATASTRUCT_LIST_H_
#define DTS_DATASTRUCT_LIST_H_


typedef struct dts_datastruct_list
{
    struct dts_datastruct_list *next;
} dts_datastruct_list_t;


void dts_datastruct_list_init(dts_datastruct_list_t *list);

void dts_datastruct_list_push(dts_datastruct_list_t * list, void *node);
void *dts_datastruct_list_pop(dts_datastruct_list_t * list);
void dts_datastruct_list_enqueue(dts_datastruct_list_t * list, void *node);
void *dts_datastruct_list_dequeue(dts_datastruct_list_t * list);
void dts_datastruct_list_append(dts_datastruct_list_t * list, void *node);

void dts_datastruct_list_add(dts_datastruct_list_t * list, void *node);
void dts_datastruct_list_remove(dts_datastruct_list_t * list, void *node);

int dts_datastruct_list_length(dts_datastruct_list_t * list);

void *dts_datastruct_list_head(dts_datastruct_list_t * list);
void *dts_datastruct_list_next(void *node);

void *dts_datastruct_list_find(dts_datastruct_list_t * list, int (*match)(void *node, void *val), void *val);
void dts_datastruct_list_traverse(dts_datastruct_list_t * list, void (*operate)(void *node));

int dts_datastruct_list_exists(dts_datastruct_list_t * list, void *node);


/**
 * Malloc support
 */
//#define LIST_USING_MALLOC
#ifdef LIST_USING_MALLOC

/* #include <some.h> , such as stdlib.h */
#include <stdlib.h>
#define dts_datastruct_list_malloc(size) malloc((size))
#define dts_datastruct_list_free(ptr) free((ptr))

dts_datastruct_list_t * dts_datastruct_list_new(void);
void dts_datastruct_list_delete(dts_datastruct_list_t * list);

#endif /* LIST_USING_MALLOC */

#endif /* DTS_DATASTRUCT_LIST_H_ */

/****************************** Copy right 2019 *******************************/
