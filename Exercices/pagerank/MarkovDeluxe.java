/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: PageRank - Parte I
 * Data: 16/11/2017
 *
 * Dependências: SymbolDigraph.java, Digraph.java, SparseMatrix.java. SparseVector.java (e todas as dependencias destes)
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/

public class MarkovDeluxe{

    public static void main(String[] args){
        String filename  = args[0];
        String delimiter = args[1];
        double alfa = Double.parseDouble(args[2]);
        int trials = Integer.parseInt(args[3]);
        boolean verboso = false;
        if (args.length > 4) verboso = true;

        SymbolDigraph links = new SymbolDigraph(filename, delimiter);
        Digraph graph = links.digraph();
        int n = graph.V();
        SparseMatrix counts = new SparseMatrix(n);
        SparseVector outDegree = new SparseVector(n);
        SparseVector inDegree = new SparseVector(n);

        //acumula informação sobre links
        for(int v = 0; v < n; v++){
            for (int w : graph.adj(v)) {
                outDegree.put(v, outDegree.get(v) + 1);
                counts.put(v, w, counts.get(v, w) + 1);
            }
        }

        //matrizes (/vetores) tais como definidas no artigo http://www.ams.org/samplings/feature-column/fcarc-pagerank
        SparseMatrix H = new SparseMatrix(n);
        SparseVector Ad = new SparseVector(n); //para lidar com dangling nodes
        SparseVector Id = new SparseVector(n);

        //preenchimento de acordo com a definição
        for (int i = 0; i < n; i++)  {
            Id.put(i, (1-alfa)/n);
            for (int j = 0; j < n; j++){
                double p;
                if (outDegree.get(i) != 0){
                    p = alfa*counts.get(i, j)/outDegree.get(i);
                    H.put(i, j, p);
                }
                else{
                    Ad.put(i, alfa*(1.0/n));
                }
            }
        }

        //vetor auxiliar pro método das potências
        SparseVector interm = new SparseVector(n);
        for(int i = 0; i < n; i++) interm.put(i, 1.0);

        //ESSES VETORES E MÉTODOS AUXILIARES SERIAM NECESSÁRIOS
        //PARA FAZER O MÉTODO DAS POTENCIAS MAIS SEGMENTADO.
        //NO FIM, DEIXEI O MÉTODO IMPLEMENTADO DE MANEIRA DIRETA, PRA
        //ECONOMIZAR USO DE MEMÓRIA E TEMPO DE ACESSO, MAS MANTIVE
        //AS PARTES COMENTADAS PARA FACILITAR O ENTENDIMENTO POSTERIOR:

        /*SparseVector med1 = new SparseVector(n);
        SparseVector med2 = new SparseVector(n);
        SparseVector med3 = new SparseVector(n);
        SparseVector med4 = new SparseVector(n);
        double r1, r2;*/

        SparseVector rank = new SparseVector(n);
        rank.put(0, 1.0);

        for (int t = 0; t < trials; t++){
            //r1 = rank.dot(Id);
            //r2 = rank.dot(Ad);
            //med1 = interm.scale(r1);
            //med2 = interm.scale(r2);
            //med4 = med1.plus(med2);
            //rank = rank.plus(med4);
            //TUDO ISSO EQUIVALE A FAZER:
            rank = H.transpose().times(rank).plus(interm.scale(rank.dot(Id)).plus(interm.scale(rank.dot(Ad))));
        }

        SparseVector rank2 = new SparseVector(n);
        if(verboso){
            rank2 = H.transpose().times(rank).plus(interm.scale(rank.dot(Id)).plus(interm.scale(rank.dot(Ad))));
        }

        for (String v : links.vertexNames()){
            int ind = links.indexOf(v);
            if(verboso)
                StdOut.printf("%5.7f %5.7f %d %s\n", rank.get(ind), rank2.get(ind), graph.indegree(ind), v);
            else
                System.out.printf("%5.7f  %s\n", rank.get(ind), v);
        }
    }
}