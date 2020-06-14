#include <stdio.h>

int main(void){
	int k, y, x, soma=0;
	int a, b;

	FILE *entrada = fopen ("exemplo1.txt", "r");
	if (entrada == NULL){
		printf("Erro ao abrir o arquivo 'exemplo1.txt'.\n");
		return 1;
	}

	printf("Digite dois numeros para serem somados: \n");
	scanf("%d %d", &a, &b);

	while (1){
		k = fscanf(entrada, "%d", &x);
		if (k != 1) break;
		soma += x;
	}

	printf("soma antes de escrever: %d\n", soma);
	fclose (entrada);

	FILE *saida = fopen ("exemplo1.txt", "w");

	fprintf(saida, "%d %d", a, b);

	x = 0;

	while (1){
		y = fscanf(saida, "%d", &x);
		if (y != 1) break;
		soma += x;
	}

	printf("soma depois de escrever: %d\n", soma);

	fclose (saida);

	return 0;

}