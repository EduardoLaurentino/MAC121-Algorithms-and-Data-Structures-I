#include <stdio.h>
#define MAX 100

int main(){
	int p[MAX];
}

/*======================================PILHA===========================================*/

/* I n i c i a l i z a uma p i l h a p [ 0 . . t −1] */
void cria_pilha(int p[], int *t){
	*t = 0;
}

/* Remove e r e t o r n a t op o de p i l h a p [ 0 . . t −1] */
int remove_da_pilha(int p[], int *t){
	if (*t > 0) return p[--(*t)];
}

/* I n s e r e x no t op o de p i l h a p [ 0 . . t −1] */
void insere_na_pilha(int x, int p[], int *t){
	if (*t < MAX) pilha[(*t)++] = x;
}

/* V e r i f i c a se p i l h a p [ 0 . . t −1] e s t a ’ v a z i a ; 1 se sim , 0 se nao */
int vazia(int p[], int t){
	if (t == 0) return 1;
	else return 0;

	/*return t == 0; */
}

/* V e r i f i c a se p i l h a p [ 0 . . t −1] e s t a ’ c h e i a ; 1 se sim , 0 se nao */
int cheia(int p[], int t){
	if (t == sizeof(p)/sizeof(p[0])) return 1;
	else return 0;

	/*return t == N;*/
}

/*======================================FILA CIRCULAR===========================================*/

int cheia(int f[], int s, int t){
	if (s == ((t)%N)) return 1; /*cheia*/
	else return 0;
}

int vazia(int f[], int s, int t){
	if (s == t) return 1; /*vazia*/
	else return 0;
}

void Remove(int f[], int *s, int *t){
	if (*s != *t){
		f[(*s)++];
		if (*s == MAX)
			*s = 0;
	}
}

void Insere(int x, int f[], int *s, int *t){
	if (*t != MAX){
		f[(*t)++] = x;
		if (*t == MAX)
			*t = 0;
	}
}