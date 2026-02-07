#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main ()
{
    int n = 0;
    lista l;
    lista_init(&l);

    lista_insert(&l, &n);
    printf("%d\n", n);

    lista_print(&l);
    printf("\n");
    lista_suma_prod(&l);

    lista *tab = malloc(n*sizeof(lista));

    tab_init(tab, n);
    tab_insert(tab, n, &l);

    for ( int i = 0 ; i < n ; i ++ )
    {
        lista_print(&tab[i]);
        printf("\n");
    }

    listd dublep, dublei;
    lista_initd(&dublep);
    lista_initd(&dublei);
    lista_par(&l, &dublep);
    lista_impar(&l, &dublei);

    lista_afis(&dublep);
    lista_afis(&dublei);

    listd rez;
    lista_initd(&rez);

    lista_interclasare(&dublep, &dublei, &rez);
    lista_afis(&rez);
    return 0;
}
