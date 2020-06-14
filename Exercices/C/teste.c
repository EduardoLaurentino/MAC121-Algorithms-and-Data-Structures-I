#include <stdio.h>

void imprime(int vetor[], int tamanho);

int main(){
	int vetor[11];
	int v = 0, x;

	for(int i = 0; i < 10; i++) vetor[v++] = i;
	imprime(vetor, 10);

	vetor[v++] = 10;
	imprime(vetor, 11);
	printf("\nv = %d\n", v);

	x = vetor[--v];
	printf("x = %d e v = %d\n", x, v);
	imprime(vetor, 10);
}

void imprime(int vetor[], int tamanho){
	for (int i = 0; i < tamanho; ++i)
	{
		printf("v[%d] = %d ", i, vetor[i]);
	}
	printf("\n...\n");
}