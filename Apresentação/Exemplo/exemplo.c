#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *init(){
	return NULL;
}

int *create(int tam){
	int *v = init(), i;
	v = (int *)malloc(sizeof(int)*tam);

	for (i=0;i<tam;i++){
		v[i] = rand()%100 ;
	}
	return v;
}

int *copyVector(int v[], int tam){
	int *v2 = init(),
		i;

	v2 = (int *)malloc(sizeof(int)*tam);

	for (i=0;i<tam;i++){
		v2[i] = v[i];
	}

	return v2;
}

void printV(int v[], int tam){
	int i;
	for (i=0;i<tam;i++){
		printf("\t%d", v[i]);
	}
	printf("\n");
}

void combSort(int v[], int tam){
	int gap = tam,
		swap = 0,
		i, aux;

	while (gap > 1 || swap == 1){
		gap = gap / 1.3;
		if (gap < 1) gap = 1;
		swap = 0;
		for (i=0; (i+gap)<tam;i++){
			if (v[i]>v[(i+gap)]){
				aux = v[i];
				v[i] = v[(i+gap)];
				v[(i+gap)] = aux;
				swap = 1;
			}
		}
	}
}

void bad_combSort(int v[], int tam){
	int gap = tam,
		swap = 0,
		i, aux;

	while (gap > 1 || swap == 1){
		gap = gap / 1.5;
		if (gap < 1) gap = 1;
		swap = 0;
		for (i=0; (i+gap)<tam;i++){
			if (v[i]>v[(i+gap)]){
				aux = v[i];
				v[i] = v[(i+gap)];
				v[(i+gap)] = aux;
				swap = 1;
			}
		}
	}
}

void bubbleSort(int v[], int tam){
	int swap = 1,
		i, aux;

	while (swap == 1){
		swap = 0;
		for (i=0; (i+1)<tam;i++){
			if (v[i]>v[(i+1)]){
				aux = v[i];
				v[i] = v[(i+1)];
				v[(i+1)] = aux;
				swap = 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int *v = init(),
		*aux = init(),
		tam;


	clock_t cini, cfim;

	printf("Tamanho do vetor: ");
	scanf(" %d", &tam);
	v = create(tam);
	system("clear");

	printf("Vetor:\n");
	printV(v,tam);

	printf("\nBubble Sort:\n");
	aux = copyVector(v, tam);
	cini = clock();
	bubbleSort(aux, tam);
	cfim = clock();
	printV(aux, tam);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);
	if (aux != NULL) free(aux);


	printf("Comb Sort (FE = 1.5):\n");
	aux = copyVector(v, tam);
	cini = clock();
	bad_combSort(aux, tam);
	cfim = clock();
	printV(aux,tam);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);
	if (aux != NULL) free(aux);


	printf("Comb Sort:\n");
	aux = copyVector(v,tam);
	cini = clock();
	combSort(aux,tam);
	cfim = clock();
	printV(aux,tam);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);


	if (v != NULL) free(v);
	if (aux != NULL) free(aux);
	return 0;
}