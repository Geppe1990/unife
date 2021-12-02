// Si scriva una funzione ricorsiva
// int massimo(int a[], int n);
// che calcola il massimo degli elementi
// dell'array a dall'indice 0 fino all'indice n;

#include <stdio.h>

int massimo(int a[], int n) {
	int m;
	if(n == 0) {
		return a[0];
	} else {
		m = massimo(a, n-1);
		if(m < a[n]){
			return a[n];
		} else return m;
	}
}

int main() {
	int a[] = {3,4,1,2,5,1,2,1};
	int n = 7;
	int m = massimo(a, n);
	printf("%d\n", m);
}