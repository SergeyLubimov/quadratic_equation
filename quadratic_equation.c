/*********************************************************************************

  quadratic_equation.c

  The quadratic_equation module provides a tool for solving quadratic equations.
  
  This is the source file of the module version that takes into account 
  complex solutions of the quadratic equation. 
  Here is the definition of the function for solving quadratic equations.
  

  Date: April 30, 2024
  Version: 1.0
  Modification: May 12, 2024

  Author: Lyubimov Sergey M.
*********************************************************************************/

#include "quadratic_equation.h"

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. 
 * 
 * It takes as arguments a, b, c the coefficients of the equation and
 * a pointer to the memory area where the result should be placed. 
 * The pointer must lead to a memory area sufficient
 * for four double numbers.
 * 
 * The result will be presented as two complex numbers in a double array in the format: 
 * {real, imaginary, real, imaginary}.
 */
bool 
solve_equation(double a, double b, double c, double *x)
{	
	double D = b * b - 4 * a * c;	
	
	if(a == 0) return false;
	
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
	return true;
}
