#include <stdio.h>

#define f1(n) ((n) % 2 ? -1 : 1)
/* #define f2(n) (((n) % 2) * -2 + 1) */
/* #define f3(n) ((((n) & 1) << 1) - 1) */

int main(void) {
    int x = 0;
    for (unsigned int i = 0; i < 400000u; ++i) {
        x += f1(i);
    }
    printf("%d\n", x);
    return 0;
} 
