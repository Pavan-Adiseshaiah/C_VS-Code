#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_SUCCESS 0
#define L_FAILURE 1

#define datatype int
#define size (sizeof(datatype))

#define Next (item -> next)
#define Prev (item -> prev)
#define Data (item -> data)

#define LENGTH 10

typedef struct item ITEM;

struct item {
    ITEM *next, *prev;
    char data[1];
};

ITEM *First = NULL, *Last = NULL, *Transferred = NULL;
int nitems=0;

int delete_list ()  {
    ITEM *item, *p;

    for (item = First; item; )  {
        p = item;
        item = Next;
        free (p);
    }

    return L_SUCCESS;
}

int append (void *data) {
    ITEM *item;

    if (!(item = malloc (sizeof (*item) + size - 1)))
        return L_FAILURE;
    
    Next = NULL;
    Prev = Last;
    memcpy (Data, data, size);

    if (Last)   {
        Last -> next = item;
        Last = item;
    }
    else
        First = Last = item;
    nitems++;

    return L_SUCCESS;
}

int read_next (void *data)   {
    if (!nitems)
        return L_FAILURE;
    
    if (!Transferred)
        Transferred = First;
    else if (!Transferred -> next)
        return L_FAILURE;
    else
        Transferred = Transferred -> next;
    
    memcpy(data, Transferred -> data, size);

    return L_SUCCESS;
}

int read_prev (void *data)  {
    if (!nitems)
        return L_FAILURE;

    if (!Transferred)
        Transferred = Last;
    else if (!Transferred -> prev)
        return L_FAILURE;
    else
        Transferred = Transferred -> prev;
    
    memcpy(data, Transferred -> data, size);

    return L_SUCCESS;
}

int delete_item ()  {
    register ITEM *item;

    if (!Transferred)
        return L_FAILURE;

    item = Transferred;

    if (item == First)
        First = Next;
    if (item == Last)
        Last = Prev;
    if (Prev)
        Prev -> next = Next;
    if (Next)
        Next -> prev = Prev;

    nitems--;
    Transferred = NULL;
    free (item);

    return L_SUCCESS;
}

void main ()    {
    char line[LENGTH];
    char *p;
    char *data;
    int val;

    while (1)   {
        printf ("<num> = append\tn = read next\tp = read prev\td = delete item\ti = no of items\te = exit\n");

        if (!fgets (line, LENGTH, stdin))   {
            fprintf (stderr, "Invalid input\n");
            exit(EXIT_FAILURE);
        }

        for (p=line; *p == ' ' || *p == '\t' || *p == '\n'; p++);

        switch (*p)  {
            default: continue;
            case 'i': case 'I':
                printf ("No of items in the list = %d\n", nitems);
                continue;
            case 'd': case 'D':
                if (delete_item())
                    fprintf (stderr, "Read before deleting the item\n");
                continue;
            case 'p': case 'P':
                if (read_prev(data))
                    fprintf (stderr, "No more items!\n");
                else
                    fprintf (stdout, "Item = %d\n", (datatype) *data);
                continue;
            case 'n': case 'N':
                if (read_next(data))
                    fprintf (stderr, "No more items!\n");
                else
                    fprintf (stdout, "Item = %d\n", (datatype) *data);
                continue;
            case 'e': case 'E':
                delete_list();
                exit (EXIT_SUCCESS);
            case '0': case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                val = atoi((const char *) p);
                if (append (&val))
                    fprintf (stderr, "Append failed\n");
                continue;
        }
    }
}