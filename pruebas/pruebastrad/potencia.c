#include <stdio.h>

potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else {
        return base * potencia(base, exponente - 1);
    }
}

main() {
    printf("%s %d\n", "2 elevado 5 = ", potencia(2, 5));
}

//@ (main)
