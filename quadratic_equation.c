#include "quadratic_equation.h"

bool solve_equation(double a, double b, double c, double *x)
{	
	double D = b * b - 4 * a * c;
	
	D = sqrt(D);
	
	if(D >= 0 && a != 0)
	{	
		a *= 2;	
		x[0] = (-b + D) / a;
		x[1] = (-b - D) / a;
		return true;
	}	
	return false;
}
