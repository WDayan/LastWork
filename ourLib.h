#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 40

// me perco nas comparações kkk
#define TRUE 0
#define FALSE 1


typedef struct _contato{
	char nome[40];
	char fone[30];
}TpContato;

typedef struct _listaContato{
	TpContato contato;
	struct _listaContato *prev;
	struct _listaContato *next;
}ListaContato;

TpContato *start();

TpContato *createVetor();

void fillVetor(TpContato *tp);

void printVetor(TpContato *tp);

void combSort_vetor(TpContato* tp);

//void fillVetor(TpContato *tp, int size);

// Funções da Lista
ListaContato *init();

ListaContato *push(ListaContato* head, char nome[], char fone[]);

ListaContato *pop(ListaContato* head, TpContato contato);

int isEmpty(ListaContato *head);

ListaContato *find(ListaContato* head, TpContato contato);

void print(ListaContato *h);

void combSort_lista(ListaContato* head, int tam);