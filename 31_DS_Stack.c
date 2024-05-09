#include <stdio.h>
#include <stdlib.h>

void main ()    {
    int i[] = {250, 350};
    int *c=i;

    //c = i;
    printf ("c = %d\n", *c);
    printf("addr: %lu\n", c);
    int t = *c++;
    printf ("t = %d\n", t);
    printf ("c = %d\n", *c);
    printf("addr: %lu\n", c);
    int x = *--c;
    printf ("x = %d\n", x);
    printf ("c-- = %d\n", *c);
    printf("addr: %lu\n", c);

    exit (0);
}