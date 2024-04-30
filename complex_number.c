/*********************************************************************************

  complex_number.c

  This file constains function definitions for performing basic algebraic operations 
  with complex number and the necessary auxiliary functions.


  Date: April 30, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/

#include "complex_number.h"

#include <stdio.h>

/*
 * Represents a double number as a complex number of type COMPLEXNUM.
 */
COMPLEXNUM cxinit(double a)
{
	COMPLEXNUM result;
	result.re = a;
	result.im = 0;
	
	return result;
}

/*
 * Adds two complex numbers.
 */
COMPLEXNUM cxsum(COMPLEXNUM a, COMPLEXNUM b)
{
	COMPLEXNUM c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

/*
 * Subtraction of complex numbers. 
 * Subtracts the second argument from the first.
 */
COMPLEXNUM cxsub(COMPLEXNUM a, COMPLEXNUM b)
{
	COMPLEXNUM c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

/*
 * Multiplies two complex numbers.
 */
COMPLEXNUM cxmul(COMPLEXNUM a, COMPLEXNUM b)
{
	COMPLEXNUM c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return c;
}

/*
 * Division of complex numbers. 
 * Divides the first argument by the second.
 */
COMPLEXNUM cxdiv(COMPLEXNUM a, COMPLEXNUM b)
{
	COMPLEXNUM c;
	double divider;
	divider = b.re * b.re + b.im * b.im;
	
	c.re = (a.re * b.re + a.im * b.im) / divider;
	c.im = (a.im * b.re - a.re * b.im ) / divider;
	
	return c;
}

/*
 * Raises c to the integer power of a complex number according to the Moivre formula.
 */
COMPLEXNUM cxpow(COMPLEXNUM a, int n)
{	
	COMPLEXNUM result;
	double r, fi;
	int abs_n;
	
	r = cxabs(a);
	fi = cxphase(a);
	
	abs_n = abs(n);
	
	r = pow(r, abs_n); 
	fi *= abs_n;
		
	result.re = r * cos(fi);
	result.im = r * sin(fi);
	
	if(n < 0) 
		result = cxdiv(cxinit(1), result); 
	
	return result;	
}

/*
 * Extracts an integer root from a complex number. 
 * Returns a Boolean value indicating the success of the extraction. 
 * 
 * As the third parameter, the function receives a pointer 
 * to the available memory sufficient for n structures of the COMPLEXNUM   type. 
 * This output parameter is used to return the found n roots.
 */
bool cxsqrt(COMPLEXNUM a, int n, COMPLEXNUM* roots)
{
	if(n == 0) return false;

	double r, fi;
	int abs_n;
	
	r = cxabs(a);
	fi = cxphase(a);
	
	abs_n = abs(n);
	
	r = pow(r, (1. / abs_n));
		
	if(n >= 0)
	{	
		for(int k = 0; k < abs_n; k++)
		{
			roots[k].re = r * cos((fi + 2 * M_PI * k) / abs_n);
			roots[k].im = r * sin((fi + 2 * M_PI * k) / abs_n);
		}
	}
	else
	{
		for(int k = 0; k < abs_n; k++)
		{
			roots[k].re = r * cos((fi + 2 * M_PI * k) / abs_n);
			roots[k].im = r * sin((fi + 2 * M_PI * k) / abs_n);
			roots[k] = cxdiv(cxinit(1), roots[k]);
		}
	}	
	return true;
}

/*
 * Finds the module of a complex number.
 */
double cxabs(COMPLEXNUM a)
{	
	return sqrt(a.re * a.re + a.im * a.im);	
}

/*
 * Finds the phase of a complex number.
 */
double cxphase(COMPLEXNUM a)
{
	double result;
	
	result = atan(a.im / a.re);
	
	if(a.re < 0 && a.im != 0)
	{
		if(a.im > 0) result += M_PI;
		else result -= M_PI;
	}
	return result;
}
