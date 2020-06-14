    public class Anagramas{

    public static void main(String[] args){
            String in = StdIn.readAll();
            String[] palavras = in.split("\\s+");
            int N = palavras.length;

            //for(int i = 0; i < N; i++) StdOut.println(palavras[i]);
            //StdOut.println("----");

            Ordenation.sort(palavras);

            //for(int i = 0; i < N; i++) StdOut.println(palavras[i]);
            //StdOut.println("----");

            String[] palavras_crescentes = new String[N];
            String[] wrd = new String[20]; //o enunciado diz que as palavras tem no máximo 20 caracteres

            for (int i = 0; i < N; i++) {
                wrd = palavras[i].split("");
                Ordenation.sort(wrd);
                palavras_crescentes[i] = toString(wrd);
            }

            ///for(int i = 0; i < N; i++) StdOut.println(palavras_crescentes[i]);
            ///StdOut.println("----");

            //Ordenation.sort(palavras_crescentes);

            /*for (int i = 0; i < N; i++) {
                //int k;
                i = encontraAnagramas(palavras, palavras_crescentes, i) - 1;
                //i = k-1;
            }*/

            encontraAnagramas(palavras, palavras_crescentes);

    }

    public static String toString(String[] arr){
        String result = "";
        for(int i = 0; i < arr.length; i++)
            result += arr[i];
        return result;
    }

     public static int encontraAnagramas(String[] palavras, String[] palavras_crescentes, int inicio){
                String questao = palavras_crescentes[inicio];
                int i;
                for(i = inicio + 1; i < palavras_crescentes.length && palavras_crescentes[i].compareTo(questao) == 0; i++){
                        if (i == inicio + 1) StdOut.print("* " + palavras[inicio] + " ");
                        StdOut.print(palavras[i] + " ");
                }
                if (i > inicio + 1) StdOut.println();
                return i;
    }

    public static void encontraAnagramas(String[] palavras, String[] palavras_crescentes){

                for (int i = 0; i < palavras_crescentes.length; i++) {
                    boolean deu = false;
                    String em_questao = palavras_crescentes[i];
                    for (int j = i; j < palavras_crescentes.length; j++){
                        if (palavras_crescentes[j] != null && em_questao != null && palavras_crescentes[j].compareTo(em_questao) == 0){
                            if (i == j) StdOut.print("* " + palavras[j] + " ");
                            StdOut.print(palavras[j] + " ");
                            palavras_crescentes[j] = null;
                            deu = true;
                        }
                    }
                    if (deu) StdOut.println();
                }

    }

}