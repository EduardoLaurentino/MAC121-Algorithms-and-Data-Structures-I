#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	char *vogais = "aeiou";
	int i, j;
	char frase[MAX];

	printf("Por favor, digite algo:\n");
	scanf("%s", frase);

	for (i = 0; frase[i] != '\0'; i++){
		for (j = 0; vogais[j] != '\0'; j++){
			if (frase[i] == vogais[j]){
				printf("%c\n", frase[i]);
			}
		}
	}

	return 0;
}