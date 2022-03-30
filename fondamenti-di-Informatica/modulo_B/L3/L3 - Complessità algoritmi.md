# Complessità degli algoritmi

## Ricerca minimo in un vettore di N elementi
Questo algoritmo esegue l'iterazione (for) N-1 volte e N-1 operazioni di confronto (if)

```C
#define N 100

typedef int[N] vettore;

int minimo(vettore vet) {
	int i, min;

	for(min = vet[0], i = 1; i<N; i++) {
		if(vet[i] < min) {
			min = vet[i];
		}
	}
	
	return min;
}
```

## Ricerca esaustiva in un vettore di N elementi
In questo algoritmo, il ciclo (while) è governato da due condizioni: **i<N && !trovato**


```C
int ricerca(vettore vet, int el, int *pos) {
	int i=0;
	int trovato = 0;

	while((i<N) && (!trovato)) {
		if(el == vet[i]) {
			trovato = 1;
			*pos = i;
		} else {
			i++;
		}
	}

	return trovato;
}
```

##Teoria della Complessità
Serve per valutare:

- la complessità intrinseca di un problema
- per valutare il costo degli algoritmi risolutivi di un problema

Qualsiasi programma richiede **spazio di memoria** e **tempo di calcolo**

## Correttezza ed efficienza
- Ci concentreremo sulla **complessità temporale** attraverso dei calcoli approssimati per scegliere gli algoritmi più performanti

## Complessità temporale
- Viene determinata contando il numero di operazioni aritmetiche e logiche, accesso al file, letture/scritture in memoria, etc.

## 1° Ipotesi semplificativa
- Consideriamo tutte le operazioni come eseguite da una **macchina ideale** e a **costo unitario** (tempo impiegato proporzionale al numero di operazioni eseguite)

## Esempio: prodotto matriciale
- Moltiplicazione di due matrici quadrate nxn di interi: **C=A * B**
- Per calcolare C[i,j] si eseguono 2n letture, n moltiplicationi, n-1 addizioni e 1 scrittura
- Per calcolare C: n^2(2 letture, n moltiplicazioni, n-1 addizioni ed 1 scrittura):
	- 2n^3 -> letture
	- n^3 -> moltiplicazioni
	- n^2*(n-1) -> addizioni
	- n^2 -> scritture
- C=(A*B) = 2n^3+n^3+n^2*(n-1)+n^2=4n^3


## Dimensione dei dati
- Il tempo impiegato per risolvere un problema dipende sia dall'algoritmo sia dalla **dimensione dei dati** a cui esso è applicato

###Oggetto in ingresso    Dimensione
- **vettore** 		   -> n elementi
- **matrice** 		   -> n elementi
- **matrice quadrata**  -> n elementi
- **matrice quadrata**  -> n righe
- **lista**				-> n elementi
- **albero** 				-> n elementi; altezza

## Ordini di grandezza
| n      | log2n | n*log2n | n^2 | n^3 | 2n |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| 2      | 1       | 2       | 4       | 8       | 4       |
| 10   | 3.322        | 33.22       | 10^2       | 10^3       | > 10^3       |
| 10^2      | 6.644       | 664.4       | 10^4       | 10^6       | >> 10^25       |
| 10^3   | 9.966        | 9996.0       | 10^6       | 10^9       | >> 10^250       |
| 10^4      | 13.287       | 1328.7       | 10^8       | 10^12       | >> 10^2500       |

## Notazione asintotica
- Un algoritmo ha un costo **f(n)=O(g(n))** se esistono opportune costanti c, n0 tali che:
- **f(n) < c*g(n)** per ogni **n > n0**

## A cosa serve la teoria della complessità?
- Per valutare quanto "difficile" è un problema
- Per valutare le risorse (spazio e tempo) necessarie per lo svolgimento di un algoritmo
- Per confrontare algoritmi risolutivi dello stesso problema
- Individuare algoritmi più efficienti

## Algoritmo migliore
Un algoritmo è migliore di un altro se la complessità in tempo del primo (A) è dominata dal secondo (B) ma non è vero il viceversa

## Complessità - Ipotesi semplificative
1. Consideriamo tutte le operazioni a costo unitario
2. Ci interessa l'andamento asintotico della funzione che calcola il costo piuttosto che la sua espressione specifica
3. **Istruzione dominante**: istruzione che incide maggiormente sul costo di complessità di un algoritmo
4. **Modello basato su confronti**: si conteggiano solo le operazioni di confronto e si trascurano le altre operazioni primitive


