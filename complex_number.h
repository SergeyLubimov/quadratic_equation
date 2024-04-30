/*********************************************************************************

  complex_number.h

  This file constains the definition of the data type structure - complex numbers, 
  as well as function prototypes for performing basic algebraic operations 
  with this data type and the necessary auxiliary functions.


  Date: April 30, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/
 
#pragma once

/*
 * Defining the type of complex numbers
 */
typedef struct
{
    double re;		// real part
    double im;		// imaginary part
} COMPLEXNUM;

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * prototypes for functions in complex_number.c
 */
COMPLEXNUM cxinit(double);

COMPLEXNUM cxsum(COMPLEXNUM a, COMPLEXNUM b);

COMPLEXNUM cxsum(COMPLEXNUM a, COMPLEXNUM b);

COMPLEXNUM cxsub(COMPLEXNUM, COMPLEXNUM);

COMPLEXNUM cxmul(COMPLEXNUM, COMPLEXNUM);

COMPLEXNUM cxdiv(COMPLEXNUM, COMPLEXNUM);

COMPLEXNUM cxpow(COMPLEXNUM, int);

bool cxsqrt(COMPLEXNUM, int, COMPLEXNUM*);

double cxabs(COMPLEXNUM);

double cxphase(COMPLEXNUM);
