#include "ourLib.h"

int main(){
	
	int fn,size;
	TpContato *tp = start();
	ListaContato *lista = init(), *lista_copy=init(), *lista_aux=init();
	TpContato *aux = start(), *copy = aux;

	clock_t cinicio, cfinal;
	
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
				lista = createLista(size);
				printLista(lista);
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

				if (!isEmpty_vetor(tp)){
					cinicio = clock();
					combSort_vetor(tp);
					cfinal = clock();
					printf("\n");
					printVetor(tp);
					printf("Tempo: %f segundos.\n", (float)(cfinal-cinicio)/CLOCKS_PER_SEC);
				}
				if (!isEmpty_lista(lista)){
					cinicio = clock();
					combSort_lista(lista,size);
					cfinal = clock();
					printf("\n");
					printLista(lista);
					printf("Tempo: %f segundos.\n", (float)(cfinal-cinicio)/CLOCKS_PER_SEC);
				}

				break;
			case 4:
				system("clear");
				printf("\t4) Ordenacao com Merge Sort\n");

				if (!isEmpty_vetor(tp)){
					aux = createVetor();
					copy = createVetor();
					vetcpy(copy, tp);

					cinicio = clock();
					mergeSort(copy, 0, MAX-1, aux);	// Vetor vai de 0-39
					cfinal = clock();

					printf("\n");
					printVetor(copy);
					printf("Tempo: %f segundos.\n", (float)(cfinal-cinicio)/CLOCKS_PER_SEC);

					if (!isEmpty_vetor(aux)) free(aux); 	// Liberando memória
				}

				if (!isEmpty_lista(lista)){
					lista_copy = listacpy(lista);

					cinicio = clock();
					lista_aux = mergeSortList(lista_copy, 0, size-1, lista_aux);	
					cfinal = clock();

					printf("\n");
					printLista(lista_copy);
					printf("Tempo: %f segundos.\n", (float)(cfinal-cinicio)/CLOCKS_PER_SEC);
					lista_copy = ourFree(lista_copy);
					lista_aux = ourFree(lista_aux);

				}
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
	while (!isEmpty_lista(lista)){
		lista = pop(lista, lista->contato);
	}
	
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

		strcpy(tp[i].nome, "Fulano ");								 // Escrevendo "Fulano "
		strcpy(tp[i].fone, "");										// Inicializano fone
	
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

int isEmpty_vetor(TpContato *head){
	if (head == NULL){
		return 1;
	}else {
		return 0;
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

void vetcpy(TpContato *dest, TpContato *src){

	int i=0;							//Copiando os valores de SRC para DEST
	while(i < MAX){
		strcpy(dest[i].nome, src[i].nome);			
		strcpy(dest[i].fone, src[i].fone);
		i++;
	}
}



void combSort_vetor(TpContato* tp){
	int gap = MAX,
		swap = FALSE,
		i, j;

	TpContato aux;
		
	while(gap > 1 || swap == TRUE){
		gap = (int) gap / 1.3;
		if (gap < 1) gap = 1;
		swap = FALSE;
		
		for(i=0, j=gap; j < MAX; i++, j++){
			if (strcmp(tp[i].nome,tp[j].nome) > 0){
				aux  = tp[i];
				tp[i] = tp[j];
				tp[j] = aux;
				swap = TRUE;
			}	
		}
	}
}





void mergeArray(TpContato *h,int begin,int mid,int end, TpContato *temp){

    int i = begin,j = mid + 1;
    int m = mid,n = end;
    int k = 0;	//contador do temporario

    while(i <= m && j <= n){ 						//Entra para fazer a comparação 
    	if(strcmp(h[i].nome, h[j].nome) <= 0){		//Se o 1° <= 2°
			strcpy(temp[k].nome, h[i].nome);		//Copia o primeiro
			strcpy(temp[k++].fone, h[i++].fone);
        }
		else{										//Senao
			strcpy(temp[k].nome, h[j].nome);		//Copia o segundo
			strcpy(temp[k++].fone, h[j++].fone);	//Passa o segundo pra frente.
        }
    }

    while(i <= m){									//Caso nao tenha sido feito alterações antes do meio
		strcpy(temp[k].nome, h[i].nome);			//Copiar eles do jeito que estao
		strcpy(temp[k++].fone, h[i++].fone);
    }

    while(j <= n){									//Caso nao tenha sido feito alterações depois do meio
		strcpy(temp[k].nome, h[j].nome);			//Copiar eles do jeito que estao
		strcpy(temp[k++].fone, h[j++].fone);
    }
													
    for(i = 0;i < k;i++){							//Salvando do temp no titular  
		strcpy(h[begin + i].nome, temp[i].nome);
		strcpy(h[begin + i].fone, temp[i].fone);
    }

}

void mergeSort(TpContato *h,int begin,int end, TpContato *temp){
    if(begin < end){

        int mid = (begin + end) / 2;

        mergeSort(h,begin,mid,temp);   
        mergeSort(h,mid + 1,end,temp);   
        mergeArray(h,begin,mid,end,temp); 
    }
}



// Funções da Lista

ListaContato *init(){
	return NULL;
}

ListaContato *createLista(int tam){
	int i, j, num[3], fone_num[8];
	char nome[40], fone[30];
	ListaContato *lista = init();
	
	for(i=0; i < tam; i++){

		strcpy(nome, "Fulano ");		 				 // Escrevendo "Fulano "
		strcpy(fone, "");								// Inicializano fone
	
		for(j=0; j<3; j++) {							  // Numero para concatenar com Fulano
			num[j] = rand()%9;							 // Aumentar a 'aleatoriedade' dos numeros, mantendo em 3 digitos
			sprintf(nome, "%s%d", nome, num[j]);		// Peguei na net essa coisa.. funcionou hahaha ---> Fulano 'num'
		}

		for(j=0; j<8; j++){
			fone_num[j] = rand()%9; 					 // Aumentar a 'aleatoriedade' dos numeros, mantendo em 8 digitos
			sprintf(fone, "%s%d", fone, fone_num[j]); 	// Agora o telefone
		}

		lista = push(lista,nome,fone);
	}

	return lista;
}

ListaContato *anotherPush(char nome[], char fone[]){

	ListaContato *novo = (ListaContato *) malloc(sizeof(ListaContato));
	strcpy(novo->contato.nome,nome);
	strcpy(novo->contato.fone,fone);
	
	novo->prev = NULL;
	novo->next = NULL;

	return novo;
}

ListaContato *push(ListaContato* head, char nome[], char fone[]){
	ListaContato 	*this=head,
		 			*previous=init(),
		 			*novo = init();

	novo = (ListaContato *) malloc(sizeof(ListaContato));
	strcpy(novo->contato.nome,nome);
	strcpy(novo->contato.fone,fone);
	
	
	while(this!=NULL){
		previous = this;
		this = this->next;
	}	
	if (previous != NULL){
		if (previous->next != NULL){
			novo->prev = previous;
			novo->next = previous->next;
			previous->next = novo;
			return head;
		}else{
			novo->prev = previous;
			novo->next = init();
			previous->next = novo;
			return head;
		}
	}else if (this==head){
		novo->next = head;
		novo->prev = init();
		return novo;
	}
	return head;
}

ListaContato *pop(ListaContato* head, TpContato contato){
	ListaContato *pop = init(),
				 *previous = init(),
				 *next = init();

	pop = find(head,contato);

	if (pop==NULL){
		return head;
	}
	previous = pop->prev;
	next = pop->next;

	if (previous == NULL){
		if (next == NULL) {
			head=init();
		}else{
			next->prev = init();
			head=next;
		}
	}else{
		if (next == NULL) {
			previous->next = NULL;
		}else{
			previous->next = next;
			next->prev = previous;
		}
	}
	free(pop);
	return head;
}

int isEmpty_lista(ListaContato *head){
	if (head == NULL){
		return 1;
	}else {
		return 0;
	}
}


ListaContato *find(ListaContato* head, TpContato contato){
	ListaContato *p = init();
	for(p=head; p!=NULL; p=p->next){
		if( (strcmp(p->contato.nome,contato.nome) == 0) && (strcmp(p->contato.fone,contato.fone) == 0) ){
			return p;
		}
	}
	return NULL; //Elemento não está na lista
}

void printLista(ListaContato *h){
	ListaContato* p=init();
	printf("\nLista:\n\n");

	for(p=h; p!=NULL; p=p->next){
		printf("-----------------\n");
		printf("Nome: %s\nFone: %s\n", p->contato.nome, p->contato.fone);
	}
	printf("-----------------\n\n");
}

void combSort_lista(ListaContato* head, int tam){
	int gap = tam,
		swap = FALSE,
		n;
	
	ListaContato *i = init(),
				 *j = init();

	TpContato aux;

	while(gap > 1 || swap == TRUE){
		gap = (int) gap / 1.3;
		if (gap < 1) gap = 1;
		swap = FALSE;
		
		i = head;
		j = i;

		for (n=0;n<gap;n++){
			j=j->next;
		}

		for(; j!=NULL; i=i->next, j=j->next){
			if (strcmp(i->contato.nome,j->contato.nome) > 0){
				aux  = i->contato;
				i->contato = j->contato;
				j->contato = aux;
				swap = TRUE;
			}
		}
	}
}


ListaContato *listacpy(ListaContato *src){
	ListaContato *dest = init();
	char nome[40],fone[30];

	while(src != NULL){
		strcpy(nome, src->contato.nome);
		strcpy(fone, src->contato.fone);
		dest = push(dest, nome, fone);
		src = src->next;

	}

	return dest;
}

ListaContato *backToStart(ListaContato *head){

	while(head->prev != NULL)
		head = head->prev;

	return head;
}


ListaContato *runTo(ListaContato *head, int find){
	int i=0;

	while(i < find){
		head = head->next;
		i++;
	}

	return head;
}

ListaContato *mergeSortList(ListaContato *head, int begin, int end, ListaContato *aux){
	
	if(begin < end){
		int mid = (begin + end) / 2;
		
		aux = mergeSortList(head,begin,mid,aux);
		aux = mergeSortList(head,mid + 1,end,aux);
		aux = mergeList(head,begin,mid,end,aux);

	}

	return aux;
}


ListaContato *mergeList(ListaContato *head, int begin, int mid, int end, ListaContato *aux){

	int i=begin, j=mid+1, m=mid, n=end, k=0;
	ListaContato *li = init(),
				 *lj = init(),
				 *h = aux;				 
	char nome[40],fone[30];

	while(i <= m && j <= n){
		li = runTo(head,i);
		lj = runTo(head,j);

		if(strcmp(li->contato.nome, lj->contato.nome)  <= 0 ){
			strcpy(nome, li->contato.nome);
			strcpy(fone, li->contato.fone);
			if(aux == NULL){
				aux = push(aux, nome, fone);
				h = aux;
			}
			else{
				h = runTo(aux, k);
				if(h == NULL){
					h = runTo(aux, k-1);
					h->next = anotherPush(nome, fone);
					h->next->prev = h;
					h = h->next;
				}
				else{
					strcpy(h->contato.nome, nome);
					strcpy(h->contato.fone, fone);
				}
			}
			i++;
			k++;
		}
		else{
			strcpy(nome, lj->contato.nome);
			strcpy(fone, lj->contato.fone);
			if(aux == NULL){
				aux = push(aux, nome, fone);
				h = aux;
			}
			else{
				h = runTo(aux, k);
				if(h == NULL){
					h = runTo(aux, k-1);
					h->next = anotherPush(nome, fone);
					h->next->prev = h;
					h = h->next;
				}
				else{
					strcpy(h->contato.nome, nome);
					strcpy(h->contato.fone, fone);
				}
			}			
			j++;
			k++;
		}

	}

	li = runTo(head, i);
	while(i <= m){
		strcpy(nome, li->contato.nome);
		strcpy(fone, li->contato.fone);
		if(aux == NULL){
			aux = push(aux, nome, fone);
			h = aux;
		}
		else{
			h = runTo(aux, k);
			if(h == NULL){
				h = runTo(aux, k-1);
				h->next = anotherPush(nome, fone);
				h->next->prev = h;
				h = h->next;
			}
			else{
				strcpy(h->contato.nome, nome);
				strcpy(h->contato.fone, fone);
			}
		}
		i++;
		k++;
		li = li->next;
	}

	lj = runTo(head, j);
	while(j <= n){
		strcpy(nome, lj->contato.nome);
		strcpy(fone, lj->contato.fone);
		if(aux == NULL){
			aux = push(aux, nome, fone);
			h = aux;
		}
		else{
			h = runTo(aux, k);
			if(h == NULL){
				h = runTo(aux, k-1);
				h->next = anotherPush(nome, fone);
				h->next->prev = h;
				h = h->next;
			}
			else{
				strcpy(h->contato.nome, nome);
				strcpy(h->contato.fone, fone);
			}
		}
		j++;
		k++;
		lj = lj->next;
	}

	head = runTo(head, begin);

	for(i = 0; i < k; i++){

		strcpy(head->contato.nome, aux->contato.nome);
		strcpy(head->contato.fone, aux->contato.fone);

		if(aux->next != NULL)
			aux = aux->next;
		head = head->next;
	}

	return backToStart(aux);
}




ListaContato *ourFree(ListaContato *lista){

	ListaContato *aux;	

	while(lista != NULL){
		aux = lista->next;
		free(lista);
		lista = aux;
	}
	
	return NULL;
}






