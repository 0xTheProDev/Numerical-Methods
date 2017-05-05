/*
 * IMPLEMENTING BISECTION METHOD
 * FOR APPROXIMATION OF ROOT OF EQUATION
 *
 * F:  GIVEN FUNCTION FOR ROOT
 * X0: MINIMUM VALUE
 * Xn: MAXIMUM VALUE
 * E:  EPSILON(MINIMUM DIFFERENCE)
 */

#include <stdio.h>
#include <math.h>
#define ABS(X) (X) > 0 ? (X) : -(X)

double Bisection(double F(double), double, double, double);

double f(double p) {
	return (p * exp(p) - cos(p));
}

int main(void) {
	double x = Bisection(f, -2, 3, 0.001);
	printf("Approximate zero of f(x): %.4lf\n", x);
	return 0;
}

double Bisection(double F(double), double X0, double Xn, double E) {
	double X, f;
	while (1) {
		X = (X0 + Xn) / 2;
		f = F(X);
		// DEBUG printf("x0 = %lf, xn = %lf, f(x = %lf) = %lf\n", X0, Xn, X, f);
		if (f > E)
			Xn = X;
		else if (f < -E)
			X0 = X;
		else
			return X;
	}
}
