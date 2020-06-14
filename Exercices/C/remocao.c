#include <stdio.h>

int remover(int v[], int n, int k);

int main(){
	int w[20] = {5, 10, 15, 20, 25, 36, 2, 6, 3, 8}, pos;

	printf("Digite a posição do numero a ser removido do vetor: "); scanf("%d", &pos);

	int tamanho = remover(w, 10, pos);

	for (int i = 0; i < tamanho; ++i)
	{
		printf("w[%d] = %d  ", i, w[i]);
	}

	return 0;

}

int remover(int v[], int n, int k){
	int j;

	for (j = k; j < n; j++){
		v[j] = v[j+1];
	}

	return n - 1;
}