public class MWS
{
    public static void main(String[] args){
        In in1 = new In(args[0]);
        In in2 = new In(args[1]);
        String txt = in1.readAll();
        String[] texto = txt.split("[^\\p{L}]+");
        String[] palavras = in2.readAllStrings();
        int N = texto.length;
        int k = palavras.length;

        // construct queues[j] = sequence of positions of jth query word
        Queue<Integer>[] queues = (Queue<Integer>[]) new Queue[args.length];
        for (int j = 0; j < k; j++) {
            queues[j] = new Queue<Integer>();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < k; j++) {
                if (words[i].equals(palavras[j])) queues[j].enqueue(i);
            }
        }

        int min = N + 10;
        int max = -1;
        int tam = 0;

        for(int i = 0; i < k; i++){
            if (!queues[i].isEmpty()){
                int x = queues[i].dequeue();
                if (x <= min) min = x;
                if (x > max) max = x;
            }
            tam = max - min;
        }












        //cria a árvore de busca binária onde cada nó terá como chave/key uma palavra do texto e como valor/value o seu índice
        BST<String, Integer> dicionario = new BST<String, Integer>();
        for(int m = 0; m < k; m ++){
            dicionario.put(palavras[m], -1);
        }

        int achadas = 0;
        boolean primeira = false;
        int ind_primeira = 0;
        int ind_ultima = 0;
        int tamanho_intervalo = 0;

        int i;

        for (i = 0; i < N; i++) {
            Integer x = dicionario.get(texto[i]);
            if (achadas < k && x != null && x == -1) {
                achadas++;
                if (!primeira) {primeira = true; ind_primeira = i;}
                dicionario.put(texto[i], i);
            }
            if (achadas == k) {
                ind_ultima = i;
                tamanho_intervalo = ind_ultima - ind_primeira;
            }
        }

        StdOut.println(tamanho_intervalo);

    }
}