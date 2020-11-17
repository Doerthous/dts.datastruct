#include <stdio.h>
#include <math.h>
#include <dts/datastruct/kdt.h>

float points[13][2] = {
	{-4.60, -10.55},
	{-6.88, -5.4},
	{-4.96, 12.61},
	{-2.96, -0.5},
	{1.75,12.26},
	{1.24,-2.86},
	{6.27,5.5},
	{17.05,-12.79},
	{7.75,-22.68},
	{15.31,-13.16},
	{10.8,-5.03},
	{7.83,15.7},
	{14.63,-0.35},
};

void kdt_node_print(kdt_t *kdt)
{
	printf("(%f %f)", ((float *)kdt->value)[0], ((float *)kdt->value)[1]);
}

static int compr(const void *a, const void *b, void *r)
{
	float c = ((float *)a)[(int)r] - ((float *)b)[(int)r];
	if (fabs(c) < 1e-6) {
		return 0;
	}
	return c > 0 ? 1 : -1;
}

int main()
{
	kdt_t *kdtree = kdt_new(points, 13, sizeof(float)*2, 2, 0, compr);
	kdt_print(kdtree, kdt_node_print);

	return 0;
}
