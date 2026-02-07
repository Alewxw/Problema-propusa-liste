#ifndef LISTE_H
#define LISTE_H

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct lista{
    node *head;
}lista;

typedef struct nod{
    int data;
    struct nod *prev, *next;
}nod;

typedef struct listd{
    nod *head;
}listd;

void lista_init ( lista *l );
void lista_insert ( lista *l, int *n );
void lista_suma_prod ( lista *l );

void lista_sort_val ( lista *l );
void lista_sort_point ( lista *l );

void lista_print ( lista *l );

int tab_hash ( int k, int n );
void tab_init ( lista *tab, int n );
void tab_insert ( lista *tab, int n, lista *l );

void lista_initd ( listd *duble );
void lista_par ( lista *l, listd *duble );
void lista_impar ( lista *l, listd *duble );
void lista_interclasare ( listd *par, listd *impar,  listd *rez );
void lista_sort_point_par ( listd *duble );

void lista_afis ( listd *duble );



#endif // __liste

