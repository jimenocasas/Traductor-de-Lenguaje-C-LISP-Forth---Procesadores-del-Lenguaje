#include <stdio.h>

int a;
int b;
int c;

main() {
    a = 2;
    
    while (a <= 150) {
        b = 2;
        c = 1; // 1 = primo, 0 = no primo
        
        while (b < a) {
            if (a % b == 0) {
                c = 0;
            }
            b = b + 1;
        }
        
        if (c == 1) {
            printf ("%d %s", a, " ") ;
            puts(" positivo ");
        }
        a = a + 1;
    }
}

//@ (main)

