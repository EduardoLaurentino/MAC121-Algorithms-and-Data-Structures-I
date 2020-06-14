/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Non-overlapping interval search
 * Data: 03/10/2017
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

public class LocateBST
{
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        int[] limites = in.readAllInts();

        //cria a árvore de busca binária onde cada nó terá como chave/key o minimo do intervalo e como valor/value o máximo do intervalo
        BST<Integer, Integer> st = new BST<Integer, Integer>();
        for(int i = 0; i < limites.length; i += 2){
            int min = limites[i];
            int max = limites[i+1];
            st.put(min, max);
        }

        while (!StdIn.isEmpty()){
            int inteiro = StdIn.readInt();
            Integer floor = st.floor(inteiro);
            Integer ceiling = st.ceiling(inteiro);

            //caso em que o inteiro é menor que o mínimo do intervalo mais baixo
            if (floor == null) StdOut.println(inteiro + ": left of [" + st.select(1) + ", " + st.get(st.select(1)) + "]");

            //caso em que o inteiro está efetivamente dentro de um intervalo
            else if (floor <= inteiro && inteiro <= st.get(floor)) StdOut.println(inteiro + ": [" + floor + ", " + st.get(floor) + "]");

            //caso em que o inteiro é maior que o máximo do mais alto intervalo
            else if (ceiling == null) StdOut.println(inteiro + ": right of [" + st.select(st.size() - 1) + ", " + st.get(st.select(st.size() - 1)) + "]");

            //caso em que o inteiro está entre dois dos intervalos
            else StdOut.println(inteiro + ": between [" + floor + ", " + st.get(floor) + "] & [" + ceiling + ", " + st.get(ceiling) + "]");

        }

    }

}
