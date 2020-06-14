/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Segmento comum mais longo e subpalíndromo mais longo
 * Data: 22/09/2017
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


public class LongestPalindrome{

    //encontra o maior prefixo comum de duas strings a partir de pontos especificos
    private static String lcp(String s, int p, String t, int q) {
        int n = Math.min(s.length() - p, t.length() - q);
        for (int i = 0; i < n; i++) {
            if (s.charAt(p + i) != t.charAt(q + i))
                return s.substring(p, p + i);
        }
        return s.substring(p, p + n);
    }

    //compara segmentos especificos de duas strings
    private static int compare(String s, int p, String t, int q) {
        int n = Math.min(s.length() - p, t.length() - q);
        for (int i = 0; i < n; i++) {
            if (s.charAt(p + i) != t.charAt(q + i))
                return s.charAt(p+i) - t.charAt(q+i);
        }
        if      (s.length() - p < t.length() - q) return -1;
        else if (s.length() - p > t.length() - q) return +1;
        else                                      return  0;
    }

    //encontra a maior substring comum entre duas strings
    public static String lcs(String s, String t) {
        SuffixArray2 suffix1 = new SuffixArray2(s);
        SuffixArray2 suffix2 = new SuffixArray2(t);

        String lcs = "";
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            int p = suffix1.index(i);
            int q = suffix2.index(j);
            String x = lcp(s, p, t, q);
            if (x.length() > lcs.length() && x.compareTo(inverte(x)) == 0) lcs = x; //garante que em casos do tipo "abcefcba" não retornará 'abc' como um palíndromo
            if (compare(s, p, t, q) < 0) i++;
            else                         j++;
        }
        return lcs;
    }

    //retorna string com caracteres em ordem contrária da entrada
    public static String inverte(String s){
        String t = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            t += s.charAt(i);
        }

        return t;
    }


    public static void main(String[] args) {
        String s;
        if (args.length > 0) {
            In in1 = new In(args[0]);
            s = in1.readAll().trim().replaceAll("\\s+", " ");
        }
        else {
            s = StdIn.readLine().trim().replaceAll("\\s+", " ");
        }

        String t = inverte(s);

        StdOut.println(lcs(s, t));
    }
}
