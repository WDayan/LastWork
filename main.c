#include "ourLib.h"

int main(){
	
	int fn,size;
	TpContato *tp = start();

	clock_t cinicio, cfinal;
	time_t tinicio, tfinal;
	
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
				break;
			case 2:
				system("clear");
				printf("\t2) Cirar Vetor\n");

				tp = createVetor();
				fillVetor(tp);
				printVetor(tp);

				break;
			case 3:
				system("clear");
				printf("\t3) Ordenacao com Comb Sort\n");

				cinicio = clock();
				tinicio = time(NULL);
				combSort_vetor(tp);
				cfinal = clock();
				tfinal = time(NULL);

				printf("\n");
				printVetor(tp);
				printf("Tempo: %f segundos.\n", (float)(cfinal-cinicio)/CLOCKS_PER_SEC);  // maior precisão!
				printf("Tempo: %ld segundos.\n", (tfinal-tinicio));
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

	if (tp != NULL) free(tp);

	return 0;
}


TpContato *createVetor(){
	return (TpContato *) malloc(sizeof(TpContato) * MAX);
}

TpContato *start(){
	return NULL;
}

void fillVetor(TpContato *tp){
	int i, j, num[3], fone[8];

	for(i=0; i < MAX; i++){

		strcpy(tp[i].nome, "Fulano ");								// Escrevendo "Fulano "
	
		for(j=0; j<3; j++) {										  // Numero para concatenar com Fulano
			num[j] = rand()%9;										 // Aumentar a 'aleatoriedade' dos numeros, mantendo em 3 digitos
			sprintf(tp[i].nome, "%s%d", tp[i].nome, num[j]);		// Peguei na net essa coisa.. funcionou hahaha ---> Fulano 'num'
		}

		for(j=0; j<8; j++){
			fone[j] = rand()%9; 									 // Aumentar a 'aleatoriedade' dos numeros, mantendo em 8 digitos
			sprintf(tp[i].fone, "%s%d", tp[i].fone, fone[j]); 		// Agora o telefone
		}
	}
}

void printVetor(TpContato *tp){
	int i;
	printf("\nVetor:\n\n");

	for(i=0; i < MAX; i++){

		printf("-----------------\n");
		printf("Nome: %s\nFone: %s\n", tp[i].nome, tp[i].fone);
	}

	printf("-----------------\n\n");
}

void combSort_vetor(TpContato* tp){
	int gap = MAX,
		swap = FALSE,
		i, j;

	TpContato aux;
		
	while(gap > 1 || swap == TRUE){
		gap = (int) gap / 1.3;
		if (gap < 1) gap = 1;
		printf("gap: %d\n", gap);
		swap = FALSE;
		
		for(i=0, j=gap; j < MAX; i++, j++){
			printf("i:j= %d:%d\n", i,j);
			if (strcmp(tp[i].nome,tp[j].nome) > 0){
				printf("troca= %s<->%s\n",tp[i].nome,tp[j].nome);
				aux  = tp[i];
				tp[i] = tp[j];
				tp[j] = aux;
				swap = TRUE;
			}	
		}
		printf("swap: %d\n", swap);
	}
}

