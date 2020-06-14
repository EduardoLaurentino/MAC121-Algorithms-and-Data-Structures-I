public class Intervalo{
    public int min;
    public int max;

    public Intervalo(int min, int max){
        this.min = min;
        this.max = max;
    }

    public void print(){
        StdOut.println("[" + this.min + ", " + this.max + "]");
    }
}