#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

int *create(){
	int *v = NULL, i;
	v = (int *)malloc(sizeof(int)*MAX);

	for (i=0;i<MAX;i++){
		v[i] = rand()%100 ;
	}
	return v;
}

int *init(){
	return NULL;
}

int *copyVector(int v[]){
	int *v2 = init(),
		i;

	v2 = (int *)malloc(sizeof(int)*MAX);

	for (i=0;i<MAX;i++){
		v2[i] = v[i];
	}

	return v2;
}

void printV(int v[]){
	int i;
	for (i=0;i<MAX;i++){
		printf("\t%d", v[i]);
	}
	printf("\n");
}

void combSort(int v[]){
	int gap = MAX,
		swap = 0,
		i, aux;

	while (gap > 1 || swap == 1){
		gap = gap / 1.3;
		if (gap < 1) gap = 1;
		swap = 0;
		for (i=0; (i+gap)<MAX;i++){
			if (v[i]>v[(i+gap)]){
				aux = v[i];
				v[i] = v[(i+gap)];
				v[(i+gap)] = aux;
				swap = 1;
			}
		}
	}
}

void bad_combSort(int v[]){
	int gap = MAX,
		swap = 0,
		i, aux;

	while (gap > 1 || swap == 1){
		gap = gap / 1.5;
		if (gap < 1) gap = 1;
		swap = 0;
		for (i=0; (i+gap)<MAX;i++){
			if (v[i]>v[(i+gap)]){
				aux = v[i];
				v[i] = v[(i+gap)];
				v[(i+gap)] = aux;
				swap = 1;
			}
		}
	}
}

void bubbleSort(int v[]){
	int swap = 1,
		i, aux;

	while (swap == 1){
		swap = 0;
		for (i=0; (i+1)<MAX;i++){
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
		*aux = init();

	v = create();

	clock_t cini, cfim;

	system("clear");

	printf("Vetor:\n");
	printV(v);

	printf("\nBubble Sort:\n");
	aux = copyVector(v);
	cini = clock();
	bubbleSort(aux);
	cfim = clock();
	printV(aux);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);


	printf("Comb Sort (FE = 1.5):\n");
	aux = copyVector(v);
	cini = clock();
	bad_combSort(aux);
	cfim = clock();
	printV(aux);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);

	printf("Comb Sort:\n");
	aux = copyVector(v);
	cini = clock();
	combSort(aux);
	cfim = clock();
	printV(aux);
	printf("Tempo: %f segundos.\n\n", (float)(cfim-cini)/CLOCKS_PER_SEC);


	if (v != NULL) free(v);
	if (aux != NULL) free(aux);
	return 0;
}