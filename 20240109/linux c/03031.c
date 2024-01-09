#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("%p : %d\n", (void *)&a, a);
    printf("%p : %d\n", (void *)p, *p);

    *p = *p + 10;
    printf("%p : %d\n", (void *)&a, a);
    printf("%p : %d\n", (void *)p, *p);

    a = 30;
    printf("%p : %d\n", (void *)&a, a);
    printf("%p : %d\n", (void *)p, *p);

    return 0;
}
