#include "quadratic_equation.h"

void solve_equation(double a, double b, double c, COMPLEXNUM *x)
{
	COMPLEXNUM sqrt_D[DEGREE_OF_Q_EQ];
	COMPLEXNUM D, cx_a, buff;
	
	D = cxinit(b * b - 4 * a * c);
	cx_a = cxinit(2 * a);
	
	cxsqrt(D, DEGREE_OF_Q_EQ, sqrt_D);	
	
	for(int i = 0; i < DEGREE_OF_Q_EQ; i++)
	{
		
		buff = cxsum(cxinit(-b), sqrt_D[i]);
		x[i] = cxdiv(buff, cx_a);
	}
}
