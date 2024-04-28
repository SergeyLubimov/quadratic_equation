#include "quadratic_equation.h"
#include <stdbool.h>

void output_solution(double a, double b, double c, double expected_x1, double expected_x2, bool is_solution)
{
	double *x;             
	x = solve_equation(a, b, c); 
	
	printf("\n(a = %f, b = %f, d = %f)\nResult:", a, b, c);
	if(x == 0) printf("\nThere are no solutions.");
	else printf("\nx1 = %f,\nx2 = %f.", x[0], x[1]); 
	
	printf("\nExpected result:");
	if(is_solution == false) printf("\nThere are no solutions.\n");
	else printf("\nx1 = %f,\nx2 = %f.\n", expected_x1, expected_x2); 
}

int main()                 
{         
	int number_of_tests = 3;
	double test[3][6] =
	{ 
		{1, -4, 4, 2, 2, 1}, 
		{1, 3, -4, 1, -4, 1}, 
		{1, -5, 9, 0, 0, 0}
	};
	
	for(int i = 0; i < number_of_tests; i++)
		output_solution(test[i][0], test[i][1], test[i][2], 
				test[i][3], test[i][4], test[i][5]);
	
	return 0;                   
}     
