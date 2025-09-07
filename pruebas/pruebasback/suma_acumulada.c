#include <stdio.h>

int suma;
int n;

main() {
    n = 5;
    suma = 0;
    
    while (n > 0) {
        suma = suma + n;
        n = n - 1;
    }
    printf("La suma es: %d\n", suma);
}

//@ (main)
