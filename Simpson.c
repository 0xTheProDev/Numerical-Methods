/*
 * IMPLEMENTATION OF SIMPSON 1/3RD RULE
 * FOR CALCULATING AREA UNDER CURVE
 *
 * f : USER GIVEN FUNCTION
 * a : LOWER LIMIT OF INTIGRATION
 * b : UPPER LIMIT OF INTIGRATION
 * h : FIXED DIFFERENCE IN INTERVAL (LIMIT -> 0)
 * n : FIXED NUMBER OF INTERVAL (LIMIT --> infinity)
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

typedef double F(double);

double simpson(double, double, F);

// User-defined Function
double func(double a){
	return sqrt(sin(a));
}

int main(void){
	double a = 0, b = PI / 2;
	double area = simpson(a, b, func);
	printf("Area: %g\n", area);
	return 0;
}

// Function calculating Area by SIMPSON 1/3RD RULE
double simpson(const double a, const double b, F f){
	if (a >= b)
		return 0.0;
	const int n = 100;
	const double h = (b - a) / n;
	double sum = f(a) + f(b);
	for(int i = 1; i < n; i++)
		sum += i & 1 ? 4 * f(a + i * h) : 2 * f(a + i * h);
	return (sum * h / 3);
}
