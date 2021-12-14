// Si scriva una funzione ricorsiva che, dato un naturale N, calcola la somma dei primi N numeri interi positivi

#include <stdio.h>

int somma(int N) {
	if(N == 0)
		return 0;
	else
		return somma(N-1)+N;
}

int main() {
	int N = 5;
	int sum = somma(N);
	printf("sum: %d\n", sum); // 15 -> 1+2+3+4+5 
}
