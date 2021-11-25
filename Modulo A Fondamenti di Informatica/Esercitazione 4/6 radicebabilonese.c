// Calcolare la radice quadrata di un numero reale "a" con il metodo babilonese: 
// una successione di approssimazioni in cui il primo elemento è 1 e il successore di x 
// è la media aritmetica fra x e a/x.

// In particolare, chiedere all'utente un numero intero N, che corrisponde al livello di 
// approssimazione (indica quanti elementi della successione visualizzare), e un numero 
// reale "a" (float) corrispondente al numero di cui calcolare la radice quadrata.

// L'immagine allegata mostra un esempio con N = 3 e a = 2

#include <stdio.h>

int main() {
	int n;
    float a;
    float x = 1;

    printf("Inserire livello di approssimazione: ");
    scanf("%d", &n);
    printf("Inserire il numero da calcolare: ");
    scanf("%f", &a);
    for(int i = 0; i < n; i++)
        x = (x+a/x)/2;
    
    printf("La radice quadrata di %f e' %.4f", a, x);
}