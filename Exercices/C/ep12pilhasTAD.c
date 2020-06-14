#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Tipo Abstrato de CONCRETO Editor */
struct editorTCD{
  char texto[10000];
  char copia[10000];
  int topo1, topo2, marca;
};

typedef struct editorTCD *editorTAD;

/* Aloca memoria e retorna um editor vazio */
editorTAD Editor (void);

/* Carrega conteudo do editor de arquivo */
void CarregaTexto (editorTAD e, char *nome);

void ExibeEditor (editorTAD e);
void AvancaCursor (editorTAD e);
void RetrocedeCursor (editorTAD e);
void RemoveCaractereAtual (editorTAD e);
void RemoveCaractereAnterior (editorTAD e);
void MarcaPosicao (editorTAD e);
void CopiaTexto (editorTAD e);
void InsereTexto (editorTAD e);

int main(){
	editorTAD editor;
  	char nome[256];

  	printf ("Digite um nome de arquivo para carregar ou criar: ");
  	fgets (nome, 256, stdin);      nome[strlen (nome) - 1] = '\0';

  	editor = Editor ();
  	CarregaTexto (editor, nome);

  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	MarcaPosicao(editor);
  	
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	MarcaPosicao(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	MarcaPosicao(editor);

  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	
  	
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);

  	RemoveCaractereAtual(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	RemoveCaractereAtual(editor);
  	printf("\n\n");
  	ExibeEditor(editor);

  	RemoveCaractereAnterior(editor);
  	ExibeEditor(editor);
  	RemoveCaractereAnterior(editor);
  	ExibeEditor(editor);

  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);

  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);

  	MarcaPosicao(editor);
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	RetrocedeCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	CopiaTexto(editor);

  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	AvancaCursor(editor);
  	printf("\n\n");
  	ExibeEditor(editor);
  	InsereTexto(editor);
  	printf("\n\n");
  	ExibeEditor(editor);


  

  	

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
  while (i < 9999){ /*não estou certo se é 9999 ou 10000 o melhor*/
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
  printf("\nmarca = %d\n", e->marca);
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

  int b = 0;
  b += strlen(e->copia);;

  printf("%s tamanho: %d\n", e->copia, b);
}

void InsereTexto (editorTAD e){
  int i = e->topo1 + strlen(e->copia), pos_copia = 0;
  while (e->topo1 < i)
    e->texto[e->topo1++] = e->copia[pos_copia++];

  e->marca = -1;
}

/* Aloca memoria e retorna um editor vazio 
editorTAD Editor (void){
	editorTAD editor = malloc(sizeof(editorTAD));	
	editor->texto = malloc(sizeof(char)*10000);
	editor->topo1 = 0;
	editor->topo2 = (editor->topo1) + 1; /*não estou certo disso ainda, a ideia é deixar o espaço do cursor
	editor->limite = (editor->topo2);
	editor->marca = -1;
	return editor;
}

/* Carrega conteudo do editor de arquivo 
void CarregaTexto (editorTAD e, char *nome){
	FILE *arquivo = fopen(nome, "r");
	while((e->texto[e->limite++] = fgetc(arquivo)) != EOF);
	e->texto[e->topo1] = '^';
	printf("topo1 = %i\ntopo2 = %i\n\n", e->topo1, e->topo2);
}

/* Move cursor para frente/tras uma posicao; nao tem efeito se posicao resultante for invalida 
void AvancaCursor (editorTAD e){
	e->texto[e->topo1++] = e->texto[e->topo2++];
	e->texto[e->topo1] = '^';
}

void RetrocedeCursor (editorTAD e){
	e->texto[--(e->topo2)] = e->texto[--(e->topo1)];
	e->texto[e->topo1] = '^';
}

void ExibeEditor (editorTAD e){
	int i = 0;
	while (i < (e->topo1)){
		printf("%c", e->texto[i++]);
	}
	while (i < (e->limite)){
		printf("%c", e->texto[i++]);
	}
	printf("\n");
}

/* Apaga caracartere na posição (anterior) do cursor 
void RemoveCaractereAtual (editorTAD e){
	for (int i = (e->topo2); i < (e->limite) && e->texto[i] != EOF; ++i)
	{
		e->texto[i] = e->texto[i + 1];
	}
	e->limite--;
}

void RemoveCaractereAnterior (editorTAD e){
	e->texto[--(e->topo1)] = '^';
	for (int i = (e->topo2); i < (e->limite); ++i)
	{
		e->texto[i - 1] = e->texto[i]; 
	}
	e->topo2--;
	e->limite--;
}

/* Marca/memoriza posição atual 
void MarcaPosicao (editorTAD e){
	e->marca = e->topo1;
}

/* Copia texto entre posicao marcada e cursor (inclusive) 
void CopiaTexto (editorTAD e){
	int pos_copia = 0;
	if(e->marca == -1) exit(1);
	else{
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
}

/* Insere texto em memoria auxiliar na posicao atual 
void InsereTexto (editorTAD e){
	int i, pos_copia = 0;
	e->limite += strlen(e->copia);
	e->topo2 += strlen(e->copia);
	for (i = e->limite; i > e->topo1; i--)
	{
		e->texto[i] = e->texto[i-1];
	}
	for (i = ((e->topo1) + 1); i < e->topo2; ++i)
	{
		e->texto[e->topo1 + 1] = e->copia[pos_copia];
	}

	free(e->copia);
	e->marca = -1;
}
*/
