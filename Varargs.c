#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//-----------------------------Without using Macros defined in stdarg-----------------------------
int vadd_no_macros  (int nint, ...) {
    int *varg_list;                             //This will only work if variables are on stack.
    int total = 0;                              //RISC (AMD, SUN) - The calling param are in registers only -> Doesn't work there.

    varg_list = (&nint + 2);                    //+2 -> Because always long is pushed onto the stack. Therefore, if short --> use +4
    
    while (nint--)
        total += (varg_list += 2) [-2];         //same reason for +2 and accessing [-2]
    
    return total;
}

//-----------------------------Using Macros defined in stdarg-------------------------------------
int vadd_macros (int nint, ...) {
    va_list va;
    int total = 0;

    va_start (va, nint);

    while (nint--)
        total += va_arg(va, int);
    
    va_end(va);

    return total;
}

void main ()    {
    printf ("Total = %d\n", vadd_no_macros(3, 1, 2, 3));        //6
    printf ("Total = %d\n", vadd_no_macros(5, 1, 2, 3, 4, 5));  //15

    printf ("Total = %d\n", vadd_macros(3, 1, 2, 3));           //6
    printf ("Total = %d\n", vadd_macros(5, 1, 2, 3, 4, 5));     //15

    exit (0);
}