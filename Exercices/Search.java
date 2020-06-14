/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Número de ocorrências em lista ordenada
 * Data: 19/09/2017
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

public class Search
{
    private static int quant = 0;

    public static int binary(int key, Numero[] words)
    {
        return binary(key, words, 0, words.length);
    }

    public static int binary(int key, Numero[] words, int inicio, int fim)
    {
        if (fim <= inicio) return -1; //não encontrou

        int meio = inicio + (fim - inicio)/2;

        if      (words[meio] == null || words[meio].inteiro() > key) return binary(key, words, inicio, meio);
        else if (words[meio] == null || words[meio].inteiro() < key) return binary(key, words, meio+1, fim);

        else return meio;
    }

}
