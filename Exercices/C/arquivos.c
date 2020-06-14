#include <stdio.h>

int main(){
	
	FILE *entrada = fopen("exemplo1.txt", "r");
	int k, soma = 0;
	char x;

	if (entrada == NULL){
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	while (1){
		k = fscanf (entrada, "%c", &x);
		printf("%d", k);
		if (k != 1) break;
		soma += x;
	} 	

	printf("soma: %d\n", soma);
	fclose(entrada);

	return 0;

}