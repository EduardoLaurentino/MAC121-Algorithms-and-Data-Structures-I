#include <stdio.h>
#define MAX 10

int insere_no_fim(int vetor[], int tamanho, int valor);
int insere(int vetor[], int tamanho, int valor, int posicao);
void imprime(int vetor[], int tamanho);
int remove_do_fim(int vetor[], int tamanho);
int remover(int vetor[], int tamanho, int posicao);

int main(){
	int amor[MAX] = {1, 3, 5, 7, 9};
	imprime(amor, MAX);

	imprime(amor, insere_no_fim(amor, 5, 11));

	imprime(amor, remove_do_fim(amor, 6));

	imprime(amor, insere(amor, 5, 7777, 3));

	imprime(amor, remover(amor, 6, 3));

	return 0;
}

int insere_no_fim(int vetor[], int tamanho, int valor){
	vetor[tamanho++] = valor;
	return tamanho;
}

int insere(int vetor[], int tamanho, int valor, int posicao){
	for (int i = tamanho; i > posicao; i--)
	{
		vetor[i] = vetor [i-1];
	}
	vetor[posicao] = valor;

	return ++tamanho;
}

int remove_do_fim(int vetor[], int tamanho){
	return --tamanho;
}

int remover(int vetor[], int tamanho, int posicao){
	for (int i = posicao; i < tamanho; ++i)
	{
		vetor[i] = vetor[i+1];
	}

	return --tamanho;
}

void imprime(int vetor[], int tamanho){
	for (int i = 0; i < tamanho; ++i)
	{
		printf("v[%d] = %d ", i, vetor[i]);
	}
	printf("\n...\n");
}