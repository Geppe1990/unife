// Un signore contatta un piastrellista per rimettere a nuovo il pavimento del
// bagno della sua casa. Il piastrellista chiede al signore la dimensione e
// il numero delle piastrelle che desidera acquistare.
// 
// Chiedere all'utente:
// - Lunghezza lato piastrella, si supponga che sia quadrata
// - Numero di piastrelle da comperare
// 
// Calcolare quindi l'area del bagno ricoperta dalle piastrelle e stamparla a video.

#include <stdio.h>

main() {
	int dimensione, quantita, area;
	printf("Inserire la dimensione della piastrella: ");
	scanf("%d", &dimensione);
	printf("Inserire la quantità delle piastrelle: ");
	scanf("%d", &quantita);

	area = (dimensione*dimensione) * quantita;

	printf("Il bagno ha un'area di %dmq\n", area);
}