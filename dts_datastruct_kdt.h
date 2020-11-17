#ifndef DTS_DATASTRUCT_KDT_H_
#define DTS_DATASTRUCT_KDT_H_

typedef struct kdt
{
	struct dts_datastruct_kdt *left;
	struct dts_datastruct_kdt *right;
	void *value;
} dts_datastruct_kdt_t;

dts_datastruct_kdt_t *
dts_datastruct_kdt_new
(
	void *mem, 
	int ele_count, 
	int ele_size, 
	int n, 
	int r, 
	int (*r_compar[])(const void *, const void *, void *)
);

void
dts_datastruct_kdt_print
(
    dts_datastruct_kdt_t *bt, 
    void (*print)(dts_datastruct_kdt_t *)
);
#endif // DTS_DATASTRUCT_KDT_H_
