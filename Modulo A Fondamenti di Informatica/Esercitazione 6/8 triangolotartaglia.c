// Si scriva un programma C che stampi a video il triangolo di Tartaglia fino alla settima riga.
// In ciascuna riga gli elementi di questa costruzione si ottengono come somma 
// di due elementi adiacenti della riga precedente (vedi anche figure in allegato).

#include <stdio.h>
#include <string.h>

#define N 10

int main()
{
    int array[N], temp[N], i, space, k, l;

    temp[0] = 1;

    // il primo elemento della riga è sempre 1
    array[0] = 1;

    for (space = 0; space < N; space++)
        printf("   ");
    printf("    1\n");

    for (i = 1; i < N; i++)
    {
        // STAMPO N - i spazi
        for (space = 0; space < N - i; space++)
            printf("   ");
        for (k = 1; k < i; k++)
        {
            // elementi intermedi della riga vengono aggiornati usando la riga precedente salvata in temp
            array[k] = temp[k - 1] + temp[k];
        }
        // l'ultimo elemento della riga è sempre 1
        array[i] = 1;
        for (l = 0; l <= i; l++)
        {
            // la stringa di formato %5d sta indicare che vanno stampati 5 spazi prima del numero
            printf("%5d ", array[l]);
            // mi salvo gli elementi appena stampati della riga in temp
            temp[l] = array[l];
        }
        printf("\n");
    }
}