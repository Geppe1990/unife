#include <stdio.h>
 
main() {
    int anno, mese, giorno;
    int anno_succ, mese_succ, giorno_succ;
 
    printf("Inserisci la data: ");
    scanf("%d/%d/%d", &giorno, &mese, &anno);
 
    if(
        //se il giorno è 31 E (&&) il mese è uguale a 1 OPPURE 3 OPPURE 5 ecc.
        (giorno == 31 && (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12)) ||
        //se il giorno è 30 E (&&) il mese è uguale a 4 OPPURE 6 OPPURE 9 ecc.
        (giorno == 30 && (mese == 4 || mese == 6 || mese == 9 || mese == 11)) ||
        //se il giorno è 29 E (&&) il mese è uguale a 2 e se il resto dell'anno diviso 4 è 0 (bisestile)
        (giorno == 29 && mese == 2 && (anno % 4 == 0)) ||
        //se il giorno è 29 E (&&) il mese è uguale a 2 e se il resto dell'anno diviso 4 è diverso da 0 (NON bisestile)
        (giorno == 28 && mese == 2 && (anno % 4 != 0))
    ) {
        mese_succ = mese + 1;
        giorno_succ = 1;
 
        if(giorno == 31 && mese == 12) {
            anno_succ = anno + 1;
            mese_succ = 1;
        } else {
            anno_succ = anno;
        }
    } else {
        mese_succ = mese;
        giorno_succ = giorno + 1;
        anno_succ = anno;
    }
 
    printf("Data successiva: %d/%d/%d\n", giorno_succ, mese_succ, anno_succ);
}