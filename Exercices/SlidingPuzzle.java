/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Sliding Puzzle
 * Data: 20/11/2017
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

public class SlidingPuzzle{

    // print n! permutation of the characters of the string s (in order)
    public  static void perm1(String s, Graph G) { perm1("", s, G); }
    private static void perm1(String prefix, String s, Graph G) {
        int n = s.length();
        if (n == 0) G.addVertex(prefix);
        else {
            for (int i = 0; i < n; i++)
               perm1(prefix + s.charAt(i), s.substring(0, i) + s.substring(i+1, n), G);
        }
    }

    //recebe uma string e retorna o indice o primeiro caracter '0'; se não tiver, retorna -1;
    public static int posZero(String v){
        boolean continua = true;
        int i = 0;
        for (i = 0 ; i < v.length() && continua; i++)
            if (v.charAt(i) == '0')
                return i;
        return -1;
    }

    //recebe uma string e retorna o indice o primeiro caracter c; se não tiver, retorna -1;
    public static int posChar(String v, String c){
        boolean continua = true;
        int i = 0;
        for (i = 0 ; i < v.length() && continua; i++)
            if (String.valueOf(v.charAt(i)).equals(c))
                return i;
        return -1;
    }

    //devolve uma representação linear de string de um grafo qualquer
    public static String toString(Graph J) {
        StringBuilder s = new StringBuilder();
        for (String v : J.vertices())
            s.append(v);
        return s.toString();
    }

    public static void main(String[] args){
        Graph G = new Graph();
        String padrao = "";
        String[] entrada;
        String[] bases = new String[100];

        if (args[0].equals("-f")){
            Graph J = new Graph(args[1], "/");
            boolean verboso = false;
            if (args.length > 2 && args[2].equals("-v")) verboso = true;

            //pega as situações iniciais
            String in = StdIn.readAll();
            entrada = in.split("\\n+");
            int num_bases = entrada.length;

            padrao = toString(J);
            G.addVertex(padrao);

            //coloca todas as permutaçções em vértices de G
            perm1(padrao, G);

            //encontra as arestas de G
            for (String v : G.vertices()) {
                int numero = posZero(v);
                for (String t : J.adjacentTo(""+numero)){
                    String[] temp = v.split("");
                    int p = Integer.parseInt(t);
                    String e = temp[p];
                    temp[p] = temp[numero];
                    temp[numero] = e;
                    String nova = "";
                    for(int i = 0; i < temp.length; i++) nova += temp[i];
                    G.addEdge(v, nova);
                }
            }

            PathFinder pf = new PathFinder(G, padrao);

            StdOut.println(G.V() + " vertices and " + G.E() + " edges");

            int reachable = 0;
            int missing = 0;

            //tabela "em que podemos ler quantas configurações estão à distância d de I, para todo d"
            ST<Integer, Integer> st = new ST<Integer, Integer>();
            for (String v : G.vertices()){
                int key = pf.distanceTo(v);
                if (st.contains(key)) st.put(key, st.get(key) + 1);
                else st.put(key, 1);

                if (pf.hasPathTo(v)) reachable++;
                else missing++;
            }
            //imprime a tabela
            for (int s : st.keys())
                if (s < 500) System.out.printf("%3s      %3s%n", s, st.get(s));
            //

            StdOut.println("Reachable: " + reachable);
            StdOut.println("Missing: " + missing);
            StdOut.println();

            for(int i = 0; i < num_bases; i++){
                if (pf.hasPathTo(entrada[i])){
                    int tam = pf.distanceTo(entrada[i]);
                    StdOut.println("Number of moves: " + tam);
                    if (verboso){
                        String[] saidas = new String[tam+1];
                        int k = tam + 1;
                        for (String v : pf.pathTo(entrada[i])) {
                            saidas[--k] = v;
                        }
                        for(int l = 0; l < tam+1; l++) StdOut.println(saidas[l]);
                    }
                }
                else StdOut.println("No solution");
            }
        }

        else if (args[0].equals("-g")){
            int m = Integer.parseInt(args[1]);
            int n = Integer.parseInt(args[2]);
            boolean verboso = false;
            if (args.length > 3 && args[3].equals("-v")) verboso = true;
            int cont = 0;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    padrao += String.valueOf(cont++);
            G.addVertex(padrao);

            ///*constroi a matrix J*/
            String[][] matrix = new String[m][n];
            Graph J = new Graph();
            cont = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = String.valueOf(cont++);
                }
            }

