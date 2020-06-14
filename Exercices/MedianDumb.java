public class MedianDumb{

    public static int select(int[] a, int[] b, int k){
        //Merge.merge(a, b, 0, (a.length + b.length)/2, , (a.length + b.length));

        int N = a.length + b.length;
        //StdOut.println(N);
        int[] c = new int[N];

        int i;
        for(i = 0; i < a.length; i++){
            //StdOut.println("i = " + i + "; a = " + a[i]);
            c[i] = a[i];
            c[a.length + i] = b[i];
            //StdOut.println("a.length + i = " + (a.length + i) + "; b = " + b[i]);
        }

        Ordenation.sort(c);

        for(int j = 0; j < N; j++) StdOut.println("c[" + j + "] = " + c[j]);

        return c[k];
    }

    public static void main(String[] args){
        int[] a = {10, 12, 13, 17, 21, 23};
        int[] b = {5, 6, 7, 9, 10, 11};

        int result = (int)select(a, b, 9);
        System.out.println(result);
    }
}