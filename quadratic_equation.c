/*********************************************************************************

  quadratic_equation.c

  The quadratic_equation module provides a tool for solving quadratic equations.
  
  This is the source file of the module version using complex numbers. 
  Here is the definition of a function for solving quadratic equations.
  

  Date: May 5, 2024
  Version: 1.0
  Modification: May 6, 2024

  Author: Lyubimov Sergey M.
*********************************************************************************/

#include "quadratic_equation.h"

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. 
 * 
 * It takes as arguments a, b, c the coefficients of the equation and
 * a pointer to the memory area where the result should be placed. 
 * The pointer should lead to a memory area sufficient 
 * for two structures of the COMPLEXNUM type. 
 * 
 * The result will be presented as two complex numbers of the COMPLEXNUM type.
 */
bool solve_equation(double a, double b, double c, COMPLEXNUM *x)
{
	COMPLEXNUM sqrt_D[DEGREE_OF_Q_EQ];
	COMPLEXNUM D, cx_a, buff;
	
	if(a == 0) return false;
	
	D = cxinit(b * b - 4 * a * c);
	cx_a = cxinit(2 * a);
	
	cxsqrt(D, DEGREE_OF_Q_EQ, sqrt_D);	
	
	for(int i = 0; i < DEGREE_OF_Q_EQ; i++)
	{
		
		buff = cxsum(cxinit(-b), sqrt_D[i]);
		x[i] = cxdiv(buff, cx_a);
	}
	return true;
}
