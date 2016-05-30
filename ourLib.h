#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 40 


typedef struct _contato{
	char nome[40];
	char fone[30];
}TpContato;


TpContato *start();

TpContato *createList();

void fillList(TpContato *tp, int size);

void printLista(TpContato *tp, int size);
