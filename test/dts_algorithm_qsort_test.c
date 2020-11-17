#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <dts/algorithm/qsort.h>

int compr(const void *a, const void *b, void *d)
{
    return (*(int *)a) - (*(int *)b);
}

static int fcompr(const void *a, const void *b, void *r)
{
	float c = *((float *)a)- *((float *)b);
	if (fabs(c) < 1e-6) {
		return 0;
	}
	return c > 0 ? 1 : -1;
}

int main()
{
    int arr[10] = { 1,3,5,6,9,2,4,8,7,0 };

    qsort(arr, 10, sizeof(int), compr, NULL);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    float farr[13] = {-4.60,-6.88,-4.96,-2.96,1.75,1.24,6.27,17.05,7.75,15.31,10.8,7.83,14.63,};
    qsort(farr, 13, sizeof(float), fcompr, NULL);

    for (int i = 0; i < 13; ++i) {
        printf("%f ", farr[i]);
    }

    return 0;
}
