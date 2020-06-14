#include <stdio.h>

double fatorial (int n){
	double fat = n;


	if (n < 2){
		return 1;
	}
	else{
		while (n > 1){
			fat *= n-1;
			printf("fat prov: %f\n", fat);
			n--;
		}
	}

	return fat;
}