/*
 * IMPLEMENTATION OF EULER METHOD
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

double Euler(const double x0, const double y0, const double xn, const double h, double F(double, double)){
	double y = y0;
	for (double x = x0; x <= xn; x += h)
		y += h * F(x, y);
	return y;
}

// User-defined functions
double func(const double x, const double y){
	return x * y;
}
int main(void){
	printf("Euler: y = %g\n", Euler(1, 2, 1.4, 0.1, func));
	return 0;
}
