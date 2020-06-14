#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "editor.h"

#define MAX 100000

struct editorTCD{
  char texto[10000];
  char copia[10000];
  int topo1, topo2, marca;
};

typedef struct registro{
  char *chave;
  char *conteudo;
  struct registro *esq;
  struct registro *dir;
} noh;

/*struct arvoreTCD{
  char *chave;
  char *conteudo;
  noh *esq;
  noh *dir;
};*/

typedef noh arvoreTCD;

int main (void)
{
  editorTAD editor;
  arvoreTAD dicionario;
  char nome[256], palavra[256], palavra2[256];
  int c, i;

  printf ("Digite um nome de arquivo para carregar ou criar: ");
  fgets (nome, 256, stdin);      nome[strlen (nome) - 1] = '\0';

  editor = Editor ();
  CarregaTexto (editor, nome);
  dicionario = ArvoreBinaria ();
  CarregaDicionario (dicionario, "dicio.txt");

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
    case 'R': RecortaTexto (editor);            break;
    case 'B':
      i = 0;
      while (1) {
        c = getchar();
        if (c == EOF || c == 3 || c == 4 || c == '.' || i == 255) {
          palavra[i] = '\0'; break;
        } else palavra[i] = c;
        i++;
      }
      Busca (editor, palavra);              break;
    case 'S':
      i = 0;
      while (1) {
        c = getchar();
        if (c == EOF || c == 3 || c == 4 || c == ' ' || i == 255) {
          palavra[i] = '\0'; break;
        } else palavra[i] = c;
        i++;
      }
      i = 0;
      while (1) {
        c = getchar();
        if (c == EOF || c == 3 || c == 4 || c == '.' || i == 255) {
          palavra2[i] = '\0'; break;
        } else palavra2[i] = c;
        i++;
      }
      Substitui (editor, palavra, palavra2); break;
    case 'O':
        Ortografia (editor, dicionario, palavra);
        if (palavra != NULL && palavra[0] != '\0') {
            printf("Palavra incorreta: %s\n\n", palavra);
            ExibeEditor (editor);
        }
        break;
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
  if (arquivo == NULL){
    FILE *arquivoNovo = fopen(nome, "w");
  }
  else {
    while((e->texto[e->topo1++] = fgetc(arquivo)) != EOF);
    while(e->topo1 > 0) e->texto[e->topo2--] = e->texto[--e->topo1];
  }

}

/* Move cursor para frente/tras uma posicao; nao tem efeito se posicao resultante for invalida */
void AvancaCursor (editorTAD e){
  if (e->topo1 <= 9999 && e->topo2 < 9999) /*verifica se não é o limite final do texto*/
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
  while (i < 9999 && e->texto[i] != EOF){ /*verifica se não é o limite final do texto*/
    printf("%c", e->texto[i++]);
  }
  ///printf("\n");
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
      while(e->marca <= e->topo1) /*copia até a posição NO cursor*/
        e->copia[pos_copia++] = e->texto[e->marca++];
    }
    else{
      int aux = e->topo2 + 1;
      while (aux <= (e->topo2 + (e->marca - e->topo1))) e->copia[pos_copia++] = e->texto[aux++];
    }
    e->copia[pos_copia] = '\0';
  }
  e->marca = -1;
}

/* Recorta texto entre posicao marcada e cursor (inclusive) */
void RecortaTexto (editorTAD e){
  if(e->marca != -1){
    int pos_recorte = 0, m = e->marca;
    if (e->topo1 > e->marca){ /*recorte do ponto de marcação para frente*/
      while(e->marca <= e->topo1) e->copia[pos_recorte++] = e->texto[e->marca++];
      while(e->topo1 > m) RemoveCaractereAnterior(e);
      RemoveCaractereAtual(e);
    }
    else { /*recorte do ponto de marcação para trás*/
      int aux = e->topo2 + 1;
      while (aux <= (e->topo2 + (e->marca - e->topo1 + 1))) e->copia[pos_recorte++] = e->texto[aux++];
      aux = e->topo2 + 1;
      int auxfixa = e->topo2;
      while(aux <= (auxfixa + (e->marca - e->topo1 + 1))){
        RemoveCaractereAtual(e);
        aux++;
      }
    e->copia[pos_recorte] = '\0'; /*põe fim a string copiada*/
  }
  e->marca = -1;
}
}

void InsereTexto (editorTAD e){
  if (e->topo1 <= (9999 - strlen(e->copia))){ /*verifica se não há espaço para insererir o texto copiada*/
    ///int i = e->topo1 + strlen(e->copia),
    int pos_copia = 0;
    while (e->copia[pos_copia] != '\0')
      e->texto[e->topo1++] = e->copia[pos_copia++];

    e->marca = -1;
  }
}

