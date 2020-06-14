#include <stdio.h>

#define MAX_N 1000

/* Recebe um vetor de tamanho n e remove os
 * zeros mantendo a ordem relativa dos demais
 * elementos. A função retorna o novo tamanho.
 */
 int remove_zeros(int v[], int n);


/* Preenche v com os numeros primos entre 2 e m
 * e retorna o tamanho de v. Chama a funcao remove_zeros
 */
int primos(int m, int v[]);


/* Preenche v com os numeros primos entre 2 e m
 * e retorna o tamanho de v. Remove numeros marcados 
 * imediatemente. 
 */
int primos2(int m, int v[]);


int main(void) {
   int N = 0, n, i;
   int v[MAX_N];

  scanf("%d", &N);
  if (N < 2 || N > 1000) {
      printf("N precisa ser um inteiro entre 2 e %d.\n", MAX_N);
      return 1;
  }

  n = primos(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (i = 0; i < n; i++) printf(" %d", v[i]);
  printf("\n");

  n = primos2(N, v);
  printf("%d primos entre 2 e %d:\n", n, N);
  for (i = 0; i < n; i++) printf(" %d", v[i]);
  printf("\n");

  return 0;
}

int remove_zeros(int v[], int n) {
	int i;
    for (i = 0; i < n; ++i)
    {
    	if (v[i] == 0){
    		for (int j = i; j < n; j++)
    		{
    			v[j] = v[j+1];
    		}
    		n--;
    		i--;
    	}
    }

    return n;
}

int primos(int m, int v[]) {
    /* implementar crivo de eratostenes 
       marcar numeros com zero e chamar
       funcao remove_zeros no final
    */

    for (int k = 0; k < m-1; ++k)
    {
    	v[k] = k+2;
    }

    if (m > 2){
    	for (int i = 0; i < m; ++i)
    	{
    		if (v[i] != 0)
    		{
	    		for (int j = i + 1; j < m; ++j)
	    		{
	    			if (v[j] != 0){
	    				if (v[j]%v[i] == 0) v[j] = 0;
		    		} 
	    		}
	    	}
    	}
    }
     
    return remove_zeros(v, m);
}

int primos2(int m, int v[]) {
    /* implementar sem chamar funcao remove_zeros 
        numeros marcados devem ser imediatamente
        removidos
    */    

    for (int k = 0; k < m-1; ++k)
    {
    	v[k] = k+2;
    }

    if (m > 2){
    	for (int i = 0; i < m; ++i)
    	{
    		if (v[i] != 0)
    		{
	    		for (int j = i + 1; j < m; ++j)
	    		{
	    			if (v[j] != 0){
	    				if (v[j]%v[i] == 0){
	    					for (int a = j; a < m; a++)
					    		{
					    			v[a] = v[a+1];
					    		}
					    	--m;
					    	--j;
	    				}
		    		} 
	    		}
	    	}
    	}
    }

    return m-1;

}