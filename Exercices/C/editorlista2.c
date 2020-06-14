#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Tipo Abstrato de CONCRETO Editor */
typedef struct celula_editor{
	char caractere;
	struct celula_editor *prox;
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

int main(){
	editorTAD editor;
  	char nome[256];

  	printf ("Digite um nome de arquivo para carregar ou criar: ");
  	fgets (nome, 256, stdin);      nome[strlen (nome) - 1] = '\0';

  	editor = Editor ();
  	CarregaTexto (editor, nome);

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
	editor->inicio = editor->fim = editor->marca = NULL;
	return editor;
}

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome){
	FILE *arquivo = fopen(nome, "r");
	char caract;
	while((caract = fgetc(arquivo)) != EOF){
		celula_editor *c = malloc(sizeof(celula_editor));
		c->caractere = caract;
		if(e->inicio == NULL){
			e->inicio = c;
			printf("inicio1 = %c\n", e->inicio->caractere);
		}
		c->prox = e->fim;
		e->fim = c;
		printf("inicio = %c\n", e->inicio->caractere);
		printf("fim    = %c\n", e->fim->caractere);
	}
	printf("inicio2 = %c\n", e->inicio->caractere);
}

/* Exibe editor na tela */
void ExibeEditor (editorTAD e){
	celula_editor *p;
	for (p = (e->fim); p != NULL; p = (p->prox))
	{
		printf("%c", (p->caractere));
	}
}

