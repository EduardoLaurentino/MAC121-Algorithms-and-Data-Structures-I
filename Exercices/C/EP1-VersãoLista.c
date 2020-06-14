#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "editor.h"

/* Tipo Abstrato de CONCRETO Editor */
typedef struct celula_editor{
  char caractere;
  struct celula_editor *prox;
  struct celula_editor *ant;
} celula_editor;

struct editorTCD{
  celula_editor *inicio;
  celula_editor *cursor;
  celula_editor *marca;
  celula_editor *fim;
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
  editorTAD editor = malloc (sizeof(struct editorTCD));
  celula_editor *c = malloc (sizeof(celula_editor));
  editor->cursor = c; 
  editor->cursor->caractere = '^';
  editor->cursor->prox = editor->inicio;
  editor->inicio = editor->marca = NULL;
  return editor;
}

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "r");
  if (arquivo == NULL){
    FILE *arquivoNovo = fopen(nome, "w"); 
  } 
  else {
    FILE *arquivo = fopen(nome, "r");
    char caract;
    while((caract = fgetc(arquivo)) != EOF){
      celula_editor *c = malloc(sizeof(celula_editor));
      c->caractere = caract;
      
      if (e->inicio == NULL){
        c->ant = NULL;
        e->inicio = c;
      }
      else{
        c->ant = e->fim;
        e->fim->prox = c;
      }
      e->fim = c;
    }
  }
  e->cursor->prox = e->inicio;
  e->cursor->ant = NULL;
}

/* Exibe editor na tela */
void ExibeEditor (editorTAD e){
  celula_editor *p;
  if(e->cursor->prox == e->inicio){
    for (p = (e->cursor); p != NULL; p = (p->prox)) printf("%c", (p->caractere));
  }
  else{
    for (p = (e->inicio); p != NULL; p = (p->prox)){
     printf("%c", (p->caractere));
    }
  }
}

void AvancaCursor (editorTAD e){
  celula_editor *p = malloc(sizeof(celula_editor)); 
  p = e->cursor->prox->prox;
  e->cursor->prox->ant = e->cursor->ant;
  e->cursor->prox->prox = e->cursor;
  e->cursor->ant = e->cursor->prox;
  e->cursor->prox = p;

  free(p);
}

void InsereCaractere (editorTAD e, char c){
  celula_editor *x = malloc(sizeof(celula_editor));
  x->caractere = c;
  x->prox = e->cursor;
  printf("%c\n", e->cursor->ant->caractere);
  x->ant = e->cursor->ant;
  e->cursor->ant->prox = x;
  e->cursor->ant = x;
}

/*=========================================*/

