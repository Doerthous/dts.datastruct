#include <dts/datastruct/kdt.h>
#include <stdlib.h>
#include <assert.h>
#include <dts/algorithm/qsort.h>s

#define ARR(i) ((char *)mem + (i)*ele_sz)

kdt_t *
dts_datastruct_kdt_new
(
	void *mem,
	int ele_cnt,
	int ele_sz,
	int n,
	int r,
	int (*compr[])(const void *, const void *, void *)
)
{
	kdt_t *node;

	if (ele_cnt == 0) {
		return NULL;
	}

	node = (kdt_t *)malloc(sizeof(struct kdt));
	assert(node != NULL);

	qsort(mem, ele_cnt, ele_sz, compr, r);

	int p = ele_cnt/2 - (ele_cnt%2==0);
	node->value = ARR(p);

	if (p >= 0) {
		node->left = dts_datastruct_kdt_new(ARR(0), p, ele_sz,
			n, (r+1)%n, compr);
	}
	if (p+1 <= ele_cnt) {
		node->right = dts_datastruct_kdt_new(ARR(p+1), ele_cnt-(p+1), ele_sz,
			n, (r+1)%n, compr);
	}

	return node;
}

#include "dts/datastruct/bt.h"
void
dts_datastruct_kdt_print
(
    kdt_t *bt,
    void (*print)(kdt_t *)
)
{
	bt_print_ext((bt_t *)bt, (void (*)(bt_t *))print);
}
