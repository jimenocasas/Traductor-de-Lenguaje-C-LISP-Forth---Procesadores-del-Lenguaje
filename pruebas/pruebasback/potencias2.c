#include <stdio.h>

int potencia;
int exponente;

main() {
    exponente = 0;
    potencia = 1;
    puts(" Potencias de 2: ");

    while (exponente <= 10) {
        printf("%d", potencia);
        potencia = potencia * 2;
        exponente = exponente + 1;
    }
}

//@ (main)
