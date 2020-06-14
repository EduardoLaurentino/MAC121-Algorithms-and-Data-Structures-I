#include <stdio.h>
#define N 10

int main(){
	int agulha1[N], agulha2[N], agulha3[N];
	int t1 = 0, t2 = 0, t3 =0;

	/*empilha discos na agulha1*/
	for (int i = N; i > 0; i--) agulha1[t1++] = i;

	/*desempilha da agulha1 e empilha na agulha3 */
	x = agulha1[--t1]; agulha3[t3++] = x;

	/*desempilha da agulha1 e empilha na agulha2 */
	x = agulha1[--t1]; agulha2[t2++] = x;
}