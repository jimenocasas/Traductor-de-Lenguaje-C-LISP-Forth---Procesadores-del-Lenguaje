#include <stdio.h>

suma_recursiva(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + suma_recursiva(n - 1);
    }
}

main() {
    int resultado;
    resultado = suma_recursiva(10);
    printf("Suma recursiva de 10: %d\n", resultado);
}

//@ (main)
