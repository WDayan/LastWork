#include "ourLib.h"

int main(){
	
	int fn,size;
	TpContato *tp = start();
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
				scanf(" %d", &size);
				tp = createList(size);
				fillList(tp, size);
				printLista(tp, size);
				
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


TpContato *createList(int size){

	return (TpContato *) malloc(sizeof(TpContato) * size);

}


TpContato *start(){

	return NULL;
}


void fillList(TpContato *tp, int size){
	int i, num;

	for(i=0; i < size; i++){

		strcpy(tp[i].nome, "Fulano "); //Escrevendo "Fulano "
		num = rand()%100;								//Numero para concatenar com Fulano	
		sprintf(tp[i].nome, "%s%d", tp[i].nome, num);	//Peguei na net essa coisa.. funcionou hahaha ---> Fulano 'num'

		num = rand()%500000;
		sprintf(tp[i].fone, "%s%d", tp[i].fone, num); //Agora o telefone

	}

}


void printLista(TpContato *tp, int size){
	int i;
	printf("\nLista:\n\n");

	for(i=0; i < size; i++){

		printf("-----------------\n");
		printf("Nome: %s\nFone: %s\n", tp[i].nome, tp[i].fone);
	}

	printf("-----------------\n\n");
}


