#include <stdio.h>

tabla_multiplicar(int n) {
    int i;
    int j;
    for (i = 1; i <= n; i = i + 1) {
        for (j = 1; j <= n; j = j + 1) {
            printf("%s %d", " ", i * j);
        }
        puts("\n");
    }
}

main() {
    puts("Tabla de multiplicar de 5:");
    tabla_multiplicar(5);
}

//@ (main)

