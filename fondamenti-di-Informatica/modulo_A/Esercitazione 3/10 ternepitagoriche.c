// Realizzare un programma C che, chiesto all’utente un numero intero pari a N, 
// ricavi e stampi a video tutte le terne pitagoriche con i cateti minori o uguali ad N.

// Una terna pitagorica è formata da tre numeri naturali (a, b, c) tali che a^2 + b^2 = c^2.
// Esempio 3,4,5 -> (9+16=25).

// Calcolare solo le terne in cui a < b.
// Risolvere il problema 𝐬𝐞𝐧𝐳𝐚 il calcolo esplicito della radice quadrata.

#include <stdio.h>

int main() 
{	int n, a, b, c;
	printf("Inserisci il valore di n: ");
	scanf("\n%d", &n);
	for(a=1; a<=n; a++) 
	{	for(b=a+1; b<=n ; b++) 
		{	for(c=((a-b)+1); c<(a+b); c++) 
			{	if (a*a+b*b==c*c)
					printf("%d, %d, %d\n", a, b, c);
			}
		}
	}
}