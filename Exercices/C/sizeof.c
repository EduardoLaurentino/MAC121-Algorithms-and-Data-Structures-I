#include <stdio.h>
#define MAX 100
#define cinco 5

///void capacidade(int u[]);

int main(){
	int amor[MAX]; 

	static int v[cinco];
	int w[] = {1, 2, 3};

	printf("%lu\n", sizeof(v)/sizeof(v[0]) );
	printf("%lu\n", sizeof(w)/sizeof(w[0]) );
	printf("%lu\n", sizeof(amor)/sizeof(amor[0]) );

	return 0;

}

