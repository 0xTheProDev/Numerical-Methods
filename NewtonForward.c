/*
 * IMPLEMENTING NEWTON FORWARD INTERPOLATION
 *
 * X: DOMAIN OF THE FUNCTION
 * Y: RANGE OF THE FUNCTION
 * x: USER GIVEN X-VALUE
 */

#include <stdio.h>

double NewtonFI(int N, double X[N], double Y[N], double);

int main(void) {
	int N;
	printf("Enter the number of terms: ");
	scanf("%d", &N);
	double x[N], y[N], u;
	for (int i = 0; i < N; i++) {
		printf("Enter x[%d]: ", i + 1);
		scanf("%lf", x + i);
		printf("Enter y[%d]: ", i + 1);
		scanf("%lf", y + i);
	}
	printf("Enter the value of x(unknown): ");
	scanf("%lf", &u);
	double v = NewtonFI(N, x, y, u);
	printf("Newton Forward Interpolation:\nf(%.4lf) = %.4lf\n", u, v);
	return 0;
}

double NewtonFI(int N, double X[N], double Y[N], double x) {
	double h = X[1] - X[0], r = (x - X[0]) / h, prod = 1, y = Y[0];
	for(int i = 1; i < (N - 1); i++)
	{
		for(int j = 0; j < (N - 1); j++)
			Y[j] = Y[j + 1] - Y[j];
		prod = prod * (r - i + 1) / i;
		y += prod * Y[0];
	}
	return y;
}