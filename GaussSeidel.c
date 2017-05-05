/*
 * IMPLEMENTING GAUSS SEIDAL METHOD
 * FOR SOLVING SYSTEM OF LINEAR EQUATION
 *
 * A: CO-EFFICIENT MATRIX
 * B: CONSTANT TERMS
 * X: LIST OF VARIABLES
 * E: EPSILON(MINIMUM DIFFERENCE)
 */

#include <stdio.h>
#include <string.h>
#define ABS(X) (X) > 0 ? (X) : -(X)

void GaussSeidal(int N, double[N][N], double[N], double[N], double);

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
	GaussSeidal(N, A, B, X, 0.01);
	for (int i = 0; i < N || !putchar('\n'); i++)
		printf("x(%d): %.4lf\t", i + 1, X[i]);
	return 0;
}

void GaussSeidal(int N, double A[N][N], double B[N], double X[N], double E) {
	// DEBUG int k = 0;
	int flag;
	double Y[N], sum;
	memset(Y, 0, N * sizeof(double));
	do {
		// DEBUG ++k;
		flag = 0;
		memcpy(X, Y, N * sizeof(double));
		// DEBUG printf("\n%d\n", k);
		for (int i = 0; i < N; i++) {
			sum = 0.0;
			for (int j = 0; j < N; j++)
				(i ^ j) && (sum += A[i][j] * Y[j]);
			Y[i] = (B[i] - sum) / A[i][i];
			// DEBUG printf("x(%d) = %lf\t", i + 1, Y[i]);
		}
		for (int i = 0; i < N || !(flag = 1); i++)
			if (ABS(Y[0] - X[0]) > E)
				break;
	} while (!flag);
}