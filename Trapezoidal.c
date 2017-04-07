/*
 * IMPLEMENTATION OF TRAPEZOIDAL RULE
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

#define PI 3.14159265359

// Function calculating Area by Trapezoidal Rule
static double trap(double f(double), const double a, const double b)
{
	if (a >= b)
		return 0.0;
	const double h = 0.01;
	const unsigned long long n = ceil((b - a) / h);
	double area = f(a) + f(b), t = a;
	unsigned long long i = 1;
	while (i < n){
			t += h;
			if(t >= b)
					break;
			area += 2 * f(t);
	}
	return 0.5 * area * h;
}

// User-defined Function
double F(double x)
{
	return (sqrt(sin(x)));
}

int main(void) {
	double a = 0, b = PI / 2;
	double I = trap(F, a, b);
	printf("Area: %g\n", I);
	return 0;
}

