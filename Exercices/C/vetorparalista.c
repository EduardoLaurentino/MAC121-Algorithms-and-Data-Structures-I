#include <stdio.h>
#include <stdlib.h>

typedef struct celula_st{
	int valor;
	struct celula_st *prox;
} celula; 

celula *VetorParaLista(int v[], int t);
void ImprimeListaComCabeca(celula *cabeca);


int main(){
	int v[10];
	for (int i = 0; i < 10; ++i) v[i] = i;
	for (int j = 0; j < 10; ++j) printf("v[%d] = %d\n", j, v[j]);
	
	celula *cabeca = VetorParaLista(v, 10);	
	ImprimeListaComCabeca(cabeca);

	return 0;
}

celula *VetorParaLista(int v[], int t){
	int i;
	celula *ant = malloc(sizeof(celula));
	celula *cabeca = malloc(sizeof(celula)); 
	cabeca->prox = NULL;
	ant = cabeca;
	for (i = 0; i <= t; ++i)
	{
		celula *n = malloc(sizeof(celula));
		n->valor = v[i];
		n->prox = ant->prox;
		if(cabeca->prox == NULL) cabeca->prox = n;
		else ant->prox = n;
		ant = n;
	}
	free(ant);

	return cabeca;
}

void ImprimeListaComCabeca(celula *cabeca){
	celula *q = malloc(sizeof(celula));
	for(q = cabeca->prox; q->prox != NULL; q = (q->prox)) printf("[%d] ", q->valor);
}