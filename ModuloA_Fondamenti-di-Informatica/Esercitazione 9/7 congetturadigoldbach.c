// Nel margine di una lettera ad Eulero (1742), il matematico prussiano Christian Goldbach formulava un’ipotesi che, in termini moderni, viene spesso descritta così: “Ogni intero pari maggiore di 2 può essere scritto come la somma di due numeri primi”.

// Si scriva una funzione con la seguente interfaccia:
// int goldbach (int n, int* primo1, int* primo2)

// Tale funzione, dato un intero n, fornisce:
// - come valore di ritorno un valore intero 0/1 (falso/vero) che comunica se il numero n può essere scomposto nella somma di due numeri primi;
// - (qualora sia possibile) due numeri primi (primo1, primo2) che danno come somma n.

#include <stdio.h>
#include <math.h>

int controlloPrimo(int n)
{

	int i;
	int EPrimo = 1;

	for (i = 2; i < sqrt((double)n); i++)
	{

		if (n % i == 0)
		{
			EPrimo = 0;
		}
	}

	return EPrimo;
}

int goldbach(int n, int *primo1, int *primo2)
{

	int possibile = 0;
	int i = 1;
	int EPrimo1, EPrimo2;

	while ((possibile == 0) && i <= n - 1)
	{

		//PER OGNI NUMERO i DA 1 A n - 1 CONTROLLO SE E' PRIMO E SE ANCHE n-i LO E'

		EPrimo1 = controlloPrimo(i);
		EPrimo2 = controlloPrimo(n - i);

		if (EPrimo1 == 1 && EPrimo2 == 1)
		{

			possibile = 1;
			*primo1 = i;
			*primo2 = n - i;
		}
		else
		{

			i++;
		}
	}

	return possibile;
}

int main()
{

	int n, scomponibile;
	int primoPrimo, secondoPrimo;
	//printf("Inserisci un numero pari maggiore di 2\n");
	//scanf("%d", &n);
	for (n = 2; n <= 100; n = n + 2)
	{
		scomponibile = goldbach(n, &primoPrimo, &secondoPrimo);

		if (scomponibile)
		{

			printf("Il numero %d e' scomponibile in %d e %d\n", n, primoPrimo, secondoPrimo);
		}
		else
		{

			printf("Il numero non e' scomponibile\n");
		}
	}
}