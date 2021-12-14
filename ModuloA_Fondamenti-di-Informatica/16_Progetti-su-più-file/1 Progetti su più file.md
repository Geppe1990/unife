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
  int f(int); // Dichiarazione della funzione
  
  main() {
  	int y = f(3); // Chiamata della funzione
  }
  ```



**Dichiarazione di funzione**

- La dichiarazione di una funzione è costituita dalla sola interfaccia costituita dalla sola interfaccia, senza corpo

  ```c
  int f(int);
  ```



**Dichiarazione vs Definizione**

- Dichiarazione

  ```c
  int f(int);
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

3. 



**ARRIVATO A 39:00**





**Riassunto**

```bash
gcc -c main.c f.c
gcc main.o f.o -o prog
./prog 
```