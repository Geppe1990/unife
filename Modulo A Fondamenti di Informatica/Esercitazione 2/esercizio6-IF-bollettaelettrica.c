// Si scriva un programma che calcoli la bolletta elettrica dei clienti di una società di fornitura.

// Il programma prende in ingresso il numero di kilowattora (kWh) consumati dall'utente nell'ultimo mese e restituisce 
// la cifra dovuta in euro.

// Per educare le famiglie a un consumo consapevole dell'energia elettrica la società ha 
// deciso che il costo per kWh cambia in base al consumo mensile come segue:
// - i primi 200 kWh costano 1 euro/kWh
// - i kWh dal 201-esimo fino al 400-esimo costano 2 euro/kWh
// - i kWh dal 401-esimo al 600-esimo costano 3 euro/kWh
// - i kWh oltre il 600-esimo costano 4 euro/kWh
// (si noti che si tratta di una funzione continua).
// Ad esempio, se l'energia spesa è di 450kWh, il costo sarà:
// 200 kWh * 1 (euro/kWh) = 200 euro      +
// 200 kWh * 2 (euro/kWh) = 400 euro      +
//  50 kWh * 3 (euro/kWh) = 150 euro       =
// -----------------------------------------------------------------
//                                              750 euro

#include <stdio.h>

main() {
	int kwh, counter, costo;
	kwh = 650;
	costo = 0;
	counter = kwh;

	if(counter > 600) {
		int soglia = counter - 600;

		costo += soglia * 4;
		counter = counter - soglia;
	}

	if(counter > 400) {
		int soglia = counter - 400;

		costo += soglia * 3;
		counter = counter - soglia;
	}

	if(counter > 200) {
		int soglia = counter - 200;

		costo += soglia * 2;
		counter = counter - soglia;
	}

	costo += counter;
	printf("Hai usato %dkWh, pagherai %d euro\n", kwh, costo);
}