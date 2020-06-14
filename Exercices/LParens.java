/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Exercício 1.3.9 de Algs4
 * Data: 27/10/2017
 *
 * Baseado em: LongestCommonSubstring.java, de Princeton
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/


public class LParens{

    public static void main(String[] args) {
        Stack<String> stack = new Stack<String>();

        while (!StdIn.isEmpty()){

            String token = StdIn.readString();

            if (!token.equals(")")){
                stack.push(token);
            }
            else{
                String s1 = stack.pop();
                String s2 = stack.pop();
                String s3 = stack.pop();
                String s = "(" + s3 + s2 + s1 + ")";
                stack.push(s);
            }
        }

        StdOut.println(stack.pop());
    }
}