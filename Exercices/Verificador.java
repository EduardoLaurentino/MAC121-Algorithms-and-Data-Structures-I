public class Verificador{

    public static void main(String[] args){
        In in1 = new In(args[0]);
        In in2 = new In(args[1]);
        String saida1 = in1.readAll();
        String saida2 = in2.readAll();

        String[] texto1 = saida1.split("\\s+");
        String[] texto2 = saida2.split("\\s+");

        int N1 = texto1.length;
        int N2 = texto2.length;

        boolean iguais = true;
        for (int i = 0; iguais && i < N1 && i < N2; i++) {
            if (texto1[i].compareTo(texto2[i]) != 0) iguais = false;
        }

        if (iguais){
            StdOut.println("são iguais");
        }
        else StdOut.println("não são iguais");
    }
}