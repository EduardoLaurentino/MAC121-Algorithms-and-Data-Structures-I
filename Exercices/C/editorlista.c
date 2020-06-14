#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

typedef struct editorTCD *editorTAD;
editorTAD Editor (void);

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome);

void ExibeEditor (editorTAD e);

void AvancaCursor (editorTAD e);
void InsereCaractere (editorTAD e, char c);

int main(){
	editorTAD editor;
  	char nome[256];

  	printf ("Digite um nome de arquivo para carregar ou criar: ");
  	fgets (nome, 256, stdin);      nome[strlen (nome) - 1] = '\0';

  	editor = Editor ();
  	CarregaTexto (editor, nome);

  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	ExibeEditor(editor);	
  	





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
		printf("inicio = %c\n", e->inicio->caractere);
		printf("fim    = %c\n", e->fim->caractere);
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

