#include <stdio.h>
#include "function.h"

int main() {
	ARRAY arr = {7,2,4,5,3,1};
	int dim = 6;

	naiveSort(arr, dim);
	bubbleSort(arr, dim);
}
