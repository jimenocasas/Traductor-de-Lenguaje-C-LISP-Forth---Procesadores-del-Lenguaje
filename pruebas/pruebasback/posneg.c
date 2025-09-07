#include <stdio.h>

int numero;

main() {
    numero = -14;
    
    if (numero != 0) {
        if (numero % 2 == 0) {
            printf("%d %s",  numero, " es par y ");
        } else {
            printf("%d %s",  numero, " es impar y ");
        }
        
        if (numero > 0) {
            puts(" positivo ");
        } else {
            puts(" negativo ");
        }
    } else {
        puts(" El número es cero ");
    }
}

//@ (main)
