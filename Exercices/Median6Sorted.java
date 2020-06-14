public class Median6Sorted{
    public static Comparable select(Comparable[] a, Comparable[] b, int k)
    {
        int step = k / 4;

        int i1 = k / 2;
        int i2 = k - i1;

        while(! (b[i2].compareTo(a[i1 - 1]) >= 0 && a[i1].compareTo(b[i2 - 1]) >= 0))
        {
            if (a[i1 - 1].compareTo(b[i2 - 1]) >= 0)
            {
                i1 -= step;
                i2 += step;
            }
            else
            {
                i1 += step;
                i2 -= step;
            }

            step /= 2;
            if (step <= 0) step = 1;
        }

        if (a[i1 - 1].compareTo(b[i2 - 1]) >= 0)
            return a[i1 - 1];
        else
            return b[i2 - 1];
    }
}