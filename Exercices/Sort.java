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


public class Sort{

    //vetor global auxiliar
    private static int[] aux;
    private static Numero[] aux2;

    //MERGESORT PARA VETOR DE OBJETOS STRING:
    public static void mergesort(Numero[] a){
        aux2 = new Numero[a.length];
        mergesort (a, 0, a.length);
    }

    public static void mergesort(Numero[] a, int lo, int hi){
        int N = hi - lo;
        if (N <= 1) return;
        int mid = lo + N/2;
        mergesort(a, lo, mid);
        mergesort(a, mid, hi);
        merge(a, lo, mid, hi);
    }

    public static void merge(Numero[] a, int lo, int mid, int hi){
        int i = lo, j = mid, N = hi - lo;

        for(int k = 0; k < N; k++){
            if (i == mid) aux2[k] = a[j++];
            else if (j == hi) aux2[k] = a[i++];
            else if (a[j].inteiro() < a[i].inteiro()) aux2[k] = a[j++];
            else aux2[k] = a[i++];
        }
        for (int k = 0; k < N; k++) a[lo + k] = aux2[k];
    }


    //MERGESORT PARA VETOR DE OBJETOS STRING:
    public static void mergesort(int[] a){
        aux = new int[a.length];
        mergesort (a, 0, a.length);
    }

    public static void mergesort(int[] a, int lo, int hi){
        int N = hi - lo;
        if (N <= 1) return;
        int mid = lo + N/2;
        mergesort(a, lo, mid);
        mergesort(a, mid, hi);
        merge(a, lo, mid, hi);
    }

    public static void merge(int[] a, int lo, int mid, int hi){
        int i = lo, j = mid, N = hi - lo;

        for(int k = 0; k < N; k++){
            if (i == mid) aux[k] = a[j++];
            else if (j == hi) aux[k] = a[i++];
            else if (a[j] < a[i]) aux[k] = a[j++];
            else aux[k] = a[i++];
        }
        for (int k = 0; k < N; k++) a[lo + k] = aux[k];
    }

}