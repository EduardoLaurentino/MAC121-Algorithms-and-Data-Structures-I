#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "editor.h"

struct editorTCD{
  char texto[10000];
  char copia[10000];
  int topo1, topo2, marca;
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
  editorTAD editor = (editorTAD) malloc(sizeof *((editorTAD)NULL)); 
  editor->topo1 = 0;
  editor->topo2 = 9999; /*ultima posição do vetor de 10000 caracteres*/
  editor->marca = -1;
  return editor;
}


/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "r");
  while((e->texto[e->topo1++] = fgetc(arquivo)) != EOF);
  while(e->topo1 > 0) e->texto[e->topo2--] = e->texto[--e->topo1];
  
}

/* Move cursor para frente/tras uma posicao; nao tem efeito se posicao resultante for invalida */
void AvancaCursor (editorTAD e){
  if (e->topo1 <= 9999) /*verifica se não é o limite final do texto*/
  e->texto[(e->topo1)++] = e->texto[++(e->topo2)];
}

void RetrocedeCursor (editorTAD e){
  if (e->topo1 != 0) /*verifica se não é o limite inicial do texto*/
  e->texto[(e->topo2)--] = e->texto[--(e->topo1)];
}


void ExibeEditor (editorTAD e){
  int i = 0;
  while (i < (e->topo1)){
    printf("%c", e->texto[i++]);
  }
  printf("^");
  i = e->topo2 + 1;
  while (i < 9999){ /*verifica se não é o limite final do texto*/
    printf("%c", e->texto[i++]);
  }
  printf("\n");
}

/* Apaga caracartere na posição (anterior) do cursor */
void RemoveCaractereAtual (editorTAD e){
  if (e->topo2 < 9999) e->topo2++;
}

void RemoveCaractereAnterior (editorTAD e){
  if (e->topo1 > 0) e->topo1--;
}

/* Marca/memoriza posição atual */
void MarcaPosicao (editorTAD e){
  e->marca = e->topo1;
}

/* Copia texto entre posicao marcada e cursor (inclusive) */
void CopiaTexto (editorTAD e){
  if(e->marca != -1){
    int pos_copia = 0;
    if(e->topo1 > e->marca){
      while(e->marca < e->topo1)
        e->copia[pos_copia++] = e->texto[e->marca++];
    }
    else{
      int aux = e->topo2 + 1;
      while (aux < (e->topo2 + e->marca - 2)) e->copia[pos_copia++] = e->texto[aux++];
    }
    e->copia[pos_copia] = '\0';
  }
  e->marca = -1;
}

void InsereTexto (editorTAD e){
  if (e->topo1 <= (9999 - strlen(e->copia))){ /*verifica se não há espaço para insererir o texto copiada*/
    int i = e->topo1 + strlen(e->copia), pos_copia = 0;
    while (e->topo1 < i)
      e->texto[e->topo1++] = e->copia[pos_copia++];

    e->marca = -1;
  }
  
}

/* Insere caractere na posicao do cursor */
void InsereCaractere (editorTAD e, char c){
  if (e->topo1 < (9999)) /*verifica se há espaço para inserir*/
  e->texto[e->topo1++] = c;
}

/* Salva conteudo do editor em arquivo */
void SalvaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "w");
  for (int i = 0; i < e->topo1; ++i) fputc(e->texto[i], arquivo);
  for (int j = e->topo2 + 1; j < 9999; ++j) fputc(e->texto[j], arquivo);

  fclose(arquivo);
}
