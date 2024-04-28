#include "quadratic_equation.h"

int main()                 
{         
	double *x;             
	x = solve_equation(1, -4, 4); 
	if(x == 0) printf("\nThere are no solutions.\n");
	else printf("\nx1 = %f,\nx2 = %f.\n", x[0], x[1]); 
	return 0;                   
}     
