#include <stdio.h>

clasificar_numero(int n) {
    if (n > 0) {
        printf("%d %s",n, ": El número es positivo.  ");
    }
    if (n < 0) {
        printf("%d %s",n, ": El número es negativo.  ");
    }
    if (n == 0) {
        printf("%d %s",n, ": El número es cero.  ");
    }
}

main() {
    clasificar_numero(5);
    clasificar_numero(-3);
    clasificar_numero(0);
    return 0;
}

//@(main)
