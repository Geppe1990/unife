// - Si definisca il nuovo tipo di dato frazione, costituito da due campi interi: num e den
// - Si scriva un programma che legga da tastiera due frazioni e ne calcoli il prodotto,
// organizzando opportunamente il programma in funzioni

#include <stdio.h>

typedef struct {
	int num, den;
} frazione;

frazione leggiFrazione() {
	frazione f;

	printf("Inserisci la frazione: ");
	scanf("%d/%d", &f.num, &f.den);

	return f;
}

frazione prodotto(frazione A, frazione B) {
	frazione P;
	P.num = A.num * B.num;
	P.den = A.den * B.den;
	
	return P;
}

int main() {
	frazione A,B, P;

	A = leggiFrazione();
	B = leggiFrazione();
	P = prodotto(A, B);
	printf("%d/%d\n%d/%d\n", A.num, A.den, B.num, B.den);
	printf("Prodotto: %d/%d\n", P.num, P.den);
}