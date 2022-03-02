// Approssimare la funzione del seno con la serie di Taylor: chiedere all'utente un valore reale x (float), ossia l'angolo di cui calcolare il seno (compreso tra -3,14 e +3,14) e un livello di approssimazione L, un intero dispari a cui fermarsi (nell'immagine questo livello è imposto a 7).
// Stampare a video il risultato finale.

// P.S.: fare i dovuti controlli sui numeri prima di eseguire il calcolo ed eventualmente chiedere di reinserire i valori fino a quando non sono corretti

#include <stdio.h>

int main(){
    float x, fatt = 1, potenza = 1;
    int l, c=1;
    float sen = 0;

    do{
        printf("Inserire un valore compreso tra -3,14 e +3,14: ");
        scanf("%f", &x);
    }while(x<-3.14 || x>3.14);

    do{
        printf("Inserire un intero dispari: ");
        scanf("%d", &l);
    }while(l%2 == 0);

    for(int i = 1; i<=l; i+=2){
        fatt = 1;
        potenza = 1;
        for(int j = 1; j<=i;j++){
            //qui calcolo il fattoriale e la potenza
            fatt = fatt*j;
            potenza = potenza*x;            
        }
        if(c%2==1){
            sen = sen + potenza/fatt;
        }
        else{
            sen = sen - potenza/fatt;
        }
        c++;
    }

    printf("sen(%f) = %.7f", x, sen);

}