public class Median4Sorted{

    public static Comparable select(Comparable[] a, Comparable b[], int k){
        return select(a, b, a.length, b.length, k, 0, 0);
    }

    public static Comparable select(Comparable a[], Comparable b[], int m, int n, int k, int st1, int st2)
    {
        // In case we have reached end of array 1
        if (st1 == m)
            return b[st2 + k - 1];

        // In case we have reached end of array 2
        if (st2 == n)
            return a[st1 + k - 1];

        // k should never reach 0 or exceed sizes
        // of arrays
        if (k == 0){
            if (a[0].compareTo(b[0]) < 0) return a[0];
            else return b[0];
        }

        //if (k )


        // Compare first elements of arrays and return
        if (k == 1)
            return (a[st1].compareTo(b[st2]) < 0) ?
                a[st1] : b[st2];

        int curr = k / 2;

        // Size of array 1 is less than k / 2
        if (curr - 1 >= m - st1)
        {
            // Last element of array 1 is not select
            // We can directly return the (k - m)th
            // element in array 2
            if (a[m - 1].compareTo(b[st2 + curr - 1]) < 0)
                return b[st2 + (k - (m - st1) - 1)];
            else
                return select(a, b, m, n, k - curr,
                    st1, st2 + curr);
        }

        // Size of array 2 is less than k / 2
        if (curr-1 >= n-st2)
        {
            if (b[n - 1].compareTo(a[st1 + curr - 1]) < 0)
                return a[st1 + (k - (n - st2) - 1)];
            else
                return select(a, b, m, n, k - curr,
                    st1 + curr, st2);
        }
        else
        {
            // Normal comparison, move starting index
            // of one array k / 2 to the right
            if (a[curr + st1 - 1].compareTo(b[curr + st2 - 1]) < 0)
                return select(a, b, m, n, k - curr,
                    st1 + curr, st2);
            else
                return select(a, b, m, n, k - curr,
                    st1, st2 + curr);
        }
    }
}