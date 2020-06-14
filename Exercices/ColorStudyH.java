/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Variante do Creative Ex. 3.1.33 (Color study)
 * Data: 17/08/2017
 *
 * Baseado em: HSB.java e ColorStudy.java
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/


import java.awt.Color;

public class ColorStudyH{
    public static void main(String[] args){
        float h1 = Float.parseFloat(args[0]);
        float h2 = Float.parseFloat(args[1]);
        StdDraw.setXscale(-1, 16);
        StdDraw.setYscale(-1, 16);

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                int gray = i*16 + (15-j);
                float t = (float) ((Math.sqrt(i*i + j*j))/(Math.sqrt(450))); ///450 = 15*15 + 15*15 (dimensões da imagem);
                float hue = (1-t)*h1 + t*h2;
                Color c1 = Color.getHSBColor(hue, 0.95f, 0.95f);
                Color c2 = new Color(gray, gray, gray);
                StdDraw.setPenColor(c1);
                StdDraw.filledSquare(i, j, 0.5);
                StdDraw.setPenColor(c2);
                StdDraw.filledSquare(i, j, 0.25);

            }
        }
        StdDraw.save("study" + "-" + h1 + "-" + h2 + ".png");
    }
}