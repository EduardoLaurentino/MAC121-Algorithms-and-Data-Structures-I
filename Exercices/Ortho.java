/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Verificador ortográfico
 * Data: 01/09/2017
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


public class Ortho
{
    public static void main(String[] args)
    {
        //booleana para detecção da execucao a ser feita
        boolean modo_marcador = false;
        if (args.length > 1 && args[1].compareTo("-m") == 0) modo_marcador = true;

        //carrega dicionario
        In in = new In(args[0]);
        String[] dicionario = in.readAllStrings();

        //raiz do verificador
        while(!StdIn.isEmpty()) {
            String linha = StdIn.readLine();
            String[] palavras = linha.split("\\W+"); //separa em palavras (split) de uma linha e retira os caracteres de pontuação (regex \\W+)

            for(int i = 0; i < palavras.length; i++)
                if ((palavras[i].length() > 1) && (Search.binary(palavras[i], dicionario) == -1)){
                    if (Search.binary(palavras[i].toLowerCase(), dicionario) == -1){
                        if (modo_marcador && !(palavras[i].matches(".*\\d.*"))) { //!(palavras[i].matches(".*\\d.*")) = garante que não considerará numeros como palavras inexistentes
                            linha = linha.replace("*"+palavras[i]+"*", palavras[i]); //garante que não haverá dupla marcação
                            linha = linha.replace(palavras[i], "*" + palavras[i] + "*");
                        }
                        else if (!(palavras[i].matches(".*\\d.*")))  StdOut.println(palavras[i]);}
                    }
            if (modo_marcador) StdOut.println(linha);
        }
    }
}
