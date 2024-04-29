#include "quadratic_equation.h"

bool solve_equation(double a, double b, double c, double *x)
{	
	double D = b * b - 4 * a * c;
	
	if(D >= 0)
	{		
		x[0] = (-b + sqrt(D)) / (2 * a);
		x[1] = (-b - sqrt(D)) / (2 * a);
		return true;
	}	
	return false;
}
