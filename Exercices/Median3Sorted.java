public class Median3Sorted{

    public static int[] limitesA = new int[2];
    public static int[] limitesB = new int[2];

    public static int select(int[] a, int[] b, int k){
        limitesA[1] = a.length;
        limitesB[1] = b.length;
        return select(a, b, k, limitesA, limitesB);
    }

    public static int select(int[] a, int[] b, int k, int[] limitesA, int[] limitesB){
        StdOut.println("a = [" + limitesA[0] + ", " + limitesA[1] + "]");
        StdOut.println("b = [" + limitesB[0] + ", " + limitesB[1] + "]");
        StdOut.println("k = " + k); StdOut.println();

        int i_medianaA = limitesA[0] + (limitesA[1] - limitesA[0])/2 - 1;
        int i_medianaB = limitesB[0] + (limitesB[1] - limitesB[0])/2 - 1;

        StdOut.print("a = {");
        for(int i = limitesA[0]; i < limitesA[1]; i++) {
            if (i != (limitesA[1] - 1)) StdOut.print(a[i] + ", ");
            else StdOut.println(a[i] + "}");
        }if (limitesA[0] == limitesA[1]) StdOut.println("ø}");
        StdOut.print("b = {");
        for(int i = limitesB[0]; i < limitesB[1]; i++) {
            if (i != (limitesB[1] - 1)) StdOut.print(b[i] + ", ");
            else StdOut.println(b[i] + "}");
        } if (limitesB[0] == limitesB[1]) StdOut.println("ø}");

        StdOut.println();
        StdOut.println("i_medianaA = " + i_medianaA + "; a[i_medianaA] = " + a[i_medianaA]);
        StdOut.println("i_medianaB = " + i_medianaB + "; b[i_medianaB] = " + b[i_medianaB]);

        StdOut.println();

        if ((limitesA[1] - limitesA[0]) <= 1 || limitesB[1] - limitesB[0] <= 1){
            return a[limitesA[0] + k];
        }

        if (a[i_medianaA] == b[i_medianaB]) //a[i_medianaA] == b[i_medianaB]
        {
            StdOut.println("a == b");
            if (k >= (i_medianaA + i_medianaB)){
                limitesA[0] = i_medianaA + 1;
                limitesB[0] = i_medianaB + 1;
                k -= i_medianaA + i_medianaB;
                //SELECT//
                StdOut.println("k >= medA + medB");
            }
            else{
                limitesA[1] = i_medianaA;
                limitesB[2] = i_medianaB;
                //SELECT//
                StdOut.println("k < medA + medB");
            }
        }

        else if (a[i_medianaA] > b[i_medianaB]) //a[i_medianaA] > b[i_medianaB]
        {
            StdOut.println("a > b");
            if (k < i_medianaA + i_medianaB - 1){
                limitesA[0] = i_medianaA;
                limitesB[0] = i_medianaB + 1;
                k -= (i_medianaA + i_medianaB - 1);
                //SELECT
                StdOut.println("k > medA + medB - 1");
            }
            else if (k < i_medianaB){
                limitesB[0] = i_medianaB;
                //limitesB[1] = i_medianaB;
                //SELECT
                StdOut.println("k <= medA + medB - 1");
            }

        }

        else
        {
            StdOut.println("a < b");
            if (k > i_medianaB + i_medianaA - 1){
                limitesB[0] = i_medianaB;
                limitesA[0] = i_medianaA + 1;
                k -= (i_medianaA + i_medianaB - 1);
                //SELECT
                StdOut.println("k > medA + medB - 1");
            }
            else{
                limitesA[1] = i_medianaA;
                limitesB[1] = i_medianaB;
                StdOut.println("k <= medA + medB - 1");
            }
        }

        StdOut.println("===============================================");
        return select(a, b, k, limitesA, limitesB);
    }

    public static void main(String[] args){
        int[] a = {10, 12, 15, 17, 21, 23, 26, 31, 42};
        int[] b = {5, 6, 7, 9, 10, 11, 13, 15};

        int result = (int)select(a, b, 3);
        System.out.println(result);
    }
}