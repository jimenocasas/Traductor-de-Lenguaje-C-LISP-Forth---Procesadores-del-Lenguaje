#include <stdio.h>

mcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mcd(b, a % b);
    }
}

main() {
    printf("%s %d\n", "MCD de 48 y 18:", mcd(48, 18));
}

//@ (main)
