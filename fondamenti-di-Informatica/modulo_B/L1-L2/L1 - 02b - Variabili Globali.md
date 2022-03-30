# Variabili Globali
- Servono a costruire componenti software **dotati di stato**

## Ambiente locale e globale
- Ogni funzione ha il suo ambiente locale che comprende **parametri formali** e **variabili locali**
- L'**ambiente globale** è quello dove sono definite tutte le funzioni, qui vengono definite anche le **variabili globali**
- Si dicono globali in quanto l'environment è esterno da ciascuna funzione (compreso il main)
- In C una variabile è globale se **definita fuori da qualunque funzione**

## Esempio 1
```C
int trentadue = 32; // VARIABILE GLOBALE

float fahrToCelsius(float F) {
	float temp = 5.0 / 9;
	return temp * (F - trentadue);
}
```

##Extern
- Per richiamare una variabile globale definita in un altro file si usa la keyword **extern**, la variabile può anche essere definita in un altro file sorgente del progetto

## Esempio 2
```C
extern int trentadue; // DICHIARAZIONE DI VARIABILE GLOBALE

float fahrToCelsius(float f) {
	return 5.0 / 9 * (f-trentadue); // USO DI VARIABILE GLOBALE
}

void main(void) {
	float c = fahrToCelsius(86);
}

int trentadue = 32; // DEFINIZIONE DI VARIABILE GLOBALE
```

## Esempio su 3 file
```C
// file main.c
float fahrToCelsius(float f);

void main(void) {
	float c = fahrToCelsius(86);
}

// file f2c.c
extern int trentadue;
float fahrToCelsius(float f) {
	return 5.0/0 * (f-trentadue);
}

// file c43.c
int trentadue = 32;
```

## Esempio: Stile funzionale puro
- Questo stile di programmazione è preferibile
 
```C
int fattoriale(int n) {
	int i, p=1;
	for(i=1; i<=n; i++) {
		p *= i;
	}
	return p;
}

void main(void) {
	printf("%d", fattoriale(4);
}
```

## Esempio: Side effect
- Questo stile di programmazione è da evitare perchè è più difficile trovare errori e modificare il software
 
```C
int N = 1; // Variabile globale

void fattoriale(int n) {
	int i;
	for(i=1; i<=n; i++){
		N *= i;
	}
}

void main(void) {
	fattoriale(4);
	printf("%d", N);
	fattoriale(4); // quanto vale N?
}
```

##Side effects delle variabili globali
- La funzione può sfruttarle per memorizzare una informazione destinata a sopravviverle
- Rendono la funzione dipendente dall'ambiente esterno, il codice quindi diventa più difficile da correggere e modificare

## Componenti con stato: esempio
- Si vuole costruire un componente software **numeriDispari** che fornisca una funzione **int prossimoDispari(void)** che restituisca via via il "successivo" dispari
- Per fare questo, tale componente deve **tenere memoria** al suo interno dell'ultimo valore fornito
- Dunque, non è una funzione in senso matematico, perchè, interrogata più volte, dà ogni volta una risposta diversa
- Possiamo sviluppare il software nel seguente modo:
	- un file **dispari.c** che definisca la funzione e una variabile globale per raccogliere lo stato
	- un file **dispari.h** che dichiari la funzione

**dispari.c**	

```C
	int ultimoValore = 0;
	int prossimoDispari(void) {
		return 1 + 2 * ultimoValore++;
	}
```

**dispari.h**

```C
int prossimoDispari(void);
```

**main.c**

```C
#include "dispari.h"
#include <stdio.h>

void main(void) {
	int i;
	for(i=1; i<10; i++) {
		printf("%d", prossimoDispari());
	}
}
```

## Ambiente globale e protezione
Il fatto che le variabili globali siano potenzialmente visibili in tutti i file dell'applicazione pone dei **problemi di protezione:** alterando una variabile globale potremmo rompere delle parti di codice senza accorgercene

## Variabili Globali statiche
Possiamo rendere protette le variabili globali definite in un file con la keyword static:

- permanente come tempo di vita
- protetta, cioè visibile solo entro il suo scope di definizione
- non sarà quindi possibile richiamarla con extern

```C
static int ultimoValore = 0;
int prossimoDispari(void) {
    return 1 + 2 * ultimoValore++;
}
```

```C
#include "dispari.h"
#include <stdio.h>
extern int ultimoValore; // -> ERRORE!!
void main(void) {
	int i;
	for(i=1; i<10; i++) {
		printf("%d", prossimoDispari());
	}
}
```

## Variabili Statiche dentro a funzioni
Una variabile statica può essere definita anche dentro una funzione:

- è protetta, in quanto **visibile solo dentro alla funzione**
- è permanente, in quanto **il suo tempo di vita diventa quello dell'intero programma**
- Consente di costruire componenti dotati di stato, ma indipendenti dall'esterno

Le variabili statiche hanno due effetti:
- rende l'oggetto permanente (DATA SEGMENT)
- rende l'oggetto protetto (invisibile fuori dal suo scope)
```C
int prossimoDispari(void) {
	static int ultimoValore = 0;
	
	return 1 + 2 * ultimoValore++;
}
```

## Aree di memoria
- **Code Segment**
	- funzioni
- **Data Segment**
	- variabili globali
- **Stack**
	- variabili automatiche
- **Heap**
	- variabili dinamiche allocate (malloc) e deallocate (free)