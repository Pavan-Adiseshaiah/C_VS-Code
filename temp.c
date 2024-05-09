#include <stdio.h>
#include <stdlib.h>

int main ()    {
    struct iabcd{
        int a;
        int b;
        struct {
            int c;
            int d;
        };
    };

    struct iabcd *p;
    struct iabcd val;
    p = &val;

    printf ("*p: %d\tval: %d\tint: %d\n", sizeof(p), sizeof(*p), sizeof(int));

    return 0;
}