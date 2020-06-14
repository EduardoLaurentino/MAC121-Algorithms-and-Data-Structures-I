#include <stdio.h>
#define MAX_N 1000


int remove_zeros(int v[], int n);
int primos(int m, int v[]);

int main()
{
	int w[MAX_N];

	int tamanho = primos(10, w);

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
		}
	}

	return i;
}

/*Preenche v com números primos entre 2 e m
e retorna o tamanho de v. Chama a função remove_zeros*/

int primos(int m, int v[]){

	int tamanho_v_sem_zeros = remove_zeros(v, m-1);

	int min = 0;
	while (min != tamanho_v_sem_zeros){
		for (int i = 0; i < tamanho_v_sem_zeros; ++i)
		{

			if (v[i]%v[min] == 0)
			{
				for (int j = 0; j < tamanho_v_sem_zeros; j++)
				{
					v[j] = v[j+1];
				}
				tamanho_v_sem_zeros--;
			}
		}
		min++;
	}

	return min;
}