#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 

typedef struct _contato{
	char nome[40];
	char fone[30];
}TpContato;

void combSort(int a[], int tam){
	int gap = tam;
	int swap = 1;
	int i, j, aux;
	printf("gap:swap= %d:%d\n", gap,swap);
	
	while(gap > 1 || swap == 0){
		gap = gap / 1.3;
		if (gap < 1) gap = 1;

		swap = 0;
		i = 0;
		j = i+gap;
		for(i=0, j=gap; j < tam; i++, j++){
			printf("i:j= %d:%d\n", i,j);
			if (a[i] > a[j]){
				printf("troca= %d<->%d\n",a[i],a[j]);
				aux  = a[i];
				a[i] = a[j];
				a[j] = aux;
				swap = 1;
			}	
		}
	}
}

void criarVetor(int v[]){
	int i;
	for (i=0; i<MAX; i++){
		v[i] = (rand()%MAX)*i;
	}
}

void imprimeVetor(int v[]){
	int i;
	for (i=0;i<MAX;i++){
		printf("%d\t", v[i]);
	}
	printf("\n");
}

int main(){
	
	int fn;
	int vTeste[MAX];

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
				criarVetor(vTeste);
				break;
			case 3:
				system("clear");
				printf("\t3) Ordenacao com Comb Sort\n");
				imprimeVetor(vTeste);
				combSort(vTeste,MAX);
				printf("\n");
				imprimeVetor(vTeste);
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