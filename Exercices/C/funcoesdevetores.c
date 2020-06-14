#include <stdio.h>
#define MAX 100

int maximo(int v[], int n);
int maximo2(int *v, int n);
int busca(int x, int vetor[], int tamanho);

int main(){
	int amor[MAX] = {2, 3, 5, 65, 43, 23, 555, 43, 2222, 7};

	printf("%d\n", maximo2(amor, 10));
	printf("43 = %d\n", amor[busca(43, amor, 10)]);

	return 0;
}

int maximo(int v[], int n){
	int maior = v[0];

	for (int i = 1; i < n; ++i)
	{
		if (v[i] > maior) maior = v[i];
	}

	return maior;
}

int maximo2(int *v, int n){
	int maior = *v;
	for (int i = 1; i < n; ++i)
	{
		if (*(v+i) > maior ) maior = *(v+i);
	}

	return maior;
}

int busca(int x, int vetor[], int tamanho){
	int i;
	for (i = 0; i < tamanho && vetor[i] != x; ++i);
	return i;
}