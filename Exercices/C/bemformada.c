#include <stdio.h>
#define max 100

int bemformada(char *expressao);

int main(){
	char expressao[max];	

	printf("Entre com sua expressão: \n"); scanf("%s", expressao);
	printf("%s\n\n", expressao);

	if (bemformada(expressao) == 1) printf("A expressão é bem formada!\n");
	else printf("A expressão não é bem formada.\n");

	return 0;
}

int bemformada(char *expressao){
	char pilha[max];
	int t = 0;

	for (int i = 0; expressao[i] != '\0'; i++)
	{
		if (expressao[i] == '(' || expressao[i] == '{')
		{
			pilha[t++] = expressao[i];
		}
		if (expressao[i] == ')')
		{
			if (t > 0 && pilha[t - 1] == '(') t--;
			else return 0;
		}
		if (expressao[i] == '}')
		{
			if (t > 0 && pilha[t - 1] == '{') t--;
			else return 0;
		}
	}
 
	return t == 0;
}