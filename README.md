Quadratic Equation 
=====================================

The module is designed to solve quadratic equations of the form ax^2+bx+c=0. 
It contains a solve_equation function that accepts three real numbers - coefficients a, b, c. 
The return of the solution depends on the version of the module.

In this repository, three versions of the module are presented in different branches.

### Basic version (master)
This is the master branch. The basic version of the module finds only the real roots of 
the equation. With a negative discriminant, it is assumed that there are no roots. 
The solve_equation function represents the solution as an array containing two double numbers: 
{x1, x2}.

### Version with a Complex Solution (VCS)
This is the VCS branch. This version takes into account the complex roots of the equation. 
The solve_equation function represents the solution as a one-dimensional array, 
as four double numbers in the format: 
{real part x1, imaginary part x1, real part x2, imaginary part x2}. 

### Version with Complex Numbers (VCN)
This is the VCN branch. This version finds the complex roots of the quadratic equation. 
The solve_equation function works using tools for working with the complex numbers of 
the cumplex_number module (located in the repository of this branch). 
The solve_equation function represents the solution as an array of two structures 
of the COMPLEX NUM type defined in cumplex_number.h.
