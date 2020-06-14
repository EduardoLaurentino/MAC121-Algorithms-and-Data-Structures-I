#include <stdio.h>
#define MAX_N 1000

int remove_zeros(int v[], int n);

int main()
{
	int w[MAX_N] = {3, 4, 0, 0, 5, 0, 0, 0, 0, 0, 6};

	int tamanho = remove_zeros(w, 11);

	for (int i = 0; i < tamanho; ++i)
	{
		printf("w[%d] = %d  ", i, w[i]);
	}

	return 0;

}

int remove_zeros(int v[], int n){
	int i;

	for (i = 0; i < n; ++i){
		if (v[i] == 0)
		{ 
			for (int j = i; j < n; j++)
			{
				v[j] = v[j+1];
			}
			n--;
			--i;			
		}
	}

	return n;
}