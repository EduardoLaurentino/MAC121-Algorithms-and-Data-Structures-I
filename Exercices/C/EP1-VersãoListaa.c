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
  celula_editor *fim;
  int marca;
  char copia[10000];
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
  editor->inicio = NULL;
  editor->cursor->prox = editor->inicio;

  return editor;
}

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "r");
  if (arquivo == NULL){
    FILE *arquivoNovo = fopen(nome, "w");
  }
  else {
    FILE *arquivo = fopen(nome, "r"); ///???
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
  e->cursor->ant = e->fim->prox = NULL;
  e->marca = -1;
}

/* Exibe editor na tela */
void ExibeEditor (editorTAD e){
  celula_editor *p;
  if(e->cursor->prox == e->inicio){ /*ponteiro no inicio do texto */
    for (p = (e->cursor); p != NULL; p = (p->prox)) printf("%c", (p->caractere));
  }
  else{
    for (p = (e->inicio); p != NULL; p = (p->prox)){
     printf("%c", (p->caractere));
    }
  }
}

void AvancaCursor (editorTAD e){
  celula_editor *p;
  celula_editor *q;
  p = e->cursor->prox;
  q = e->cursor->ant;

  if (p != NULL){ /*verifica limite final*/
    if(q == NULL){ /*quando o ponteiro ta no inicio do texto*/
      e->cursor->prox = p->prox;
      e->cursor->ant = p;
      p->prox = e->cursor;

    } else { /*ponteiro no meio do texto*/
      q->prox = p;
      p->ant = q;
      if (p != e->fim){
        e->cursor->prox = p->prox;
        e->cursor->ant = p;
        p->prox->ant = e->cursor;
        p->prox = e->cursor;
      } else {
        e->cursor->prox = NULL;
        e->cursor->ant = p;
        p->prox = e->cursor;
      }
    }
  }
}

void RetrocedeCursor (editorTAD e){
  celula_editor *p;
  celula_editor *q;

  p = e->cursor->prox;
  q = e->cursor->ant;

  if (q != NULL){ /*verifica limite inicial do texto*/
    if (p == NULL){ /*quando o ponteiro esta no final do texto*/
      e->cursor->ant = q->ant;
      e->cursor->prox = q;
      q->ant->prox = e->cursor;
      q->ant = e->cursor;
      q->prox = p;
    } else { /*quando o ponteiro esta no meio do texto*/
      q->prox = p;
      p->ant = q;
      if (q != e->inicio){ /*quando ponteiro retrocederá para posição que não é anterior ao inicio*/
        q->ant->prox = e->cursor;
        e->cursor->ant = q->ant;
        q->ant = e->cursor;
        e->cursor->prox = q;
      } else {
        e->cursor->ant = NULL;
        q->ant = e->cursor;
        e->cursor->prox = q;
      }
    }
  }
}

/* Apaga caracartere na posição do cursor */
void RemoveCaractereAtual (editorTAD e){
  celula_editor *p = malloc(sizeof(celula_editor));
  p = e->cursor->prox;
  if (p != NULL){ /*verifica limite final*/
    if (p != e->fim){
      e->cursor->prox = p->prox;
      p->prox->ant = e->cursor;
      if (p == e->inicio) e->inicio = p->prox; /*remoção do primeiro caractere*/
    } else { /*remoção do último caractere*/
      e->cursor->prox = NULL;
      e->fim = e->cursor->ant;
    }
  }

  free(p);
}

/* Apaga caracartere na posição anterior do cursor */
void RemoveCaractereAnterior (editorTAD e){
  celula_editor *q = malloc(sizeof(celula_editor));
  q = e->cursor->ant;
  if (q != NULL){ /*verifica limite inicial*/
    if (q != e->inicio){
      e->cursor->ant = q->ant;
      q->ant->prox = e->cursor;
      if (q == e->fim) e->fim = q->ant; /*remoção do ultimo caractere*/
    } else { /*remoção do primeiro caractere*/
      e->cursor->ant = NULL;
      e->inicio = e->cursor->prox;
    }
  }

  free(q);
}

void InsereCaractere (editorTAD e, char c){
  celula_editor *x = malloc(sizeof(celula_editor));
  x->caractere = c;
  celula_editor *q;
  q = e->cursor->ant;

  x->ant = q;
  x->prox = e->cursor;

  if (q != NULL){ /*inserção no meio*/
    q->prox = x;
  } else { /*inserção no limite inicial*/
    e->inicio = x;
  }
  if (q == e->fim){ /*inserção no limite final*/
    e->fim = x;
  }
  e->cursor->ant = x;
}

/* Marca/memoriza posição atual */
void MarcaPosicao (editorTAD e){
  int n = 0;
  celula_editor *c;
  if(e->cursor->prox != e->inicio){
    for(c = e->inicio; c != NULL && c != e->cursor; c = c->prox) n++;
  }
  e->marca = n;
}

///====================aaaaaaaaaaAAAAAAAAAAAAAAAAAAAAAAAAaaaaaaAAAAAAAAAAAAAAaaaaaaaaaaaaaaaaaaa===========

/* Copia texto entre posicao marcada e cursor (inclusive) */
void CopiaTexto (editorTAD e){
  if (e->marca != -1){
    int n = 0, p = 0, i = 0;
    celula_editor *c;

    if(e->cursor->prox != e->inicio){
      for(c = e->inicio; c != NULL && c != e->cursor; c = c->prox) n++;
    } else c = e->inicio; /*quando a copia é do inicio até algum ponto outro*/

    if (n > (e->marca)){ /*quando a copia é do ponto de marcação pra frente*/
      for(c = e->inicio; p != (e->marca); c = c->prox) p++;
      while (c != e->cursor){ ///ou (p < n)
        e->copia[i++] = c->caractere;
        c = c->prox;
      }
      if (c->prox != NULL) e->copia[i++] = c->prox->caractere; /*copia o elemento NO cursor*/
    } else { /*quando a copia é do ponto de marcação para trás*/
      while (n <= (e->marca) && c != NULL){
        e->copia[i++] = c->caractere;
        c = c->prox;
        n++;
      }
    }

    e->copia[i] = '\0'; /*dá fim a string*/
    e->marca = -1;
  }
}

/* Insere texto em memoria auxiliar na posicao atual */
void InsereTexto (editorTAD e){
    int i;
  for (i = 0; e->copia[i] != '\0' ;++i)
  {
    InsereCaractere(e, e->copia[i]);
  }
  e->marca = -1;
}

/* Salva conteudo do editor em arquivo */
void SalvaTexto (editorTAD e, char *nome){
  FILE *arquivo = fopen(nome, "w");
  celula_editor *p;

  for (p = (e->inicio); p != NULL; p = (p->prox)){
    if (p->caractere != '^'){ /*para não imprimir o cursor*/
      fputc(p->caractere, arquivo);
    }
  }
}
/*=========================================*/

