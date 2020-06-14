public class Median5Sorted{

    public static Comparable select(Comparable[] a, Comparable b[], int k){
        return select(a, b, a.length, b.length, k);
    }

    public static int select(int A[], int m, int B[], int n, int k) {

       if (m <= 0 )return B[k-1];
       else if (n <= 0) return A[k-1];

       int i =  (m /(double) (m + n))  * (k-1);

       if (i < m-1 && i < (k-1)) ++i;
       int j = k - 1 - i;

       int Ai_1 = (i > 0) ? A[i-1] : INT_MIN, Ai = (i < m) ? A[i] : INT_MAX;
       int Bj_1 = (j > 0) ? B[j-1] : INT_MIN, Bj = (j < n) ? B[j] : INT_MAX;

       if (Ai >= Bj_1 && Ai <= Bj) {
           return Ai;
       } else if (Bj >= Ai_1 && Bj <= Ai) {
           return Bj;
       }
       if (Ai < Bj_1) { // the answer can't be within A[0,...,i]
           return select(A+i+1, m-i-1, B, n, j);
       } else { // the answer can't be within A[0,...,i]
           return select(A, m, B+j+1, n-j-1, i);
       }
    }
}