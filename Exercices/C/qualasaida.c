	#include <stdio.h>
	#define N 10
	

	int main(void){
		int *p, i = 0, v[N];
		for (int i = 0; i < N; i++){
			v[i] = i;
		}
		p = &(v[N-1]);
		while (*p){
			--p; i++;
		}

		printf("%d %d\n", *p, i);

		return 0;
	}