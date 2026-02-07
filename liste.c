#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

void lista_init ( lista *l )
{
    l->head = malloc(sizeof(node));
    if ( !l->head ) return ;

    l->head->next = NULL;
    l->head->data = -1;
}

void lista_insert ( lista *l, int *n )
{
    if ( !l || !l->head ) return ;
    int x = -1;

    while ( x != 0 )
    {
        scanf("%d", &x);
        if ( x == 0 ) return ;

        node *aux = malloc(sizeof(node));
        if ( !aux ) return;

        aux->data = x;
        aux->next = l->head->next;
        l->head->next = aux;

        (*n)++;
    }
}

void lista_insert_elem ( lista *l, int elem )
{
    node *aux = malloc(sizeof(node));

    aux->data = elem;
    aux->next = l->head->next;
    l->head->next = aux;
}

void lista_suma_prod ( lista *l )
{
    int sum = 0, prod = 1;
    node *aux = l->head->next;

    while ( aux != NULL )
    {
        sum += aux->data;
        prod *= aux->data;

        aux = aux->next;
    }

    printf("%d %d\n", sum, prod);
}

void lista_sort_val ( lista *l )
{
    int v[1001], n = 0;
    node *aux = l->head->next;

    while ( aux != NULL )
    {
        v[n++] = aux->data;
        aux = aux->next;
    }

    for ( int i = 0 ; i < n - 1 ; i ++ )
        for ( int j = i + 1 ; j < n ; j ++ )
            if ( v[i] > v[j] )
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    node *tmp = l->head->next;
    for ( int i = 0 ; i < n ; i ++, tmp = tmp->next )
            tmp->data = v[i];

}

void lista_circ ( lista *l )
{
    node *aux = l->head->next;

    while ( aux->next != NULL )
        aux = aux->next;

    aux->next = l->head;
}

void lista_sort_point ( lista *l )
{
    if ( !l || !l->head ) return ;

    int swapped;
    node **p;

    do{
        swapped = 0;
        p = &l->head->next;

        while ( (*p)->next != NULL )
        {
            node *a = *p;
            node *b = a->next;

            if ( a->data > b->data )
            {
                a->next = b->next;
                b->next = a;
                *p = b;

                swapped = 1;
            }

            p = &((*p)->next);
        }

    }while(swapped);
}

int tab_hash ( int k, int n )
{
    return k % n;
}

void tab_init ( lista *tab, int n )
{
    for ( int i = 0 ; i < n ; i ++ )
        lista_init(&tab[i]);
}

void tab_insert ( lista *tab, int n, lista *l )
{
    node *aux = l->head->next;

    while ( NULL != aux )
    {
        int index = tab_hash(aux->data, n);
        lista_insert_elem(&tab[index], aux->data);
        aux = aux->next;
    }
}

void lista_print ( lista *l )
{
    node *aux = l->head->next;

    while ( aux != NULL )
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
}

void lista_initd ( listd *duble )
{
    duble->head = malloc(sizeof(nod));
    if ( !duble->head ) return ;

    duble->head->next = NULL;
    duble->head->prev = NULL;
}

void lista_par ( lista *l, listd *duble )
{
    node *aux = l->head->next;
    nod *tail = duble->head;

    while ( NULL != aux )
    {
        if ( aux->data % 2 == 0 )

        {
            nod *nou = malloc(sizeof(nod));
            nou->data = aux->data;
            nou->next = NULL;
            nou->prev = tail;

            tail->next = nou;
            tail = nou;
        }

        aux = aux->next;
    }
}

void lista_impar ( lista *l, listd *duble )
{
    lista_sort_point(l);

    node *aux = l->head->next;
    nod *prev = duble->head;

     while ( NULL != aux )
     {
         if ( aux->data % 2 == 1 )
         {
             nod *nou = malloc(sizeof(nod));
             nou->data = aux->data;
             nou->next = NULL;
             nou->prev = prev;

             prev->next = nou;
             prev = nou;
         }

         aux = aux->next;
     }
}

void lista_sort_point_par(listd *duble)
{
    if (!duble || !duble->head) return;

    int swapped;
    nod *p;

    do {
        swapped = 0;
        p = duble->head->next;

        while (p && p->next)
        {
            if (p->data > p->next->data)
            {
                int tmp = p->data;
                p->data = p->next->data;
                p->next->data = tmp;
                swapped = 1;
            }
            p = p->next;
        }
    } while (swapped);
}


void lista_interclasare ( listd *par, listd *impar,  listd *rez )
{
    lista_sort_point_par(par);
    nod *auxp = par->head->next, *auxi = impar->head->next, *prev = rez->head;


    while ( NULL != auxp && NULL != auxi )
    {
        nod *nou = malloc(sizeof(nod));
        if ( !nou ) return ;

        if ( auxp->data > auxi->data )
        {
            nou->data = auxi->data;
            auxi = auxi->next;
        }
        else{
            nou->data = auxp->data;
            auxp = auxp->next;
        }

        nou->prev = prev;
        nou->next = NULL;
        prev->next = nou;
        prev = nou;
    }

    while ( auxp )
    {
        nod *nou = malloc(sizeof(nod));
        nou->data = auxp->data;

        nou->prev = prev;
        nou->next = NULL;

        prev->next = nou;
        prev = nou;

        auxp = auxp->next;
    }

    while ( auxi )
    {
        nod *nou = malloc(sizeof(nod));
        nou->data = auxi->data;

        nou->next = NULL;
        nou->prev = prev;

        prev->next = nou;
        prev = nou;

        auxi = auxi->next;
    }
}

void listd_circ ( listd *duble )
{
    nod *aux = duble->head->next;

    while ( NULL != aux->next )
        aux = aux->next;

    aux->next = duble->head;
    duble->head->prev = aux;
}

void lista_afis ( listd *duble )
{
    nod *aux = duble->head->next;
    while( NULL != aux )
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

