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

public class Word{
        String palavra;
        String palavra_ordenada;

        //construtor
        public Word(String s1, String s2){
            palavra = s1;
            palavra_ordenada = s2;
        }

        //método de retorno de atributo
        public String palavra(){
            return this.palavra;
        }

        //método de retorno de atributo
        public String palavra_ordenada(){
            return this.palavra_ordenada;
        }

        //deixa os caracteres do segundo atributo em ordem lexigofráfica
        public void OrdenaPalavra(){
            String[] wrd = this.palavra_ordenada.toUpperCase().split(""); //toUpperCase() é feito para contornar problemas com relações de maíuscula-minúscula
            Ordenation.sort(wrd);
            this.palavra_ordenada = toString(wrd);
        }

        public static String toString(String[] arr){
                String result = "";
                for(int i = 0; i < arr.length; i++)
                    result += arr[i];
                return result;
        }
}