// Si calcoli il valore di π approssimato. Si utilizzi la formula sottostante.
// Il numero di addendi (corrispondenti alla precisione del calcolo) dovrà essere 
// dato in input prima dell’esecuzione del calcolo. Ad ogni iterazione stampare il valore 
// corrente di π.

// // VARIANTE: Si chieda all’utente l’approssimazione E con cui si vuole effettuare 
//il calcolo e terminare la computazione quando l'errore è inferiore a tale valore. 
// L'errore può essere stimato considerando la differenza (in valore assoluto) 
//fra il valore di π e quello ottenuto all'iterazione precedente. 
// Ad ogni iterazione stampare il valore corrente di π.
#include <stdio.h>

int main() {
	int num, den,i=1;
    float pi=0,term, prec, absterm;
    printf("Inserisci precisione: ");
    scanf("%f",&prec);
    
    num = 1;
    den = 1;
    do
    {
        term = 4*num/(float) den;
        if (term<0)
            absterm = - term;
        else absterm = term;
        
        pi = pi + term;
        printf("%d. pi= %f\n",i,pi);
        i++;
        num = -num;
        den = den+2;
    }
    while (absterm>prec);
}