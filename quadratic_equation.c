#include "quadratic_equation.h"

void solve_equation(double a, double b, double c, double *x)
{	
	double D = b * b - 4 * a * c;	
	
	a *= 2;
	if(D >= 0)
	{	
		D = sqrt(D);	
		x[0] = (-b + D) / a;
		x[1] = 0;
		x[2] = (-b - D) / a;
		x[3] = 0;		
	}	
	else
	{	
		D = sqrt(-D);
		x[0] = x[2] = -b / a;
		x[1] = D / a;		
		x[3] = -D / a;
	}
}
