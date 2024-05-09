#include<stdio.h>
#include<stdlib.h>

int main() {

    int *p = (int *) malloc (sizeof (int));
    *p = 5;

    printf ("%d\n", *p);
    free (p);

    // p is a dangling pointer here

    printf ("%d\n", *p);
    
    return 0;
    
    exit (0);
    
}
