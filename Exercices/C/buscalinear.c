#include <stdio.h>
#define MAX 16

int busca(int a[], int x, int n);

int main(){
	int v[MAX], w[] = {5, 10, 15, 20, 25, 36, 2, 6, 3, 8}, x, lugar;

	for (int i = 0; i < MAX; i++){
		v[i] = i*3.149;
		i++;
	}

	printf("Digite um número a ser pesquisado dentro do vetor: ");
	scanf("%d", &x);

	lugar = busca(w, x, 10);

	if (lugar == 11) printf("O número não existe dentro do vetor.\n");
	else printf("O numero %d está na posição %d do vetor!\n", x, lugar);

	return 0;


}

int busca(int a[], int x, int n){
	int i = 0;

	a[n] = x;

	while (a[i] != x){
		i++;
	}

	return i+1;

}