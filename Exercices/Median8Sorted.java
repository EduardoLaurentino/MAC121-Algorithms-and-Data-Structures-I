public class Median8Sorted{

    public static Comparable select(Comparable[] a, Comparable b[], int k){
        return select(a, 1, a.length, b, 1, b.length, k - 1);
    }

     public static Comparable select(Comparable[] A, int startA, int endA, Comparable[] B, int startB, int endB, int k)
    {
            int n = endA - startA;
            int m = endB - startB;

            if (n <= 0)
                return B[startB + k - 1];
            if (m <= 0)
                return A[startA + k - 1];
            if (k == 1)
                return A[startA].compareTo(B[startB]) < 0 ? A[startA] : B[startB];

            if (k == 0){
                if (A[0].compareTo(B[0]) < 0) return A[0];
                else return B[0];
            }

            int midA = (startA + endA) / 2;
            int midB = (startB + endB) / 2;

            if (A[midA].compareTo(B[midB]) <= 0)
            {
                if (n / 2 + m / 2 + 1 >= k)
                    return select(A, startA, endA, B, startB, midB, k);
                else
                    return select(A, midA + 1, endA, B, startB, endB, k - n / 2 - 1);
            }
            else
            {
                if (n / 2 + m / 2 + 1 >= k)
                    return select(A, startA, midA, B, startB, endB, k);
                else
                    return select(A, startA, endA, B, midB + 1, endB, k - m / 2 - 1);

            }
    }
}