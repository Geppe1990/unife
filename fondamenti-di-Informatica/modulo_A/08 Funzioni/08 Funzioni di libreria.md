- Il linguaggio C ha il concetto di funzione

- Libreria **math** contiene funzioni di calcolo/matematiche

  ```c
  #include <math.h>
  
  sin()  // seno
  cos()  // coseno
  sqrt() // radice quadrata
  ```

- **Esempio**

  ```c
  #include <stdio.h>
  #include <math.h>
  
  main() {
  	float a, b, c;
  	scanf("%f %f", &a, &b);
  	c = sqrt(a*a+b*b);
  	printf("La diagonale è %f\n", c)
  }
  ```



- Le funzioni si usano all'interno delle espressioni, come gli operatori del linguaggio C (come +, -, *, ...)

  ```c
  c = sqrt(a*a+b*b)
  ```

  

- Invocazione della funzione:
  - nome della funzione: es: sqrt
  - parametri attuali: 
    - Costanti: x = sqrt(2);
    - Variabili: x = sqrt(y);
    - Espressioni: x = sqrt(3*y+1);