#include <stdio.h>
#define MAX 100

void nada(int vetor[]);

int main(){
	int familia[MAX];

	nada(familia);
	

	return 0;


}

void nada(int vetor[]){
	float amor[MAX];
	int amizade[] = {2, 3, 4, 5, 6, 7};

	printf("%lu\n", sizeof(amor)/sizeof(amor[0]));
	printf("%lu\n", sizeof(amor[3]));
	printf("%lu\n", sizeof(amizade)/sizeof(amizade[0]));
	printf("%lu\n", sizeof(vetor)/sizeof(vetor[0]));
}