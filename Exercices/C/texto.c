#include <stdio.h>

int main(){
	int num1, num2, num3, num4;
	char frase[100];
	FILE *arquivo1 = fopen("textosskkk.txt", "a");
	FILE *arquivo2 = fopen("numeros.txt", "r");
	if (arquivo2 == NULL) {
		printf("Arquivo não pôde ser aberto.\n");
		return 0;
	}

	if (arquivo1 == NULL){
		printf("Arquivo não pôde ser aberto.\n");
		return 0;
	}

	fprintf(arquivo1, "\nprimeira linha\n");
	char dica[] = "não dorme, estuda!!";
	char hm = '!';

	fputs(dica, arquivo1);
	fputc(hm, arquivo1);


	fscanf(arquivo2, "%i %i %i %i", &num1, &num2, &num3, &num4);
	printf("%i %i %i %i\n", num1, num2, num3, num4);

	/*while (fgets(frase, 100, arquivo1) != NULL){
		printf("%s\n", frase);
	}*/

	fclose(arquivo1);
	fclose(arquivo2);


	return 0;
}