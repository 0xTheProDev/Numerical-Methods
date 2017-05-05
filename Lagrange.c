/*
 * IMPLEMENTING LAGRANGE INTERPOLATION
 *
 * X: DOMAIN OF THE FUNCTION
 * Y: RANGE OF THE FUNCTION
 * x: USER GIVEN X-VALUE
 */

#include <stdio.h>

double Lagrange(double, int, double[], double[]);

int main(void)
{
	int N;
	puts("Enter number of terms: ");
	scanf("%d", &N);
	double x, X[N], Y[N];
	for (int i = 0; i < N; i++)  {
		printf("Enter X[%d] = ", i + 1);
		scanf("%lf", X + i);
		printf("Enter Y[%d] = ", i + 1);
		scanf("%lf", Y + i);
	}
	printf("Please enter the value of x(unknown): ");
	scanf("%lf", &x);
	printf("Value of y: %lf\n", Lagrange(x, N, X, Y));
	return 0;
}

double Lagrange(double x, int N, double X[N], double Y[N])
{
	double sum = 0, product;
	for (int i = 0; i < N; i++) {
		product = 1;
		for (int j = 0; j < N; j++)
			(i ^ j) && (product *= (x - X[j]) / (X[i] - X[j]));
		sum += product * Y[i];
	}
	return sum;
}