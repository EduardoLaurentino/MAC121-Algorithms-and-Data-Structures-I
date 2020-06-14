#include <stdio.h>

double fatorial(double n){
	static int a = 0; double x; a++;
	printf("%d.", a); printf("%*s", a, "");
	printf("fat(%.f)\n", n);
	if(n < 2) { x = 1;}
	else x = n * fatorial(n - 1);
	printf("%d.", a); printf("%*s", a, "");
	printf("%.f\n", x);
	a--;
	return x;
}

double fat(double n){
	if (n < 2) return 1;
	return n * fat(n - 1);
}

int fibonnaci(int n){
	static int a = 0; int x; 
	a++;
	printf("%d.", a); printf("%*s", a, "");
	printf("fib(%d)\n", n);
	if (n <= 2) {x = 1;}
	else { x = fibonnaci(n - 1) + fibonnaci(n - 2);}
	printf("%d.", a); printf("%*s", a, "");
	printf("%d\n", x);
	a--;
	return x;
}

int main(){
	int num;
	printf("Digite um número para calcular o fatoria: "); scanf("%d", &num);
	printf("\n");
	fibonnaci(num);

	return 0;
}