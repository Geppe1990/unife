// Si scriva una funzione ricorsiva
// int somma(int a[], int n);
// che calcola la somma degli elementi dell'array a dall'indice 0 fino all'indice n

#include <stdio.h>

int somma(int a[], int n) {
	if(n==0) {
		return a[0];
	} else {
		return a[n]+somma(a, n-1);
	}
}

int main() {
	int a[] = {3,4,1,2,5,1,2,1};
	int n = 7;
	int sum = somma(a, n);
	printf("%d\n", sum);
}