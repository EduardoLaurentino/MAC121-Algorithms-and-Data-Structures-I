#include <stdio.h>

int main(){
  char nome[100];

  printf("Digite o seu nome: \n");
  scanf("%s", nome);
  printf("\nOlá, %s\n", nome);


  int valor = 0; char unidade = '\0';

  printf("\nDigite o valor e a unidade: \n");
  scanf("%d%c", &valor, &unidade);
  printf("\nO valor e a unidade são: %d%c\n", valor, unidade);

  int n;

  while (1){
    printf("Digite um número: ");
      if (scanf("%d", &n) == 1){
        break;
      }
    printf("Tente novamente: \n");
  }

  printf("O número digitado foi: %d\n", n);

  return 0;

}