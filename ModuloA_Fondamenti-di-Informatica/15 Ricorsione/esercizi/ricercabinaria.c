#include <stdio.h>

int ricerca_binaria(int a[], int first, int last, int x) {
	int med;
	med = (first+last)/2;

	if(first > last) return -1;

	if(a[med] == x) {
		return med;
	} else if(a[med] > x) {
		return ricerca_binaria(a, first, med-1, x);
	} else {
		return ricerca_binaria(a, med+1, last, x);
	}
}

int main() {
	int N = 24;
	int a[] = {0,0,1,3,5,6,8,9,10,11,13,16,25,26,28,31,33,34,41,41,50,51,51,91};
	int p;
	int val = 9;
	p = ricerca_binaria(a, 0, N-1, 9);
	if(p<0) {
		printf("Elemento non presente\n");
	} else {
		printf("Il valore %d è presente all'indice %d\n", val, p);
	}
}