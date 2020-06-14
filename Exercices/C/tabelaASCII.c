#include <stdio.h>

int main(){
	char i;
	for (i = 32; i < 127; i++){
		printf("%4d: %c  ", i, i);
		if ((i + 1)%8 == 0) printf("\n");
	}
	printf("\n");

	for (i = 'a'; i < 'z'; i++){
		printf("%3d: %c    ", i, i );
	}


	printf("\n");
	return 0;
}