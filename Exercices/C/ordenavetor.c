#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3
#define MAX2 10

typedef struct celula_st{
	int valor;
	int valor2;
	struct celula_st *prox;
} celula; 

celula *VetorParaLista(int v[], int t);
void OrdenaPorInsercaoLista(celula *cabeca);
void ImprimeListaComCabeca(celula *cabeca);

void OrdenaStringPorInsercao(char vetor[], int n);
int Anagrama(char *s, char *t);

int NumAlgSig(int x);

void ordenavetor(int vetor[], int t);
void OrdenaPorSelecao(int vetor[], int n);
void OrdenaPorInsercao(int vetor[], int n);
void ImprimeVetor(int vetor[], int n);

int main(){
	int vetor[MAX], num;
	char string1[MAX2], string2[MAX2];
	printf("Digite a primeira palavra: "); scanf("%s", string1);
	printf("Digite a segunda palavra : "); scanf("%s", string2);
	printf("\nPalavra 1 = %s  -- Palavra2 = %s", string1, string2);
	OrdenaStringPorInsercao(string1, strlen(string1));
	OrdenaStringPorInsercao(string2, strlen(string2));
	printf("\nPalavra 1 = %s  -- Palavra2 = %s", string1, string2);
	if (Anagrama(string1, string2)) printf("\nSão anagramas!\n");
	else printf("Não são anagramas.\n");

	printf("\n\n");

	printf("Digite um numero inteiro: "); scanf("%d", &num);
	printf("Esse número tem %d algarismos significativos.\n", NumAlgSig(num));
	/*for (int i = 0; i < MAX; ++i) 
	{
		printf("Digite o %dº elemento do vetor: ", i+1);
		scanf("%d", &vetor[i]);
	}
	celula *lista = VetorParaLista(vetor, MAX);
	ImprimeListaComCabeca(lista);
	OrdenaPorInsercaoLista(lista);
	printf("\n\n");
	ImprimeListaComCabeca(lista);
	printf("\n\n");
	celula *q;
	for(q = lista->prox; q->prox != NULL; q = (q->prox)) printf("[%d] ", q->valor2);
	printf("\n\n\n\n");
	ImprimeVetor(vetor, MAX);
	OrdenaPorInsercao(vetor, MAX);
	printf("\n");
	ImprimeVetor(vetor, MAX);*/

	return 0;
}

void ordenavetor(int vetor[], int t){
	int aux, aux2, i = 0;
	
	while(i < t ){
		if (vetor[i] > vetor[i+1] && (i+1) < t){
			aux2 = i;
			for (int j = aux2+1; j < t; ++j){
				if(vetor[aux2] > vetor[j]){
					aux = vetor[aux2];
					vetor[aux2] = vetor[j];
					vetor[j] = aux;
					aux2++;
				}
			}
			i = 0;
		} else i++;
	}
}

void OrdenaPorSelecao(int vetor[], int n){
	int menor, lugar;
	for (int i = 0; i < n; ++i)
	{
		menor = vetor[i];
		for (int j = i+1; j < n; ++j)
		{
			if (vetor[j] < menor){
				menor = vetor[j];
				lugar = j;
			}	
		}
		vetor[lugar] = vetor[i];
		vetor[i] = menor;
	}
}

void OrdenaPorInsercao(int vetor[], int n){
	int maior;
	for (int i = 1; i < n; ++i)
	{
		maior = vetor[i];
		for (int j = 0; j < i; ++j)
		{
			if(vetor[j] > maior){
				vetor[i] = vetor[j];
				vetor[j] = maior;
				maior = vetor[i];
			}
		}
	}
}

void OrdenaStringPorInsercao(char vetor[], int n){
	char maior;
	for (int i = 1; i < n; ++i)
	{
		maior = vetor[i];
		for (int j = 0; j < i; ++j)
		{
			if(vetor[j] > maior){
				vetor[i] = vetor[j];
				vetor[j] = maior;
				maior = vetor[i];
			}
		}
	}
}

void OrdenaPorInsercaoLista(celula *cabeca){
	int maior;
	celula *q = malloc(sizeof(celula));
	celula *p = malloc(sizeof(celula));
	for (q = cabeca->prox->prox; q->prox != NULL; q =  q->prox)
	{ 
		maior = q->valor;
		for (p = cabeca->prox; p->prox != NULL; p = p->prox)
		{
			if(p->valor > maior){
				q->valor = p->valor;
				p->valor = maior;
				maior = q->valor;
			}
		}
		
	}

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
		n->valor2 = v[i]*2;
		n->prox = ant->prox;
		if(cabeca->prox == NULL) cabeca->prox = n;
		else ant->prox = n;
		ant = n;
	}
	free(ant);

	return cabeca;
}

void ImprimeListaComCabeca(celula *cabeca){
	celula *q;
	for(q = cabeca->prox; q->prox != NULL; q = (q->prox)) printf("[%d] ", q->valor);
}

void ImprimeVetor(int vetor[], int n){
	for (int j = 0; j < n; ++j) printf("v[%d] = %d ", j, vetor[j]);
}

int Anagrama(char *s, char *t){
	int n = strlen(s), m = strlen(t);
	if (n != m) return 0;
	OrdenaStringPorInsercao(s, n);
	OrdenaStringPorInsercao(t, m);
	for (int i = 0; i < n; ++i) if(s[i] != t[i]) return 0;

	return 1;
}

int NumAlgSig(int x){
	int i;
	for (i = 0; x > 0; i++)
		x = (x/10);
	return i;
}