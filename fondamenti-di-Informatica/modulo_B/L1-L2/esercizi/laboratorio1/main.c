// Si realizzi un componente dotato di stato che rappresenta un contatore (con valore intero protetto), con operazioni:
// void reset(void)
// void inc(void)
// int getValue(void)
// Il main che utilizza il contatore, lo resetta e acquisisce da input una sequenza di interi positivi (terminata da 0) usati come incremento del contatore: si verifichi che il valore intero del contatore è protetto

#include <stdio.h>
#include "contatore.h"

void main(void) {
	int i;
	reset();
	for(i=0; i<6; i++) {
		inc();
	}
	printf("%d\n", getValue());
}