#include <stdio.h>

void inverte(int vetor[], int tamanho);
void inverteelegante(int vetor[], int tamanho);
void imprime(int vetor[]);
void mudax(int x[]);

int main()
{
	int vetor[5], n = 0;

	printf("Digite cinco valores para o vetor a ser invertido: \n");
	while (n < 5){
		scanf("%d", &vetor[n++]);
	}

	imprime(vetor);
	inverteelegante(vetor, 5); printf("\n\n");
	imprime(vetor);

	/*int x[2]= {10, 20};
	printf("x[0] = %d  x[1] = %d", x[0], x[1]);
	mudax(x);
	printf("x[0] = %d  x[1] = %d", x[0], x[1]);*/
	

	return 0;
}

void mudax(int x[]){
	x[0] = 30;
	x[1] = 40;
}

void inverte(int vetor[], int tamanho){
	int pilha[10], t = 0, n = tamanho;

	while (n > 0){
		pilha[t++] = vetor[t - 1];
		n--;
	}

	n = 0;

	while (n < tamanho){
		vetor[n++] = pilha[--t];
	}
}

void inverteelegante(int vetor[], int tamanho){
	int pilha[10], t = 0;
	while(tamanho) pilha[t++] = vetor[--tamanho];
	while(t--) vetor[t] = pilha[t]; 
}

void imprime(int vetor[]){
	for (int i = 0; i < 5; ++i)
	{
		printf(" v[%d] = %d ", i, vetor[i]);
	}
}