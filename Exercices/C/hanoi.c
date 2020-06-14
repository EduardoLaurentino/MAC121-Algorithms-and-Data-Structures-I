#include <stdio.h>

void Hanoi (int n, char origem, char dest, char aux){
	if (n == 0) return;

	Hanoi(n-1, origem, aux, dest);
	printf("Mova disco %d de %c para %c\n", n, origem, dest);
	Hanoi(n-1, aux, dest, origem);
}

int main(){
	Hanoi(4, 'A', 'B', 'C');

	return 0;
}