/* Busca próxima ocorrência de str no texto e atualize cursores. */
void Busca (editorTAD e, char *str){
  int ocorrencias, h, k, i, j, et2, m = strlen(str), novo_m = strlen(str) - 1;
  int n = 10000 - e->topo2;
  int alcance[MAX];

  /*pré-processamento da palavra na lógica do algoritmo de Boyer-Moore*/
        h = novo_m; k = novo_m - 1;
        while (h >= 0 && k >= 1){
                i = novo_m;
                j = k;
                while (i >= h && j >= 1){
                    if (str[i] == str[j]){
                        --i;
                        --j;
                    } else{
                        i = novo_m;
                        j = --k;
                    }
                }
                alcance[h--] = k;
        }

        while (h >= 0) alcance[h--] = k;
  /*fim do pré-processamento*/

        ocorrencias = 0;
        k = novo_m;
        et2 = e->topo2;
        while (k <= n && ocorrencias == 0){ /*para assim que encontra primeira ocorrencia*/
                i = novo_m;
                j = k;
                while (i >= 0 && str[i] == e->texto[et2 + j]){
                        --i;
                        --j;
                }
                /*abaixo condições de contorno pra validar ocorrencia segunda a definição de palavra do enunciado do ep*/
                if (i < 0 && (e->texto[et2 + j] == ' ' || (e->topo1 == 0) || e->texto[et2 + j] == '\n'  || e->texto[et2 + j] == '\r') && (e->texto[et2+ j+m+1] == ' ' || e->texto[et2+ j +m+1] == '\0' || e->texto[et2 + j +m+1] == '.' || e->texto[et2+j+m+1] == '?' || e->texto[et2+j+m+1] == '!' || e->texto[et2+j+m+1] == ';' || e->texto[et2+j+m+1] == ',' || e->texto[et2+j+m+1] == '\n' || e->texto[et2+j+m+1] == '\r' || e->texto[et2+j+m+1] == EOF)) ++ocorrencias;
                if (i == novo_m) k += 1;
                else k += novo_m - alcance[i+1];
        }

        if (ocorrencias != 0){ /*muda marcacação e posição do cursor em caso de busca bem sucedida*/
            e->marca = e->topo1 + j; /*inicio da primeira ocorrencia*/
            int cursor = e->topo1 + j + m - 1; /*o quanto o cursor tera que avançar*/
            while (e->topo1 != cursor){
                AvancaCursor(e);
            }
        }

}

/* Substitui próxima ocorrência de str1 por str2 e atualiza cursores. */
void Substitui (editorTAD e, char *str1, char *str2){
    int parametro1 = e->topo1 + e->topo2;
    int marca = e->marca;
    Busca(e, str1);
    int parametro2 = e->topo1 + e->topo2;

    if (parametro1 != parametro2){ /*busca bem sucedida*/
    RecortaTexto(e);
    e->marca = marca; /*garante que o comando não altera marcação prévia, conforme exige enunciado*/
    int pos_str2 = 0;
    while (str2[pos_str2] != '\0')
      e->texto[e->topo1++] = str2[pos_str2++];
  }
}

/* Insere caractere na posicao do cursor */
void InsereCaractere (editorTAD e, char c){
  if (e->topo1 < (9999)) /*verifica se há espaço para inserir*/
  e->texto[e->topo1++] = c;
}

/* Salva conteudo do editor em arquivo */
void SalvaTexto (editorTAD e, char *nome){
  int i, j;
  FILE *arquivo = fopen(nome, "w");
  for (i = 0; i < e->topo1; ++i) fputc(e->texto[i], arquivo);
  for (j = e->topo2 + 1; j < 9999; ++j) fputc(e->texto[j], arquivo);

  fclose(arquivo);
}

///aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa///

/* Aloca memoria e retorna uma árvore de busca binária vazia */
arvoreTAD ArvoreBinaria (void){
    arvoreTAD arvore = malloc(sizeof(arvoreTAD));
    arvore = NULL;
    return arvore;
}

// A função recebe uma árvore de busca r
// e uma folha avulsa novo e insere a folha
// na árvore de modo que a árvore continue
// sendo de busca. A função devolve a raiz
// da árvore resultante.

/*arvoreTAD insere (arvoreTAD r, arvoreTAD novo) {
    if (r == NULL) return novo;

    int lex = strcmp(r->chave, novo->chave);

    if (lex > 0)
       r->esq = insere (r->esq, novo);
    else
       r->dir = insere (r->dir, novo);
    return r;
}*/

/* Carrega dicionário (lista de palavras aceitas) em uma árvore de busca binária
void CarregaDicionario (arvoreTAD a, char *nome){
      FILE *arquivo = fopen(nome, "r");
      /*if (arquivo = NULL){
          printf("dicionário inválido.");
          break;
      }
      char *string;
      while (fgets(string, 20, arquivo) != NULL){
          noh *novo = malloc(sizeof(noh));
          novo->chave = string;
          novo->esq = novo->dir = NULL;

          noh *f, *p;
          if (a == NULL){
            noh *n = malloc(sizeof(noh));
            n->chave = string;
            n->esq = n->dir = NULL;
            a = n;
          }
          else{
                f = a;
                while (f != NULL){
                      p = f;
                      int lex = strcmp(f->chave, novo->chave);
                      if (lex > 0) f = f->esq;
                      else f = f->dir;
                }
                int lex2 = strcmp(p->chave, novo->chave);
                if (lex2 > 0) p->esq = novo;
                else p->dir = novo;
          }
      }
}



/* Verifica ortografia. Coloca a próxima palavra não aceita pelo dicionário (palavra é NULL se todas as palavras forem aceitas */
void Ortografia (editorTAD e, arvoreTAD a, char *palavra){
  char c = 'a';
  if (e->topo1 < (9999)) /*verifica se há espaço para inserir*/
  e->texto[e->topo1++] = c;

}

void CarregaDicionario (arvoreTAD a, char *nome){
  char c = 'a';
}
