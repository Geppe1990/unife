// Si legga da tastiera un numero N, compreso fra 1 e 100.
// Si stampino poi i numeri da 1 a N, escludendo:
// - i multipli di 7
// - i numeri in cui una cifra è 7
// In questi casi, bisogna stampare “BUM!”

// VARIANTE: Si provi a risolvere il problema anche nei casi in cui N è maggiore di 100.

#include <stdio.h>

int main() {
	int N = 171, i;

	for(i=1; i<=N; i++) {
		if(i%7 == 0) {
			printf("BUM! ");
		} else {
			int ultimaCifra,num;
            num=i;
            do
            {
                ultimaCifra = num%10; // Calcola l'ultima cifra di num
                num = num/10;         // toglie l'ultima cifra da num
            } while (num !=0 && ultimaCifra !=7);
            if (ultimaCifra == 7)
                printf("BUM! ");
            else
                printf("%d ",i);	
		}
	}
}