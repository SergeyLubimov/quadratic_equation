/*********************************************************************************

  quadratic_equation.h

  The quadratic_equation module provides a tool for solving quadratic equations.

  This is the header file of the module. 
  Here is the the prototype of a function that finds the real roots 
  of a quadratic equation.


  Date: April 29, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/

#pragma once
#include <math.h>  
#include <stdbool.h> 

/*
 * Solves a quadratic equation of the form ax^2 + bx + c = 0. As a solution, 
 * it returns a two numbers of the double type.
 */
bool solve_equation(double, double, double, double*);