            //transforma a matriz em grafo
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if (i-1 >= 0) J.addEdge(matrix[i][j], matrix[i-1][j]);
                    if (j+1 < n)  J.addEdge(matrix[i][j], matrix[i][j+1]);
                    if (i+1 < m)  J.addEdge(matrix[i][j], matrix[i+1][j]);
                    if (j-1 >= 0) J.addEdge(matrix[i][j], matrix[i][j-1]);
                }
            }
            /////////

            //coloca todas as permutaçções em vértices de G
            perm1(padrao, G);

            //encontra as arestas de G
            for (String v : G.vertices()) {
                int numero = posZero(v);
                for (String t : J.adjacentTo(""+numero)){
                    String[] temp = v.split("");
                    int p = Integer.parseInt(t);
                    String e = temp[p];
                    temp[p] = temp[numero];
                    temp[numero] = e;
                    String nova = "";
                    for(int i = 0; i < temp.length; i++) nova += temp[i];
                    G.addEdge(v, nova);
                }
            }

            //pega as situações iniciais
            String in = StdIn.readAll();
            entrada = in.split("\\n+");
            int num_bases = entrada.length/m;

            for(int p = 0; p < num_bases; p++){
                String base = "";
                for(int i = p*m; i < ((p*m)+m); i++){
                    String[] linha = entrada[i].split("\\s+");
                    for (int j = 0; j < n; j++) {
                        if (!linha[j].equals(".")) base += linha[j];
                        else base += "0";
                    }
                }
                bases[p] = base;
            }
            //

            PathFinder pf = new PathFinder(G, padrao);

            StdOut.println(G.V() + " vertices and " + G.E() + " edges");

            int reachable = 0;
            int missing = 0;

            //tabela "em que podemos ler quantas configurações estão à distância d de I, para todo d"
            ST<Integer, Integer> st = new ST<Integer, Integer>();
            for (String v : G.vertices()){
                int key = pf.distanceTo(v);
                if (st.contains(key)) st.put(key, st.get(key) + 1);
                else st.put(key, 1);

                if (pf.hasPathTo(v)) reachable++;
                else missing++;
            }
            //imprime a tabela
            for (int s : st.keys())
                if (s < 500) System.out.printf("%3s      %3s%n", s, st.get(s));
            //

            StdOut.println("Reachable: " + reachable);
            StdOut.println("Missing: " + missing);
            StdOut.println();

            for(int i = 0; i < num_bases; i++){
                if (pf.hasPathTo(bases[i])){
                    int tam = pf.distanceTo(bases[i]);
                    StdOut.println("Number of moves: " + tam);
                    if (verboso){
                            String[] saidas = new String[tam+1];
                            int k = tam + 1;
                            for (String v : pf.pathTo(bases[i])) {
                                saidas[--k] = v;
                            }
                            for(int l = 0; l < tam+1; l++){
                                String[] tmp = saidas[l].split("");
                                int contador = 0;
                                for(int p = 0; p < m; p++){
                                    for(int j = 0; j < n; j++)
                                        if (!tmp[contador].equals("0")) StdOut.print(tmp[contador++] + " ");
                                        else {StdOut.print(". "); contador++;}
                                    StdOut.println();
                                }
                                StdOut.println();
                            }
                        }
                    }
                else StdOut.println("No solution");
            }
        }
    }
}