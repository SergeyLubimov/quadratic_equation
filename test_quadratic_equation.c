#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <float.h>

#include "quadratic_equation.h"
#include "set_of_tests.h"

void 
output_solution
(
	double *x, bool is_solution_found, 
	double a, double b, double c, 
	double *expected_x, bool is_solution
)
{	
	printf("\n\t(a = %f, b = %f, d = %f)\n\tResult:", a, b, c);
	if(is_solution_found)
		printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.", x[0], x[1], x[2], x[3]);
	else printf("\n\tError: the equation is not square.");
		
	printf("\n\tExpected result:");
	if(is_solution)
		printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.\n\n", expected_x[0], expected_x[1],
							 	   expected_x[2], expected_x[3]); 
	else printf("\n\tAn error was expected.");
}


bool 
check_the_solution
(double *x, bool is_solution_found, double *expexted_x, bool is_solution)
{	
	if(is_solution_found == is_solution)
	{
		if
		(is_solution_found == false ||
			(
				abs(x[0]) - abs(expexted_x[0]) < DBL_EPSILON && abs(x[1]) - abs(expexted_x[1]) < DBL_EPSILON &&
				abs(x[2]) - abs(expexted_x[2]) < DBL_EPSILON && abs(x[3]) - abs(expexted_x[3]) < DBL_EPSILON
			)		
		) 
		return true;
	}		
	
	return false;	
}

int 
main()                 
{      
	double test[NUMBER_OF_TESTS][8] = SET_OF_TESTS;
	
	bool is_solution_found;
	
	double failed_tests[NUMBER_OF_TESTS][6];
	int number_of_failed_tests;
	
	double *x;
		
	printf("Testing has started...\n");
	
	x = malloc(4 * sizeof(double));
	number_of_failed_tests = 0;
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d", i + 1);
	
		is_solution_found = solve_equation(test[i][0], test[i][1], test[i][2], x);
		
		if(!(check_the_solution(x, is_solution_found, &(test[i][3]), test[i][7])))
		{
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2] = x[2];
			failed_tests[number_of_failed_tests][3] = x[3];
			failed_tests[number_of_failed_tests][4] = is_solution_found;
			failed_tests[number_of_failed_tests][5] = i;
			number_of_failed_tests++;
		}
	}	
	free(x);
	
	printf("\r\n\nTesting is completed.\nTotal tests completed: %d.\n%d tests passed, %d tests failed.\n\n",
		NUMBER_OF_TESTS, NUMBER_OF_TESTS - number_of_failed_tests, number_of_failed_tests);
		
	if(number_of_failed_tests) 
		printf("Failed tests:");
	
	for(int i = 0; i < number_of_failed_tests; i++)
	{
		int k = failed_tests[i][4];
		output_solution
		( 
  			&(failed_tests[i][0]), failed_tests[i][4],
  			test[k][0], test[k][1], test[k][2], 
  			&(test[k][3]), test[i][7]
  		);
	}
	
	return 0;                   
}     
