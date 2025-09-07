#include <stdio.h>

suma_hasta_n (int n) {
    int suma = 0;
    int i;
    for (i = 1; i <= n; i=i+1) {
        suma = i + suma;
    }
    return suma;
}

main() {
    printf("%s %d\n", "Suma hasta 10 = ", suma_hasta_n(10));
}

//@ (main)

