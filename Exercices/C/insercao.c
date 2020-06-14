#include <stdio.h>

int insere(int v[], int n, int k, int x);
int insere_melhor(int v[], int n, int k, int x);

int main(){
	int w[20] = {5, 10, 15, 20, 25, 36, 2, 6, 3, 8}, pos, num;

	printf("Digite o numero a ser inserido: "); scanf("%d", &num);
	printf("Digite a posição do vetor em que o numero será inserido: \n"); scanf("%d", &pos);

	int novo_tamanho = insere(w, 10, pos, num);

	for (int i = 0; i < novo_tamanho; i++){
		printf("w[%d] = %d ", i, w[i]);
	}

	return 0;

}

int insere(int v[], int n, int k, int x){
	int vetor_novo[20];
	int i = k + 1, j = 0;

	while (i < n){
		vetor_novo[j] = v[i];
		i++; j++;
	}

	v[k] = x;

	int a = k+2;
	i = 0;

	while (i < j){
		v[a] = vetor_novo[i];
		a++; i++; 
	}

	return n+1;

}

int insere_melhor(int v[], int n, int k, int x){
	int j;

	for (j = n; j > k; j--){
		v[j] = v[j - 1];
	}

	v[k] = x;

	return n + 1;
}