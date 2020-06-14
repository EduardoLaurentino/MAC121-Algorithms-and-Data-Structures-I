#include <stdio.h>
#include "funcoesdoteste.h"

int main(int argc, char **argv){
	int a = 2, b, n;
	int *p, *q, *r;

	printf("Digite um número: ");
	scanf("%d", &n);
	printf("\nO fatorial desse número é %.1f\n", fatorial(n));

	p = &a;
	q = p;
	r = &b;
	*r = *q;
	*q += 2;

	printf("%d %d\n\n", a, b);


	/*for (int i = 2; i < 5; i++){
		printf("O fatorial de %d é: %.1f\n", i, fatorial(i));
	}

	for (int j = 0; j < argc; j++){
		printf("%s\n", argv[j]);
	}*/

	return 0;

}

