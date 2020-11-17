#include <assert.h>
#include <dts/datastruct/list.h>

#define N 10

struct test_node
{
    struct test_node *next;
    int value;
};

static int match(void *node, void *val)
{
    if (((struct test_node *)node)->value == (int)val) {
        return 1;
    }
    return 0;
}

static int opi;
static int opn[N];
static void operator(void *node)
{
    opn[opi++] = ((struct test_node *)node)->value;
}

int main()
{
    list_t list; // void *__list; void **list;
    struct test_node n[N];

    for (int i = 0; i < N; ++i) {
        n[i].value = i;
    }

    list_init(&list);
    assert(list_next(&list) == NULL);

    list_add(&list, &n[0]);
    assert(list_head(&list) == &n[0]);

    list_add(&list, &n[1]);
    assert(list_length(&list) == 2);
    assert(list_next(&list) == &n[1]);

    list_remove(&list, &n[0]);
    assert(list_head(&list) == &n[1]);
    assert(list_length(&list) == 1);

    list_push(&list, &n[2]);
    assert(list_head(&list) == &n[2]);
    assert(list_length(&list) == 2);

    list_enqueue(&list, &n[3]);
    assert(list_head(&list) == &n[3]);
    assert(list_length(&list) == 3);

    assert(list_pop(&list) == &n[3]);
    assert(list_length(&list) == 2);


    list_append(&list, &n[4]);
    assert(list_length(&list) == 3);
    assert(list_dequeue(&list) == &n[4]);
    assert(list_length(&list) == 2);

    int result[N] = {1,2,};
    for (int i = 5; i < N; ++i) {
        list_add(&list, &n[i]);
        result[i-3] = i;
    }

    assert(((struct test_node *)list_find(&list, match, 7)) == &n[7]);

    list_traverse(&list, operator);
    assert(memcmp(result, opn, sizeof(int)*list_length(&list)) == 0);

    return 0;
}
