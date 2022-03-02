**Programma**

- Un programma in linguaggio C è una sequenza di caratteri che rispetta le regole grammaticali del linguaggio C



**Progetti su più file**

- Si fanno progetti su piu file per:
  - gestire grandi programmi
  - gestire il programma a moduli che si occupano di aspetti diversi 
  - riutilizzare il codice
  - facilitare il lavoro in team
  - vendita di librerie



**Progetti strutturati su più file**

- Supponiamo di avere 3 file: f.c - main.c

  ```c
  // f.c
  int f(int n) { // Definizione della funzione
  	return n*2;
  }
  ```

  ```c
  // main.c
  int f(int n); // Dichiarazione della funzione
  
  main() {
  	int y = f(3); // Chiamata della funzione
  }
  ```



**Dichiarazione di funzione**

- La dichiarazione di una funzione è costituita dalla sola interfaccia costituita dalla sola interfaccia, senza corpo

  ```c
  int f(int n);
  ```



**Dichiarazione vs Definizione**

- Dichiarazione

  ```c
  int f(int n);
  ```

  - costituisce solo una specifica delle proprietà del componente
  - può essere duplicata
  - un'applicazione può contenerne più di una
  - la compilazione di una dichiarazione non genera codice macchina

- Definizione

  ```c
  int f(int n) {
  	return n*2
  }
  ```

  - costituisce l'effettiva realizzazione del componente
  - non può essere duplicata
  - ogni applicazione deve contenere solo una definizione per ogni funzione
  - La compilazione genera codice macchina che verrà eseguito ogni volta che la funzione viene chiamata
  - definizione = dichiarazione + corpo
  - la definizione funge anche da dichiarazione (ma non viceversa)



**Compilazione di un'applicazione**

1. Compilare i singoli file (i file .o non sono eseguibili)

   ```bash
   gcc -c filesorgente
   gcc -c f1.c
   ```

   - f1.c -> compilatore -> f1.o
   - f2.c -> compilatore -> f2.o
   - f3.c -> compilatore -> f3.o

2. Collegare i file oggetto fra loro e con le librerie di sistema (attraverso il linker)

   - Il programma per il linting su UNIX si chiama **ld**

   - Si può eseguire il linking anche via **gcc** con il parametro i file oggetto e il nome del file preceduto da -o nomefile

     ```bash
     gcc f1.o f2.o f3.o -o nomefile
     ```



**Riassunto**

```bash
gcc -c main.c f.c
gcc main.o f.o -o prog
./prog 
```



**Header File**

- Contiene tutte le dichiarazioni delle funzioni
- è necessario includerlo con #include
- ha estensione .h
- per convenzione ha lo stesso nome del file .c di cui fornisce le dichiarazioni
  - es:
    - se la funzione **f** è definita nel file **f2c.c**
    - il corrispondente header dovrebbe chiamarsi **f2c.h**



**Direttiva #include**

- è una direttiva del preprocessore
- Il preprocessore sostituisce testualmente la direttiva con il contenuto del file incluso
- Due formati
  - #include <libreria.h> (il sistema sa dove trovare una libreria)
  - #include "miofile.h" (è necessario specificare dove reperirlo)



**Esempio Header**

- ESEMPIO 1 - FILE INTERO

  ```c
  float fahrToCelsius(float f) {
  	return 5.0/9 * (f-32);
  }
  
  main() {
  	float c;
  	c = fahrToCelsius(86);
  }
  ```

- ESEMPIO 2 - FILE SEPARATI

  ```c
  // file main.c
  
  float fahrToCelsius(float f);
  
  main() {
  	float c;
  	c = fahrToCelsius(86);
  }
  ```

  ```c
  // file f2c.c
  
  float fahrToCelsius(float f) {
  	return 5.0/9 * (f-32);
  }
  ```

- ESEMPIO 3 - FILE SEPARATI + HEADER

  ```c
  // file main.c
  #include "f2c.h"
  
  main() {
  	float c;
  	c = fahrToCelsius(86);
  }
  ```

  ```c
  // file f2c.c
  
  float fahrToCelsius(float f) {
  	return 5.0/9 * (f-32);
  }
  ```

  ```c
  // file f2c.h
  
  float fahrToCelsius(float f);
  ```



**Progetto**

- è un contenitore di file sorgente
- elenca i file sorgente dell'applicazione