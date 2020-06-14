/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: WordLoop
 * Data: 23/11/2017
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

public class WordLoop{
    public static ST<String, Boolean> marked = new ST<String, Boolean>();
    public static boolean ciclo = false;
    public static int tam_min = 0;

    // return true if two strings differ in exactly one letter
    public static boolean isNeighbor(String a, String b) {
        int differ = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) differ++;
        }
        return (differ == 1);    }

    //dfs apaptada para detecção de loops
    public static void dfs(Graph G, String s, String fonte, Stack<String> memo, int tam_min) {
        marked.put(s, true);
        for (String v : G.adjacentTo(s)) {
            if (ciclo) break;
            if (!marked.get(v)) {
                dfs(G, v, fonte, memo, tam_min + 1);
                if (ciclo) memo.push(v);
            }
            else if (v.equals(fonte) && tam_min >= 2) {ciclo = true; return;}
        }
    }

    public static void main(String[] args){
        In in = new In(args[0]);
        String[] dicionario = in.readAllStrings();
        int n = dicionario.length;

        Graph G = new Graph();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (isNeighbor(dicionario[i], dicionario[j]))
                    G.addEdge(dicionario[i], dicionario[j]);

        String in2 = StdIn.readAll();
        String[] palavras = in2.split("\\s+");
        int t = palavras.length;

        for(int l = 0; l < t; l++){
            for (String v : G.vertices()) marked.put(v, false);
            //reconhece quando a palvra nao faz parte do dicionario
            if (!marked.contains(palavras[l])) StdOut.println(palavras[l] + ": not in graph");
            //se tiver no dicionario, procura pelo loop
            else{
                Stack<String> loop = new Stack<String>();
                loop.push(palavras[l]);
                dfs (G, palavras[l], palavras[l], loop, tam_min);
                loop.push(palavras[l]);
                if (!ciclo) StdOut.println(palavras[l] + ": no word loop");
                else StdOut.println(palavras[l] + ": " + loop.toString());

            }
            //restaura o ambiente para a proxima palavra
            ciclo = false;
            tam_min = 0;
        }
    }
}
