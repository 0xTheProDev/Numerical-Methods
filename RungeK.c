/*
 * IMPLEMENTATION OF RUNGE KUTTA METHOD
 * FOR CALCULATING FUNCTIONAL VALUE
 * WHEN DERIVATIVE (SLOPE) AND A VALUE GIVEN
 *
 * F  : USER GIVEN FUNCTION DERIVATIVE
 * x0 : LOWER LIMIT OF INTIGRATION
 * y0 : FUNCTIONAL VALUE AT x0
 * xn : UPPER LIMIT OF INTIGRATION
 * h  : FIXED DIFFERENCE IN INTERVAL (LIMIT -> 0)
 * n  : FIXED NUMBER OF INTERVAL (LIMIT --> infinity)
 */

#include <stdio.h>

double RungeK(const double x0, const double y0, const double xn, const double h, double F(double, double)){
	double y = y0, k1, k2, k3, k4, k;
	for (double x = x0; x <= xn; x += h){
		k1 = h * F(x, y);
		k2 = h * F(x + h / 2, y + k1 / 2);
		k3 = h * F(x + h / 2, y + k2 / 2);
		k4 = h * F(x + h, y + k3);
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y += k;
	}
	return y;
}

// User defined functions
double func(const double x, const double y){
	return x * y;
}

int main(void){
	printf("RungeK: y = %g\n", RungeK(1, 2, 1.4, 0.1, func));
	return 0;
}
