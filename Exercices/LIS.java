import java.util.Arrays; 

public class LIS{
	
	public static int LIS_Length(Integer[] X){
		int n = X.length;
		Integer[] Y = new Integer[n];
		for(int k = 0; k < n; k++){
			Y[k] = X[k];
		}
		Arrays.sort(Y);
		int[][] c = new int[n+1][n+1];
		int i, j;

		for(i = 0; i < n; i++){
			c[i][0] = 0;
			c[0][i] = 0;
		}

		for(i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				if (X[i] == Y[j]){
					c[i][j] = c[i-1][j-1] + 1;
				}
				else if (c[i-1][j] >= c[i][j-1]){
					c[i][j] = c[i-1][j];
				}
				else{
					c[i][j] = c[i][j-1];
				}
			}
		}

		return c[n][n];

	}

	public static void main(String[] args){
		Integer[] X = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
		System.out.println(LIS_Length(X));
	}
}