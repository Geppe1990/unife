#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 11

typedef float ELEMENT;
typedef ELEMENT ARRAY[MAXDIM];

int compare_float_p(const void* a, const void* b) {
	float *v1, *v2;
	v1 = (float*) a;
	v2 = (float*) b;

	if(*v1 < *v2) return -1;
	if(*v1 == *v2) return 0;
	return 1;
}

int main() {
	ARRAY V = {26,16,18,14,27,3,1,19,4,8,7};
	qsort(V, MAXDIM, sizeof(float), compare_float_p);

	for(int i=0; i<MAXDIM; i++) {
		printf("%d: %.0f\n", i, V[i]);
	}
}