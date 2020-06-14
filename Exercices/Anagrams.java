/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Web Exercise 4.2.12 (Anagrams)
 * Data: 15/09/2017
 *
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/

public class Anagrams{

    public static void main(String[] args){
            String in = StdIn.readAll();
            String[] extracao = in.split("\\s+");
            int N = extracao.length;

            Word[] palavras = new Word[N];
            for(int i = 0; i < N; i++){
                palavras[i] = new Word(extracao[i], extracao[i]);
                palavras[i].OrdenaPalavra();
            }

            Ordenation.sort(palavras); //ordena o vetor de Word com base no atributo palavra_ordenada

            imprimeAnagramas(palavras);
    }

    public static void imprimeAnagramas(Word[] palavras){
        boolean primeira = true; //auxiliar para detectar nova linha de anagramas
        for(int i = 1; i < palavras.length; i++){
            if(palavras[i].palavra_ordenada.compareTo(palavras[i-1].palavra_ordenada) == 0) {
                if (primeira) StdOut.print("* " + palavras[i-1].palavra);
                StdOut.print(" " + palavras[i].palavra);
                primeira = false;
            }
            else {
                if (!primeira) StdOut.println();
                primeira = true;
            }
        }
    }

}