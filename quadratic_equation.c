#include "quadratic_equation.h"

bool solve_equation(double a, double b, double c, double *x)
{	
	double D = b * b - 4 * a * c;
	
	D = sqrt(D);
	a *= 2;
	if(D >= 0)
	{		
		x[0] = (-b + D) / a;
		x[1] = (-b - D) / a;
		return true;
	}	
	return false;
}
