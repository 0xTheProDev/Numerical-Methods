/*
 * IMPLEMENTING NEWTON RAPHSON METHOD
 * FOR APPROXIMATION OF ROOT OF EQUATION
 *
 * F:  GIVEN FUNCTION FOR ROOT
 * dF: DERIVATIVE OF FUNCTION
 * X0: STARTTING VALUE
 * E:  EPSILON(MINIMUM DIFFERENCE)
 */

#include <stdio.h>
#include <math.h>
#define ABS(X) (X) > 0 ? (X) : -(X)

double NewtonRaphson(double F(double), double dF(double), double, double);

double f(double p) {
	return (p * exp(p) - cos(p));
}

double df(double p) {
	return ((p + 1) * exp(p) + sin(p));
}

int main(void) {
	double x = NewtonRaphson(f, df, 5, 0.001);
	printf("Approximate zero of f(x): %.4lf\n", x);
	return 0;
}

double NewtonRaphson(double F(double), double dF(double), double X0, double E) {
	double X1 = X0, X2;
	while (ABS(X2 - X1) > E) {
		X1 = X2;
		X2 = X1 - F(X1) / dF(X1);
		// DEBUG printf("x0 = %lf, x = %lf, f(x) = %lf\n", X1, X2, F(X2));
	}
	return X1;
}
