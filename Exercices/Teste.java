public class Teste
{
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        String[] palavras = in.readAllLines();

        double start = System.currentTimeMillis()/1000.0;
        while(!StdIn.isEmpty())
        {
            String chave = StdIn.readString();
            if (Search.sequential(chave, palavras) != -1) StdOut.println(chave);
        }
        double now = System.currentTimeMillis()/1000.0;
        StdOut.println((now - start) + " segundos");

    }

}