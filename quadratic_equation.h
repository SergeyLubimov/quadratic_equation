/***********************************************************************************

  quadratic_equation.h

  The quadratic_equation module provides a tool for solving quadratic equations.

  This is the header file of the module version that takes into account 
  complex solutions of the quadratic equation. Here is the prototype of the function 
  that finds the complex roots of the quadratic equation.

  Date: April 30, 2024
  Version: 1.0
  Modification: May 12, 2024

  Author: Lyubimov Sergey M.
***********************************************************************************/

#pragma once

#include <math.h>  
#include <stdbool.h> 

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. 
 * As a solution, it returns a pair of complex numbers, 
 * placing them in an array of type double.
 */
bool solve_equation(double, double, double, double*);
