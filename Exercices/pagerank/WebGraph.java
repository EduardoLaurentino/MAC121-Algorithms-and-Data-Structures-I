/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: PageRank - Parte II
 * Data: 16/11/2017
 *
 * Dependências: tudo o que os progrmas WebCrawler.java e FindLinks.java forncecidos no enunciado dependem.
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/

public class WebGraph {

    private static void recycle(String v, Queue<String> q, ST<String, Integer> noTries) {
        if (!noTries.contains(v)) {
            noTries.put(v, 1);
            q.enqueue(v);
            return;
        }
        int triesSoFar = noTries.get(v);
        if (triesSoFar < 20) { // HARD CODED!
            noTries.put(v, triesSoFar + 1);
            q.enqueue(v);
        }
    }

    public static void main(String[] args) throws Exception {
        // timeout connection after 500 miliseconds
        System.setProperty("sun.net.client.defaultConnectTimeout", "500");
        System.setProperty("sun.net.client.defaultReadTimeout",    "2000");

        String s = args[0];  // initial web page for BFS
        String t = args[1];  // must contain t in webserver's name
        int MAXN = Integer.parseInt(args[2]);
        Queue<String> q = new Queue<String>();
        q.enqueue(s);
    SET<String> discovered = new SET<String>();
        discovered.add(s);
        SET<String> visited = new SET<String>();
    ST<String, Integer> numberOfTries = new ST<String, Integer>();
        while (!q.isEmpty() && visited.size() < MAXN) {
            String v = q.dequeue();
        if (visited.contains(v)) continue;
            String input = null;
            try {
                In in = new In(v);
                input = in.readAll();
            } catch (IllegalArgumentException e) {
        recycle(v, q, numberOfTries);
                continue;
            }
        visited.add(v);
        Queue<String> links = LinkFinder.links(input, v);

        //além de eliminar outras impressões, tudo o que fiz foi adicionar as impressões abaixo:
        StdOut.print(v); //vértice
        for (String w : links) {
                    if (LinkFinder.validLink(w, t) && !discovered.contains(w)) {
                        try {
                        In in = new In(w);
                        } catch (Exception e) {
                        continue;
                        }
                        q.enqueue(w);
                        discovered.add(w);
                        StdOut.print(" " + w); //direções do vertice
                    }
        }
        StdOut.println(); //nova familia de ligações no grafo
    }
    }
}
