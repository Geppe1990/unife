#include <stdio.h>

void getData(int *n, int *v) {
	int i;
	printf("Quanti valori vuoi inserire? ");
	scanf("%d", n);

	for(i=0; i<*n; i++) {
		printf("Inserisci il valore %d: ", i);
		scanf("%d", &v[i]);
	}
}

int getMax(int n, int *v) {
	int max = 0, i, index;

	for(i=0; i<n; i++) {
		if (v[i] > max) {
			max = v[i];
			index = i;
		}
	}

	return index;
}

int main() {
	int n, v[10], maxIndex;
	getData(&n, v);
	maxIndex = getMax(n, v);
	printf("L'indice del valore massimo è %d\n", maxIndex);
}