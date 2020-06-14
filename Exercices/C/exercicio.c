#include <stdio.h>
#include <string.h>
#define max 100

void imprime(char vetor[], int tamanho);
void inverteelegante(char frase[], int tamanho);
void inverte(char vetor[], int tamanho);

int main(){
	char frase2[max];
	char frase[max];

	printf("Digite a frase: \n"); scanf("%[^\n]", frase2);
	imprime(frase2, strlen(frase2));
	
	printf("Digite a palavra: \n"); scanf("%s", frase);
	int tamanho = strlen(frase);
	imprime(frase, tamanho); printf("\n\n");

	printf("===== inversões =====\n");

	inverteelegante(frase, tamanho);
	inverteelegante(frase2, strlen(frase2));

	imprime(frase, tamanho);
	imprime(frase2, strlen(frase2));

	return 0;
}

void inverteelegante(char frase[], int tamanho){
	int pilha[200], t = 0;
	while (tamanho) pilha[t++] = frase[--tamanho]; 
	while (t--) frase[t] = pilha[t];
}

void inverte(char vetor[], int tamanho){
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

void imprime(char vetor[], int tamanho){
	for (int i = 0; i < tamanho; ++i)
	{
		printf("%c", vetor[i]);
	}
	printf("\n\n");
}