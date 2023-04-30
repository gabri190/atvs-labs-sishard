#include <stdio.h>
int ex5_solucao() {
    int retval, ebx = 0, a = 1;
    while (a > 0) {
        scanf("%d", &a);
        retval = a;
        if (retval > 0) {
            ebx+=retval;
        }
    }
    return ebx;
}