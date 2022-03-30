#include <stdio.h>
#define N 11

typedef float ELEMENT;
typedef ELEMENT ARRAY[N];
typedef enum {false, true} Boolean;

void printArray(ARRAY a, int dim) {
	for(int x = 0; x<dim; x++) {
		printf("%.0f\n", a[x]);
	}
}

void swap(ELEMENT *a, ELEMENT *b) {
	ELEMENT tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(ARRAY a, int dim) {
	Boolean swapped;
	int i;
	int originaldim = dim;

	do {
		swapped = false;
		for(i=0; i<dim-1; i++) {
			if(a[i] > a[i+1]) {
				swapped = true;
				swap(&a[i], &a[i+1]);
			}
		}
		dim--;
	} while(swapped);
	printArray(a, originaldim);
}

int main() {
	ARRAY arr = {7,2,4,5,3,1};
	int dim = 6;

	bubbleSort(arr, dim);
}