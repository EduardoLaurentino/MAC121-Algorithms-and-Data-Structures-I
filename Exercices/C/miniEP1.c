/* Mini-EP1 NUSP: 8988212 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *entrada, *saida;
    int numAV, numDV, n;
    int m, c, d, u, dc, uc, a, carac = 0;
    char *cifra, *cifra_singular, ch, *preco, *precoAV, *precoDV;
    
    /* Declaracao de suas variaveis */;
    char *unidades[] = {"zero","um","dois","tres","quatro","cinco","seis","sete","oito","nove"};
	char *dezVinte[] = {"dez","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"};
	char *dezenas[] = {"","dez","vinte", "trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa"};
	char *centenas[] = {"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"};
    char *milhares[] = {"", "um mil", "dois mil", "três mil", "quatro mil", "cinco mil", "seis mil", "sete mil", "oito mil", "nove mil"};
    /* Verifica se numero de argumentos de entrada e' suficiente */
    if (argc < 3) {
        fprintf(saida, "Numero de parametros insuficiente:\n\tuse %s arquivo_entrada arquivo_saida\n", argv[0]);
    }
    /* Abre arquivo de entrada; termina programa em caso de falha */
    if (!(entrada = fopen(argv[1], "r"))) {
        fprintf(saida, "Nao foi possivel abir o arquivo %s para leitura. Abortando...\n", argv[1]);
        return 1;
    }

    /* Abre arquivo de saida; termina programa em caso de falha */
    if (!(saida = fopen(argv[2], "w"))) {
        fprintf(saida, "Nao foi possivel abir o arquivo %s para escrita. Abortando...\n", argv[2]);
        return 1;
    }


    while ((ch = getc(entrada)) != EOF){
    	preco = (char *)malloc(10);
    	precoAV = (char *)malloc(10);
    	precoDV = (char *)malloc(10);

	    while (ch != ' ' && ch != '\n'){
	    	preco[carac++] = ch;
	    	ch = getc(entrada);
	    }
	    carac = 0;

		if (preco[0] == 'R'){ /*valor em reais*/
	    	n = a = 2;
	    	cifra = "reais";
	    	cifra_singular = "real";
	  	}
	  	else if (preco[0] == 'U'){
	  		n = a = 3;
	  		cifra = "dólares";
	  		cifra_singular = "dólar";
	  	} else {
	  		n = 0; a = 1;
	  	}

	  	while(preco[n++] != ',' && n != 1);
	    for (int i = a; i < n-1; ++i) precoAV[i-a] = preco[i];
	  	for (int j = n; j < strlen(preco); ++j) precoDV[j-n] = preco[j];
	  	numAV = atoi(precoAV);
	  	numDV = atoi(precoDV);

	  	m = numAV/1000;
	  	c = numAV/100 - m*10;
	  	d = numAV/10 - m*100 - c*10;
	  	u = numAV - (numAV/10)*10;
	  	///fprintf(saida, "m = %d; c = %d; d = %d; u = %d;\n", m, c, d, u);

	  	if(m != 0) fprintf(saida, "%s ", milhares[m]);
	  	if(c != 0) fprintf(saida, "%s ", centenas[c]);
	  	if ((c != 0 && d != 0) || (c != 0 && u != 0)) fprintf(saida, "e ");
	  	if(d != 0 && d != 1){
	  		fprintf(saida, "%s ", dezenas[d]);
	  		if (d != 0 && u != 0) fprintf(saida, "e ");
	  		if(u != 0) fprintf(saida, "%s ", unidades[u]);
	  	}
	  	if(d == 0 && u != 0) fprintf(saida, "%s ", unidades[u]);
	  	if(d == 1) fprintf(saida, "%s ", dezVinte[u]);
	  	if ((n != 1) && (m != 0 || c != 0 || d != 0 || u != 0)){
	  		if (m == 0 && c == 0 && d == 0 && u == 1) fprintf(saida, "%s", cifra_singular);
	  		else fprintf(saida, "%s", cifra);
	  	}
	  	if (numAV == 0 && numDV == 0) fprintf(saida, "zero %s", cifra);

	  	dc = numDV/10;
	  	uc = numDV - (numDV/10)*10;
	 
	  	if (numDV != 0){
	  		if (numAV != 0) fprintf(saida, " e ");
		  	if(dc != 0 && dc != 1){
		  		fprintf(saida, "%s ", dezenas[dc]);
		  		if (dc != 0 && uc != 0) fprintf(saida, "e ");
		  		if(uc != 0) fprintf(saida, "%s ", unidades[uc]);
		  	}
		  	if(dc == 0 && uc != 0) fprintf(saida, "%s ", unidades[uc]);
		  	if(dc == 1) fprintf(saida, "%s ", dezVinte[uc]);
		  	if(dc == 0 && uc == 1) fprintf(saida, "centavo");
		  	else fprintf(saida, "centavos");
		  	if (m == 0 && c == 0 && d == 0 && u == 0) fprintf(saida, " de %s", cifra);
		} else fprintf(saida, " e zero centavos");
		

		fprintf(saida, "\n");
		
		free(preco);
		free(precoAV);
		free(precoDV);

	}

	fclose(entrada);
	fclose(saida);
    /* Seu codigo */
    /* ... */
    return 0;
}
