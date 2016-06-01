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

TpContato *createVetor();

void fillVetor(TpContato *tp);

void printVetor(TpContato *tp);

//void fillVetor(TpContato *tp, int size);
