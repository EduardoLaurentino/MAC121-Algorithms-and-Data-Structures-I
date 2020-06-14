public class Median7Sorted{

    public static Comparable select(Comparable[] arr1, Comparable[] arr2, int k) {
        if (k < 1 || k > (arr1.length + arr2.length)){
            if (arr1[0].compareTo(arr2[0]) <= 0) return arr1[0];
            else return arr2[0];
        }
         else return helper(arr1, 0, arr1.length, arr2, 0, arr2.length, k - 1);
    }


    private static Comparable helper(Comparable[] arr1, int low1, int high1, Comparable[] arr2, int low2, int high2, int k) {
        if (low1 > high1) {
            return arr2[low2 + k - 1];
        } else if (low2 > high2) {
            return arr1[low1 + k - 1];
        }
        if (k == 1) {
            if (arr1[low1].compareTo(arr2[low2]) < 0) return arr1[low1];
            else return arr2[low2];
            ///return Math.min(arr1[low1], arr2[low2]);
        }
        int i = Math.min(low1 + k / 2, high1 + 1);
        int j = Math.min(low2 + k / 2, high2 + 1);
        if (arr1[i - 1].compareTo(arr2[j - 1]) > 0) {
            return helper(arr1, low1, high1, arr2, j, high2, k - (j - low2));
        } else {
            return helper(arr1, i, high1, arr2, low2, high2, k - (i - low1));
        }
    }

}