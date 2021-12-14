// Si scriva una funzione ricorsiva C con la seguente interfaccia
// int compresi(int a[], int n, int lower, int upper)
// che considera gli elementi dell'array a che hanno indice compreso fra 0 e n e restituisce
// quanti di questi hanno valore strettamente compreso fra lower e upper.
// Ad esempio si supponga che l'array a contenga gli elementi {1,4,2,8,5,3}
// in tal caso compresi(a,4,1,6) fornisce 3, ifnatti fra gli elementi che hanno indice 
// fra 0 e 4 (cioè 1,4,2,8,5), quelli strettamente compresi fra 1 e 6 sono 3: 4,2,5

#include <stdio.h>

int compresi(int a[], int n, int lower, int upper) {
	if(n < 0) {
		return 0;
	} else {
		if(a[n] > lower && a[n] < upper) {
			return compresi(a, n-1, lower, upper) + 1;
		} else {
			return compresi(a, n-1, lower, upper);
		}
	}
}

int fun(int *b, int a[], int x) {
	int k = 4;
	while (*b >= 0) {
		a [(*b) * (*b)] = *b;
		(*b)--;
	}
	x = k-2;
	k =* b;
	return compresi(a ,x ,*b ,3);
}

main (){
	int x, y=2, z=1 , a[5];

	for (x=0;x < 5; x++)
		a[x]=0;

	z = fun(&y, a, x);
}
