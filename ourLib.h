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


TpContato *start();

TpContato *createVetor();

void fillVetor(TpContato *tp);

void printVetor(TpContato *tp);

void combSort_vetor(TpContato* tp);

//void fillVetor(TpContato *tp, int size);
