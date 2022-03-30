#include <stdio.h>
#include "function.h"

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

void mergeSort(ARRAY a, int dim) {
	mergeSortR(a, 0, dim-1);
}

void mergeSortR(ARRAY a, int iniz, int fine) {
	if(iniz > fine) {
		int m = (fine + iniz) / 2;
		mergeSortR(a, iniz, m);
		mergeSortR(a, m+1, fine);
		merge(a, iniz, m+1, fine);
	}
}