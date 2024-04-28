#include "quadratic_equation.h"

double* solve_equation(double a, double b, double c)
{	
	double *x = 0;
	double D = b * b - 4 * a * c;
	
	if(D >= 0)
	{
		x = malloc(2 * sizeof(double));
		x[0] = (-b + sqrt(D)) / (2 * a);
		x[1] = (-b - sqrt(D)) / (2 * a);
	}	
	return x;
}
