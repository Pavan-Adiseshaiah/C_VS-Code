#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf jmp_place;                                  //Stack datastructure - Contains sp, fp and other registers

void handler (int sig_no)   {
    printf ("In handler before longjmp\n");
    longjmp(jmp_place, 1);
    printf ("After longjmp\n");                     //Never printed
}

void main ()    {

    signal (SIGALRM, handler);
    alarm (3);

    if (!setjmp (jmp_place))
        printf ("Jump location set\n");
    else    {
        printf ("Returned from longjmp\n");
        exit (EXIT_SUCCESS + SIGALRM);              //0+14 = 14
    }

    while (1);

    exit (EXIT_SUCCESS);
}
