/*
 * IMPLEMENTING REGULA FALSI METHOD
 * FOR APPROXIMATION OF ROOT OF EQUATION
 *
 * F:  GIVEN FUNCTION FOR ROOT
 * dF: DERIVATIVE OF FUNCTION
 * X0: STARTTING VALUE
 * Xn: ENDING VALUE
 * E:  EPSILON(MINIMUM DIFFERENCE)
 */

#include <stdio.h>
#include <math.h>
#define ABS(X) (X) > 0 ? (X) : -(X)

double RegulaFalsi(double F(double), double, double, double);

double f(double p) {
	return (p * exp(p) - cos(p));
}

int main(void) {
	double x = RegulaFalsi(f, 0, 1, 0.001);
	printf("Approximate zero of f(x): %.4lf\n", x);
	return 0;
}

double RegulaFalsi(double F(double), double X0, double Xn, double E) {
	double X, fa, fb, d;
	do {
		fa = F(X0), fb = F(Xn);
		X = (X0 * fb - Xn * fa) / (fb - fa);
		// DEBUG printf("x0 = %lf, xn = %lf, f(x=%lf) = %lf\n", X0, Xn, X, F(X));
		if (F(X) < 0)
			d = X - X0, X0 = X;
		else if (F(X) > 0)
			d = X - Xn, Xn = X;
	} while(ABS(d) > E);
	return X;
}
