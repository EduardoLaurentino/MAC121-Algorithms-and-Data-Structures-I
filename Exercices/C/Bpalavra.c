#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    char *t = "esta o esta amor esta onde sta sta esta esta porque estamental estamento estava tem que  sta sta esta est esta esta";
    char *p = "esta";

    printf("a palavra ocorre no texto %d vezes.\n", Busca(p, strlen(p), t, strlen(t)));
    printf("a palavra ocorre no texto %d vezes.\n", Busca2(p, strlen(p), t, strlen(t)));

    return 0;

}

int Busca(char *palavra, int m, char *texto, int n){
        int T1[256], i, k, r, ocorrencias, novo_m = m - 1;

        for (i = 0; i < 256; i++) T1[i] = novo_m;
        for (i = 0; i <= novo_m; i++) T1[palavra[i]] = novo_m - i;

        ocorrencias = 0; k = novo_m;
        while (k <= n){
            r = 0;
            while (novo_m-r >= 0 && palavra[novo_m-r] == texto[k-r]) r += 1;
            if (novo_m-r < 0) ocorrencias += 1;
            if (k == n) k += 1;
            else k += T1[texto[k+1]] + 1;
        }

        return ocorrencias;
}

int Busca2(char *palavra, int m, char *texto, int n){
        int ocorrencias, h, k, i, j, novo_m = m - 1;
        int *alcance = malloc((m)*sizeof(int));

        h = novo_m; k = novo_m - 1;
        while (h >= 0 && k >= 1){
                i = novo_m;
                j = k;
                while (i >= h && j >= 1){
                    if (palavra[i] == palavra[j]){
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


        ocorrencias = 0;
        k = novo_m;
        while (k <= n){
                i = novo_m;
                j = k;
                while (i >= 0 && palavra[i] == texto[j]){
                        --i;
                        --j;
                }
                if (i < 0 && (texto[j] == ' ' || j<0) && (texto[j+m+1] == ' ' || texto[j+m+1] == '\0')) ++ocorrencias;
                if (i == novo_m) k += 1;
                else k += novo_m - alcance[i+1];
        }

        return ocorrencias;
}

typedef struct noh_arvore{
  char *chave;
} noh;

struct arvoreTCD{
  noh conteudo;
  arvoreTCD *esq;
  arvoreTCD *dir;
}