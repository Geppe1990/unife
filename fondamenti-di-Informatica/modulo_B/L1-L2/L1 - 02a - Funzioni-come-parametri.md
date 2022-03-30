# Funzioni come parametri

## Astrazioni nei linguaggi di alto livello (C)
- Possibilità di dare nomi simbolici a indirizzi di memoria (variabili)
- Possibilità di sfruttare la programmazione strutturata:
	- sequenza (;)
	- blocco
	- if else, while, do, ecc.
	- astrazione funzionale (funzioni)

	
## Interfaccia di una funzione
L'interfaccia di una funzione comprende:

- nome della funzione
- lista dei parametri
- tipo di valore di ritorno

Definisce il contratto di servizio tra cliente e servitore

Cliente e servitore comunicano mediante:

- **parametri**: trasmessi dal cliente al servitore all'atto della chiamata
- **valore restituito** dal servitore al cliente


## Definizione di una funzione
```C
long potenza(int x, int y){
	// x e y sono parametri formali
	int i;
	long p = 1; // variabile locali
	for(i=1; i<=n; ++i){
		p *= x;
	}
	return p;
}
```

## Chiamata della funzione
```C
main() {
	long Y;
	Y = potenza(X, 10);
	// X e 10 sono parametri attuali
}
```

## Parametri funzione
Tra i parametri formali di una funzione F ci possono essere anche delle altre **funzioni**

In C, l'identificatore di una funzione è il puntatore al suo codice

**Parametro attuale**: nome di una specifica funzione

**Parametro formale**: puntatore a codice di una funziona con un certo tipo restituito e tipo dei parametri formali

Per avere parametri procedura o funzione, occorre specificare un parametro formale di tipo funzione come segue:

```C
tipo F1(tipo2 (*F2) (list-pf-F2), rest-param-F1)
```
Nel corpo di F1 potrà esserci la chiamata:

```C
k=(*F2)(...) /* con parametri attuali opportuni */
```

Le funzioni possono anche essere restituite (attraverso puntatore) come risultato di una funzione

## Esempio
```C
#include <math.h>

double sommaquadratif(
	double (*f) (double par), int m, int n
) {
	int i;
	double somma = 0;

	for(i=m; i<=n; i++)
		somma = somma + (*f)(i) * (*f)(i);

	return somma;
}

void main() {
	//Sin è una funzione restituita da math.h
	printf("Seni %.7f\n", sommaquadratif(sin, 2, 13));
}
```