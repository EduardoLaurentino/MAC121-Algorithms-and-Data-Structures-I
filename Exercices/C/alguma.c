#include <stdio.h>
#include <stdlib.h>

int main(){
	int n; char *s;
	printf("Digite a quantidade de caracteres da string: "); scanf("%d", &n);
	s = (char *) malloc(n+1);
	puts("mortadela");

	fgets(s, n, stdin);
	printf("Aqui está: \n\n");
	printf("%s", s);
	free(s);

	return 0;
}