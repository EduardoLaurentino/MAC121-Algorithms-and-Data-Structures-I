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

public class CountOccurrences{

    public static void main(String[] args){

        In in = new In(args[0]);
        int[] inteiros = in.readAllInts();
        int[] queries = StdIn.readAllInts();

        int quant_inteiros = inteiros.length;
        int quant_queries = queries.length;

        Numero[] numeros = new Numero[quant_queries];
        int num = 0;
        for(int i = 0; i < quant_inteiros; i++){
            if (i == 0 || inteiros[i] != inteiros[i-1]){
                numeros[num] = new Numero(inteiros[i]);
                numeros[num++].mais();
            }
            else numeros[num-1].mais();
        }

        for(int i = 0; i < quant_queries; i++){
            int it = Search.binary(queries[i], numeros);
            if (it != -1) StdOut.println(numeros[it].quantidade());
            else StdOut.println("0");
        }
    }
}