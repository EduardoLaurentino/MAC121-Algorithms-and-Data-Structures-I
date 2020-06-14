#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "editor.h"

struct editorTCD{
  char *texto;
  char *copia;
  int topo1, topo2, limite, marca;
};

int main (void)
{
  editorTAD editor;
  char nome[256];
  int c;

  printf ("Digite um nome de arquivo para carregar ou criar: ");
  fgets (nome, 256, stdin);      nome[strlen (nome) - 1] = '\0';

  editor = Editor ();
  CarregaTexto (editor, nome);

  printf (":");
  while ((c = getchar ())) 
    switch (c) {
    case 't': ExibeEditor (editor); printf ("\n"); break;
    case 'i': 
      while (1) {
    c = getchar ();
    if (c == EOF || c == 3 || c == 4) break;
    else if (c == '^') {
      printf ("\n");
      c = '\n';
      break;
    } else InsereCaractere (editor, c);
      }
      break;
    case 'n': InsereCaractere (editor, '\n');   break;
    case 'r': RemoveCaractereAtual (editor);    break;
    case 'b': RemoveCaractereAnterior (editor); break;
    case 'e': RetrocedeCursor (editor);         break;
    case 'd': AvancaCursor (editor);            break;
    case 'm': MarcaPosicao (editor);            break;
    case 'c': CopiaTexto (editor);              break;
    case 'v': InsereTexto (editor);             break;
    case 's': SalvaTexto (editor, nome);        return 1;
    case EOF: case 3: case 4: return 1;
    case '\n': case '\r': printf (":"); break;
    }        
  return 0;
}



/* Aloca memoria e retorna um editor vazio */
editorTAD Editor (void){
  editorTAD editor = malloc(sizeof(editorTAD)); 
  editor->texto = malloc(sizeof(char)*10000);
  editor->topo1 = 0;
  editor->topo2 = 1; /*não estou certo disso ainda, a ideia é deixar o espaço do cursor*/
  editor->limite = (editor->topo2);
  editor->marca = -1;
  return editor;
}

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "r");
  while((e->texto[e->topo2++] = fgetc(arquivo)) != EOF);
  e->topo2 -= 2; /*desconsiderar o '\n' do fim do arquivo*/
  printf("topo2 = %d e limite = %d\n e texto[topo2] = %c", e->topo2, e->limite, e->texto[e->topo2-1]);
  e->texto[e->topo1] = '^';
}

/* Move cursor para frente/tras uma posicao; nao tem efeito se posicao resultante for invalida */
void AvancaCursor (editorTAD e){
  if(e->topo1 < ((e->limite)-1)){ /*verifica se não é o limite final do texto*/
    e->texto[e->topo1++] = e->texto[e->topo2++];
    e->texto[e->topo1] = '^';
  };
}

void RetrocedeCursor (editorTAD e){
  if(e->topo1 != 0){ /*verifica se não é o limite inicial do texto*/
    e->texto[--(e->topo2)] = e->texto[--(e->topo1)];
    e->texto[e->topo1] = '^';
  };
}

void ExibeEditor (editorTAD e){
  int i = 0;
  while (i < (e->topo1)){
    printf("%c", e->texto[i++]);
  }
  
  while (i < (e->topo2)){
    printf("%c", e->texto[i++]);
  }
  printf("\n");
}

/* Apaga caracartere na posição (anterior) do cursor */
void RemoveCaractereAtual (editorTAD e){
  if(e->topo1 < ((e->limite)-1)){ /*verifica se não é o limite final do texto*/
    for (int i = (e->topo2); i < (e->limite) && e->texto[i] != EOF; ++i)
    {
      e->texto[i] = e->texto[i + 1];
    }
    e->limite--;
  };
}

void RemoveCaractereAnterior (editorTAD e){
  if(e->topo1 != 0){ /*verifica se não é o limite inicial do texto*/
    e->texto[--(e->topo1)] = '^';
    for (int i = (e->topo2); i < (e->limite); ++i)
    {
      e->texto[i - 1] = e->texto[i]; 
    }
    e->topo2--;
    e->limite--;
  };
}

/* Marca/memoriza posição atual */
void MarcaPosicao (editorTAD e){
  e->marca = e->topo1;
}

/* Copia texto entre posicao marcada e cursor (inclusive) */
void CopiaTexto (editorTAD e){
  int pos_copia = 0;
  if(e->marca == -1) exit(1);
  else{
    free(e->copia); /*garante a liberaração da memoria ocupada pela ultima chamada de copia caso não tenha sido usada a função de inserir*/
    if (e->marca > e->topo1){
      e->copia = malloc(sizeof(char)*((e->marca) - (e->topo1)));
      for (int i = ((e->topo1) + 1); i <= (e->marca); ++i)
      {
        e->copia[pos_copia++] = e->texto[i];
      }
    } 
    else{
      e->copia = malloc(sizeof(char)*((e->topo1) - (e->marca)));
      for (int i = (e->marca); i < (e->topo1) ; ++i)
      {
        e->copia[pos_copia++] = e->texto[i];
      }

    }
  }
  e->marca = -1;
  int b = 0;
  b += strlen(e->copia);;

  printf("%s tamanho: %d\n", e->copia, b);
}

/* Insere texto em memoria auxiliar na posicao atual */
void InsereTexto (editorTAD e){
  int i, pos_copia = 0;
  e->limite += strlen(e->copia);
  e->topo2 += strlen(e->copia);
  for (i = e->limite; i >= e->topo2; i--)
  {
    e->texto[i] = e->texto[i-5]; /* esse "-5" entra pra ajustar, pois há alguns caracteres lixos após o limite */
  }
  for (i = ((e->topo1) + 1); i < e->topo2; ++i)
  {
    e->texto[i] = e->copia[pos_copia++];
  }


  free(e->copia); /*libera memoria*/
  e->marca = -1;
}

/* Insere caractere na posicao do cursor */
void InsereCaractere (editorTAD e, char c){
  e->limite++;
  e->texto[e->topo1++] = c;
  e->texto[e->topo1] = '^';
  for (int i = e->limite; i > e->topo2; --i)
  {
    e->texto[i] = e->texto[i - 1];
  }
}

/* Salva conteudo do editor em arquivo */
void SalvaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "a");
}
