/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Eduardo Rocha Laurentino
 * Numero USP: 8988212
 * Tarefa: Caching ótimo
 * Data: 28/11/2017
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

public class Clairvoyant{

    public static void main(String[] args){
        int m = Integer.parseInt(args[0]);
        boolean verboso = false;
        if (args.length > 1 && args[1].equals("-v")) verboso = true;

        String in = StdIn.readAll();
        String[] entrada = in.split("\\s+");
        int N = entrada.length;

        //cria uma tabela de símbolos que guarda,
        //pra cada elemento distinto da sequencia,
        //as posições onde ele aparece.
        ST<String, Queue<Integer>> st = new ST<String, Queue<Integer>>();
        //cria uma tabela de símbolos pra referenciar,
        //depois, quem já está no cache ou não,
        //guardando o index associado
        ST<String, Integer> st_check = new ST<String, Integer>();

        //roda em O(N(log n)), onde n é o número de entradas diferentes, dentre as N entradas
        for(int i = 0; i < N; i++){
            if (!st.contains(entrada[i])){
                Queue<Integer> fila = new Queue<Integer>();
                st.put(entrada[i], fila);
            }
            else st.get(entrada[i]).enqueue(i);
        }

        int cont = 0;
        int cache_misses = 0;
        //fila de prioridade que representará o cache
        IndexMaxPQ<String> cache = new IndexMaxPQ<String>(m);
        //guardara a distancia de cada elemento do cache até ele ocorrrer novamente,
        //contando a partir da posição atual na sequencia
        IndexMaxPQ<Integer> dist = new IndexMaxPQ<Integer>(m);

        //roda em O(N(log m + log n)), onde n é o número de entradas diferentes, dentre as N entradas
        for(int i = 0; i < N; i++){
            //se elemento já está no cache:
            if(st_check.contains(entrada[i]) == true){
                if(verboso) StdOut.println(entrada[i] + ": in cache");

                //atualiza a distancia
                Integer d1;
                if(!st.get(entrada[i]).isEmpty()){
                    d1 = st.get(entrada[i]).dequeue();
                    dist.changeKey(st_check.get(entrada[i]), d1);
                }
                else dist.changeKey(st_check.get(entrada[i]), N+100); //uma distancia absurda pra denotar que não aparecerá mais
                ///////////////////
            }
            //se cache está com espaço livre e elemento não estava lá
            else if(m > cache.size()){
                cache_misses++;
                cache.insert(cont, entrada[i]); //adiciona no cache
                st_check.put(entrada[i], cont); //marca que está no cache
                if(verboso) StdOut.println(entrada[i] + ": +" + entrada[i]);

                //guarda distancia pela primeira vez
                Integer d1;
                if(!st.get(entrada[i]).isEmpty()){
                    d1 = st.get(entrada[i]).dequeue();
                    dist.insert(cont, d1);
                }
                else dist.insert(cont, N+100); //uma distancia absurda pra denotar que não aparecerá mais
                ///////////////////

                cont++;
            }
            else{
                cache_misses++;
                String saida = cache.keyOf(dist.maxIndex());
                int belady = dist.maxIndex();

                //retira a marcação de que está no cache:
                st_check.remove(cache.keyOf(belady));
                //guarda no cache o novo elemente em detrimento do correto:
                cache.changeKey(belady, entrada[i]);
                //marca que está no cache:
                st_check.put(entrada[i], belady);

                if(verboso) StdOut.println(entrada[i] + ": -" + saida + "/+" + entrada[i]);

                //atualiza a distancia
                Integer d1;
                if (!st.get(entrada[i]).isEmpty()){
                    d1 = st.get(entrada[i]).dequeue();
                    dist.changeKey(belady, d1);
                }
                else dist.changeKey(belady, N+100); //uma distancia absurda pra denotar que não aparecerá mais
                ///////////////////
            }
        }
        StdOut.println("Number of cache misses: " + cache_misses);
    }
}

/**************************************JUSTIFICATIVA DA COMPLEXIDADE**************************************/
/*Este código, conforme comentado, tem um trecho que roda em O(N(log n)) e outra em O(N(log m + log n)).
Assintoticamente, a complexidade do programa é, portanto, O(N(log m + log n)). Essa complexidade vem do
fato de que "gastarmos" complexidade N ao percorrer toda entrada e, dentro disto, lidarmos com
acesso/remoção/inserção em fila de prioridade indexada de tamanho n, gastando "log m", e o mesmo
com uma tabela de símbolos de tamanho n, gastando log n.
/*********************************************************************************************************/