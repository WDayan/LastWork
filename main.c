#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 40 

typedef struct _contato{
	char nome[40];
	char fone[30];
}TpContato;

int main(){
	
	int fn;
	system("clear");
	do{
		printf(
			"Escolha uma das opções abaixo:\n"
			"\t1) Criar Lista\n"
			"\t2) Cirar Vetor\n"
			"\t3) Ordenacao com Comb Sort\n"
			"\t4) Ordenacao com Merge Sort\n"
			"\t5) Sair\n\n"
		);

		scanf(" %d",&fn);
		switch(fn){
			case 1:
				system("clear");
				printf("Criar lista com quantos elementos?\n");
				
				break;
			case 2:
				system("clear");
				printf("\t2) Cirar Vetor\n");
				break;
			case 3:
				system("clear");
				printf("\t3) Ordenacao com Comb Sort\n");
				break;
			case 4:
				system("clear");
				printf("\t4) Ordenacao com Merge Sort\n");
				break;
			case 5:
				system("clear");
				printf("BYE!\n\n");
				break;
			default:
				system("clear");
				printf("Opção invalida!\n");
				break;
		}
	}while(fn != 5);
	return 0;
}