#include <stdio.h>

double Potencia1(double x, int n){
	if (n == 0) return 1;
	return x*Potencia1(x, n-1);
}

double Potencia2(double x, int n){
	double y;
	if (n == 0) return 1;
	y = Potencia2(x, n/2);
	if (n%2 == 0) return y*y;
	return y*y*x;
}

int main(){
	printf("%.1f\n", Potencia1(4, 5));
	printf("%.1f\n", Potencia2(4, 4));

	return 0;
}