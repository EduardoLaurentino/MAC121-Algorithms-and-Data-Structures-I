/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Daniel Silva Nunes
 * Numero USP: 10297612
 * Tarefa: Word loops
 * Data: 23/11/2017
 *
 * Baseado em DepthFirstSearch.java, WordLadder.java
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/
public class WordLoopD {
	// return the number of characters that differs between strings a and b
    public static int diffCount(String a, String b) {
        int differ = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) differ++;
        }
        return differ;
    }

	public static void main (String[] args) {
		// array to keep all given words from the filename in args[0]. Max = 100k words
		String[] words = new String[100000];
		In in = new In(args[0]);
		// put words from file in words[]
		int n = 0;
		while (!in.isEmpty())
			words[n++] = in.readString();
		// put words from array in a graph and connect them if they're neighbors
		Graph G = new Graph();
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (diffCount(words[i], words[j]) == 1)
					G.addEdge(words[i], words[j]);

		//debug: print all vertices of graph G:
		//StdOut.println(G.toString());

		// read words from standard output and find loops for them
		loops(G);
	}

	public static void loops (Graph G) {
		while (!StdIn.isEmpty()) {
			// symbol table to control vertices that have already been visited
			ST<String, Boolean> marked = new ST<String, Boolean>();
			//mark every word from G with false in the symbol-table (any visited vertex yet)
			for (String vertex : G.vertices())
				marked.put(vertex, false);
			// get the word point
			String word = StdIn.readString();
			if (!marked.contains(word))
				// if the word is not in graph
				StdOut.println(word + ": not in graph");
			else {
				// keep the word loop in a stack (to print in the correct order)
				Stack<String> w = new Stack<String>();
				w.push(word);
				// depth-first search start searching the graph
				dfs (G, word, word, marked, 0, w);
				w.push(word);
				// if no cycle was found in dfs
				if (!cycle) StdOut.println(word+": no word loop");
				else StdOut.println(word+": " + w.toString());
				cycle = false;
			}

		}
	}

	// flag to control if a cycle is completed
	static boolean cycle = false;
	public static void dfs (Graph G, String word, String origin, ST<String, Boolean> marked, int count, Stack<String> w) {
		// the word has been visited
		marked.put(word, true);
		for (String vertex : G.adjacentTo(word)) {
			// if a cycle is found, it's not necessary to search for more vertices
			if (cycle) {
				break;
			}
			if (!marked.get(vertex)) {
				dfs(G, vertex, origin, marked, count+1, w);
				// run depth-first search for this vertex
				if (cycle)
					w.push(vertex);
				// if a loop has been found for 'word' (already marked vertex was found again)
			} else
			{
				// condition to determine if a word loop was found
				if (vertex.equals(origin) && count >= 2)
				{
					// set flag to true
					cycle = true;
					// break the recursive call
					return;
				}

			}


		}

	}
}
