/***********************************************************************************

  quadratic_equation.h

  The quadratic_equation module provides a tool for solving quadratic equations.

  This is the header file of the module. Here is the the definition of a function 
  that finds the real roots of a quadratic equation.

  Date: April 29, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
***********************************************************************************/

#include "quadratic_equation.h"

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. 
 * 
 * It takes as arguments a, b, c the coefficients of the equation and
 * a pointer to the memory area where the result should be placed. 
 * The pointer must lead to a memory area sufficient
 * for two double numbers.
 * 
 * The result will be presented as two numbers in a array of the double type in the format: 
 * {x1, x2}.
 */
bool 
solve_equation(double a, double b, double c, double *x)
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
