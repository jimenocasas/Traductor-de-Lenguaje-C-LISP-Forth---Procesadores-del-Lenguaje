#include <stdio.h>


factorial(int n) {
    int resultado = 1;
    int i = 1;
    while (i <= n) {
        resultado = resultado * i;
        i = i + 1;
    }
    return resultado;
}

main() {
    printf("%s %d","El factorial 5 de es: ", factorial (5));
}

//@(main)
