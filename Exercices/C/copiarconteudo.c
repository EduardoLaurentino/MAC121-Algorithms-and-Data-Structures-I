#include <stdio.h>
#define MAX 1000

void CopiarConteudo(FILE *file1, FILE *file2);

int main(){
	FILE *arquivo1 = fopen("Arquivo 1.txt", "r");

	if (arquivo1 == NULL){
		printf("Não foi possível abrir o arquivo.\n");
		return 1;
	}

	char nome[] = "Arquivo 2.txt";


	FILE *arquivo2 = fopen(nome, "w");

	CopiarConteudo(arquivo1, arquivo2);
	fclose(arquivo1);

	/*--------------------------------------------------*/
	char frase[100];
	fgets(frase, 100, stdin);
	printf("%s\n", frase);
	FILE *arquivo3 = fopen("texto.txt", "r");
	freopen("Arquivo 1.txt", "r", arquivo3);
	fgets(frase, 100, arquivo1);
	printf("%s\n", frase);

	return 0;

}

void CopiarConteudo(FILE *file1, FILE *file2){
	char conteudo[MAX];
	while (fgets(conteudo, MAX, file1) != NULL){
		fputs(conteudo, file2);
	};

}