// Si scriva una funzione ricorsiva C con la seguente interfaccia
// int maggiori(int a[], int x, int n);

// che fornisce come valore di ritorno quanti elementi nella porzione di array a
// compresa fra gli indici 0 ed n sono maggiori di x.
// Ad esempio, se l'array a è il seguente:
// [1][3][4][6][2]
// x=2 e n=3, la funzione fornisce 3.
// Si mostri poi il funzionamento del seguente programma, che invoca la funzione definita precedentemente,
// utilizzando i record di attivazione.

#include <stdio.h>

int maggiori(int a[], int x, int n) {
	if(n<0) 
		return 0;
	else {
		if(a[n] > x)
			return maggiori(a, x, n-1) + 1;
		else
			return maggiori(a, x, n-1);
	}
}

int f(int a[], int s, int *k) {
	int m = maggiori(a, s, *k);

	for (s=0; s < *k; s++) {
		printf("a[%d] = %d", s, a[s]+m);
		a[s] = a[s]+m;
		(*k) = s;
	}

	return s;
}

int main() {
	int k=2;
	int a[] = {5,3,6,2};
	int b=3;
	int j;

	j = f(a,b,&k);
	// printf("%d\n", j);
	printf("k: %d\n", k);

	for(int i=0; i<k; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}