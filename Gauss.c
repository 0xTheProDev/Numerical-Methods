/*
 * IMPLEMENTING GAUSSIAN ELIMINATION METHOD
 * FOR SOLVING SYSTEM OF LINEAR EQUATION
 *
 * A: CO-EFFICIENT MATRIX
 * B: CONSTANT TERMS
 * X: LIST OF VARIABLES
 */

#include <stdio.h>

void Gauss(int N, double[N][N], double[N], double[N]);

int main(void) {
	int N;
	printf("Enter the number of variables: ");
	scanf("%d", &N);
	double A[N][N], B[N], X[N];
	for (int i = 0, j = 0; j < N || (j = 0, ++i) < N; j++){
		printf("Enter co-efficient a(%d, %d): ", i + 1, j + 1);
		scanf("%lf", &A[i][j]);
	}
	for (int i = 0; i < N; i++){
		printf("Enter constant b(%d): ", i + 1);
		scanf("%lf", B + i);
	}
	Gauss(N, A, B, X);
	for (int i = 0; i < N || !putchar('\n'); i++)
		printf("x(%d): %.4lf\t", i + 1, X[i]);
	return 0;
}

void Gauss(int N, double A[N][N], double B[N], double X[N]) {
	double mul, sum;
	for (int j = 0; j < N; j++)
		for (int i = j + 1; i < N; i++) {
			mul = -(A[i][j] / A[j][j]);
			for (int k = j; k < N; k++)
				A[i][k] += mul * A[j][k];
			B[i] += mul * B[j];
		}
	for (int j = N - 1; j > 0; j--)
		for (int i = j - 1; i >= 0; i--) {
			mul = -(A[i][j] / A[j][j]);
			for (int k = j; k < N; k++)
				A[i][k] += mul * A[j][k];
			B[i] += mul * B[j];
		}
	for (int i = 0; i < N; i++)
		X[i] = B[i] / A[i][i];
}