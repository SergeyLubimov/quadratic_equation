/*********************************************************************************

  quadratic_equation.h

  The quadratic_equation module provides a tool for solving quadratic equations.

  This is the header file of the module version using complex numbers. Here is 
  a prototype of a function that uses the COMPLEXNUM data type and tools 
  for working with it, which are presented in the complex_number module, 
  to solve a quadratic equation.


  Date: May 5, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/

#pragma once

#define DEGREE_OF_Q_EQ 2

#include "complex_number/complex_number.h"

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. As a solution, 
 * it returns a pair of complex numbers of the COMPLEXNUM type.
 */
void solve_equation(double, double, double, COMPLEXNUM*);
