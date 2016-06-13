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

int isEmpty_vetor(TpContato *head);

void printVetor(TpContato *tp);

void vetcpy(TpContato *dest, TpContato *src);

void combSort_vetor(TpContato* tp);

void mergeSort(TpContato *h,int begin,int end, TpContato *temp);

void mergeArray(TpContato *h,int begin,int mid,int end, TpContato *temp);



// Funções da Lista
ListaContato *init();

ListaContato *createLista(int tam);

ListaContato *push(ListaContato* head, char nome[], char fone[]);

ListaContato *pop(ListaContato* head, TpContato contato);

int isEmpty_lista(ListaContato *head);

ListaContato *find(ListaContato* head, TpContato contato);

void printLista(ListaContato *h);

void combSort_lista(ListaContato* head, int tam);

ListaContato *listacpy(ListaContato *src);

ListaContato *mergeSortList(ListaContato *head, int begin, int end, ListaContato *aux);

ListaContato *mergeList(ListaContato *head, int begin, int mid, int end, ListaContato *aux);

ListaContato *backToStart(ListaContato *head);

ListaContato *runTo(ListaContato *head, int find);

ListaContato *anotherPush(char nome[], char fone[]);




