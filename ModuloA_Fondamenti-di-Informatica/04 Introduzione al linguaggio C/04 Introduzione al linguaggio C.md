**Caratteristiche del Linguaggio C**

- linguaggio sequenziale: le istruzioni vengono eseguite in sequenza una alla volta
- linguaggio imperativo: le istruzioni sono dei comandi imperativi, contiene l'assegnamento distruttivo
- strutturato a blocchi: ogni istruzione o costrutto ha un punto di ingresso e un punto d'uscita
- linguaggio di sistema: adatto a software, sistemi operativi
- portabile, efficiente, sintetico



**Struttura di un Programma C**

- Un programma C è definito in 3 parti:

  - zero o più unità di traduzione
  - il programma (main)
  - zero o più unità di traduzione

  ```
  <programma> ::=
  	{<unità-di-traduzione>} // Facoltativa
  	<main> // Obbligatoria
    {<unità-di-traduzione>} // Facoltativa
  ```



**Main**

- Il <main> è definito dalla parola chiave main() e racchiuso tra parentesi graffe al cui interno troviamo le dichiarazioni e definizioni (opzionali) e una sequenza di istruzioni (opzionali):

  ```
  <main> ::= main() <blocco>
  <blocco> ::=
  	{
  		[<dichiarazioni-e-definizioni>]
  		[sequenza-di-istruzioni]
  	}
  ```



**Esempio programma basilare in C**

```c
main()
{
}
```



**Commenti**

- Servono per inserire un testo all'interno del programma

- Il compilatore li scarta

- I commenti non possono essere innestati

- Sintassi

  ```
  <Commento> ::= /* <frase> */
  						| // <frase> \n
  <frase> ::= { <carattere> }		
  ```

  ```c
  main()
  {
  	/* un testo qualsiasi */
    // commento su una riga
  }
  ```



**Mostrare un testo**

- Per mostrare del testo a schermo si usa la funziona **printf()**

  ```c
  printf("testo");
  ```

- è presente all'interno della libreria **stdio**

- I testi, o stringhe, vanno wrappati nelle doppie virgolette **""** e non nelle singole

  

**Punto e virgola**

- Il punto e virgola serve per terminare un'istruzione
- Tutte le istruzioni devono avere il punto e virgola



**Librerie**

- Per includere le librerie si usa la direttiva **#include** all'inizio del programma

  ```c
  #include <stdio.h>
  
  main()
  {
  	printf("Testo da stampare a schermo")  
  }
  ```



**Caratteri di controllo**

- **Andare a capo**
  - Per andare a capo si usa il simbolo **\n**

    ```c
    printf("Testo\n")
    ```

- **Tabulazione**

  - Per tabulare si usa il simbolo **\t**

- **Backspace**

  - Per usare il backspace si usa il simbolo **\b**

- Carriage Return

  - Per usare il carriage return si usa il simbolo **\r**



**Primo programma**

```c
#include <stdio.h>

/*
	Programma che visualizza la
	scritta hello world
*/

main() {
	printf("Hello World\n");
}
```

