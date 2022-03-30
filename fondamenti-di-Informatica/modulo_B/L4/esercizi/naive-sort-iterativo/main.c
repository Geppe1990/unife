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

void naiveSort(ARRAY a, int dim) {
	int j, i, posmin;
	ELEMENT min;

	for(j=0; j<dim; j++) {
		posmin = j;

		for(min = a[j], i = j + 1; i<dim; i++) {
			if(a[i] < min) {
				posmin = i;
				min = a[i];
			}
		}

		if(posmin != j) {
			swap(&a[j], &a[posmin]);
		}
	}

	printArray(a, dim);
}

int main() {
	ARRAY arr = {7,2,4,5,3,1};
	int dim = 6;

	naiveSort(arr, dim);
}