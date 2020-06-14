#include <stdio.h>
#define CAP 10

void imprime(int vetor[]);
void inverte_fila(int fila[], int *s, int *t);

int main(){
	int fila[CAP], s, t;
	for (int i = 0; i < CAP; ++i) fila[i] = i;
	imprime(fila);

	inverte_fila(fila, s, t);
	imprime(fila);

	return 0;

}


/* Inverte a ordem dos elementos da fila f[s...t-1] usando uma pilha */
void inverte_fila(int fila[], int *s, int *t){
	int pilha[CAP], p = 0;

	while (*s < *t){
		pilha[p++] = fila[(*s)++];	
	} 																																																														s != *t) pilha[p++] = fila[*s++];
	while (p > 0){
		fila[(*t)++] = pilha[--p];
	}
}																																																																																																																																																																																																																																																																																																																																																																																																																																																			

void imprime(int vetor[]){
	for (int i = 0; i < 5; ++i)
	{
		printf(" v[%d] = %d ", i, vetor[i]);
	}
}
