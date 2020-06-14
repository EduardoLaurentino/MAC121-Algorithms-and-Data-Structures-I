/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Web Exercise 4.2.1 (Union of intervals)
 * Data: 12/09/2017
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

import java.util.Arrays;
import java.util.Comparator;
import java.awt.Color;

public class UnionOfIntervals{


    public static void main(String[] args){

        boolean verboso = false;
        if (args.length > 0) { //prepara para o modo verboso
            StdDraw.setXscale(0, 1.0);
            StdDraw.setYscale(0, 1.0);
            verboso = true;
        }

        while(!StdIn.isEmpty()) {
            String in = StdIn.readAll();
            String[] dicionario = in.split("\\s+");
            int N = dicionario.length/2;

            Interval1D[] intervals = new Interval1D[N];
            int k = 0;
            double aux = 0.15;
            for(int i = 0; i < N; i++){
                intervals[i] = new Interval1D(Double.parseDouble(dicionario[k++]), Double.parseDouble(dicionario[k++]));
                if (verboso){
                    StdDraw.setPenColor(StdDraw.LIGHT_GRAY);
                    StdDraw.line(intervals[i].min(), 0, intervals[i].min(), 1.0);
                    StdDraw.line(intervals[i].max(), 0, intervals[i].max(), 1.0);
                }
            }

            Arrays.sort(intervals, Interval1D.MIN_ENDPOINT_ORDER);

            if (verboso){
                StdDraw.setPenColor(StdDraw.BLACK);
                StdDraw.setPenRadius(0.004);
                for(int i = 0; i < N; i++){
                    StdDraw.line(intervals[i].min(), aux, intervals[i].max(), aux);
                    aux += 0.01;
                }
            }

            aux += 0.05; //pula alguns espaços para as barras vermelhas

            Interval1D[] intervalsR = new Interval1D[N];

            k = 0;

            for(int i = 0; i < N-1; i++){
                if (intervals[i].intersects(intervals[i+1])){
                    if (Interval1D.MAX_ENDPOINT_ORDER.compare(intervals[i], intervals[i+1]) == +1) {
                        intervalsR[k] = new Interval1D(intervals[i].min(), intervals[i].max());
                    }
                    else {
                        intervalsR[k] = new Interval1D(intervals[i].min(), intervals[i+1].max());
                    }

                    intervals[i+1] = intervalsR[k++];
                }
            }

            for (int i = 0; i < N-1; i++){
                if (intervalsR[i] != null && intervalsR[i].equals(intervalsR[i+1])) intervalsR[i+1] = null;
            }

            double tam = 0;
            int quant = 0;
            for (int i = 0; i < N; i++){
                if (intervalsR[i] != null){
                    tam += intervalsR[i].length();
                    quant++;
                    if (verboso){
                        StdDraw.setPenColor(StdDraw.RED);
                        StdDraw.line(intervalsR[i].min(), aux, intervalsR[i].max(), aux);
                        aux += 0.01;
                    }
                }
            }

            StdOut.println("Total length: " + tam + " [" + quant + " components]");

            for (int i = 0; i < N; i++){
                if (intervalsR[i] != null){
                     StdOut.println(intervalsR[i]);
                }
            }
        }
    }

}