## Esempio
- In questo esempio il costo è O(N), se N è la dimensione del vettore

```C
#include <stdio.h>
#define N 15
typedef int vettore[N];

int minimo(vettore vet) {
	int i;
	int min = vet[0];
	
	for(i = 1; i<N; i++) {
		if(vet[i] < min) { /* istruzione dominante */
			min = vet[i];
		}
	}

	return min;
}

int massimo(vettore vet) {
	int i;
	int max = vet[0];
	
	for(i = 1; i<N; i++) {
		if(vet[i] > max) { /* istruzione dominante */
			max = vet[i];
		}
	}

	return max;
}

void main(void) {
	int i;
	vettore a;
	printf("Scrivi %d numeri interi\n", N);

	for(i=0; i<N; i++) {
		scanf("%d", &a[i]);
	}

	printf("Il minimo vale %d e il massimo è %d\n", minimo(a), massimo(a));
}
```

## Caso peggiore, migliore e medio
- è possibile distinguere diversi casi: **caso migliore**, **caso peggiore**, **caso medio**, in base al costo della dimensione dell'ingresso e dei valori dati in ingresso
- Di solito viene valutata nel **caso peggiore**


## Esempio - Ricerca esaustiva in un vettore di N elementi

```C
int ricerca(vettore vet, int el, int *pos) {
	int i = 0;
	int trovato = 0;
	while(i<N) { // istruzione dominante (eseguita N+1 volte nel caso peggiore)
		if(el == vet[i]) { // istruzione dominante (eseguita N volte nel caso peggiore)
			trovato = 1;
			*pos = i;
		}
		i++;
	}
	return trovato;
}
```

## Ricerca esaustiva (o sequenziale)
- Per la ricerca sequenziale in un vettore il costo dipende dalla posizione dell'elemento cercato
	- **Caso migliore**: l'elemento è il primo del vettore (1 confronto)
	- **Caso peggiore**: l'elemento è l'ultimo o non è presente: l'istruzione dominante è eseguita N volte (N dimensione del vettore. Il costo è **lineare, O(N)**
	- **Caso medio**: ciascun elemento è equiprobabile. Il costo è sempre **O(N)**

	
## Ricerca in array
- Se l'array non è ordinato -> ricerca esaustiva (o sequenziale)
- Se l'array è ordinato -> ricerca binaria
- La **ricerca binaria**, rispetto alla ricerca esaustiva, consente di eliminare ad ogni passo metà degli elementi del vettore

## Ricerca di un elemento
Sapendo che il vettore è **ordinato**, la ricerca può essere ottimizzata

- Vettore ordinato in senso non decrescente:

	| 2 | 3 | 5 | 5 | 7 | 8 | 10 | 11 |
	| --- | --- | --- | --- | --- | --- | --- | --- |
Se **i<j** si ha **V[i] <= V[j]**

- Vettore ordinato in senso crescente:
	
	| 2 | 3 | 5 | 6 | 7 | 8 | 10 | 11 |
	| --- | --- | --- | --- | --- | --- | --- | --- |
Se **i<j** si ha **V[i] < V[j]**

## Ricerca binaria in un vettore
- Vettore con indici da first a last, indice mediano **med = (first+last)/2**
- Si confronta l'elemento cercato **el** con quello mediano del vettore, **V[med]**
- Se **el == V[med]**, fine della ricerca (**trovato=true**)
- Altrimenti, se il vettore ha almeno un componente(**first <= last**):
	- se **el < V[med]**, ripeti la ricerca nella prima metà del vettore (**da first a med-1**)
	- se **el > V[med]**, ripeti la ricerca nella seconda metà del vettore (**da med+1 a last**)

	
## Ricerca binaria: complessità
- Come per la ricerca sequenziale, dipende dalla posizione dell'elemento cercato.
- **Caso migliore**: l'elemento cercato è quello mediano nel vettore (1 confronto)
- **Caso peggiore**: l'elemento cercato è l'ultimo o non è presente nel vettore. Il ciclo è ripetuto finchè ci si riduce ad un vettore monodimensionale (first==last)
- Ad ogni passo di iterazione la dimensione del vettore dimezza, si hanno al più k passi (con k finito e proporzionale a log2N)