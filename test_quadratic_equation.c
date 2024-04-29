#define NUMBER_OF_TESTS 3

#include <stdio.h>
#include <malloc.h>

#include "quadratic_equation.h"

void 
output_solution
( 
  double x1, double x2, bool is_solution_found,
  double a, double b, double c, 
  double expected_x1, double expected_x2, bool is_solution
)
{	
	printf("\n\t(a = %f, b = %f, d = %f)\n\tResult:", a, b, c);
	if(is_solution_found) printf("\n\tx1 = %f,\n\tx2 = %f.", x1, x2);
	else  printf("\n\tThere are no solutions.");
	
	printf("\n\tExpected result:");
	if(is_solution) printf("\n\tx1 = %f,\n\tx2 = %f.\n\n", expected_x1, expected_x2); 
	else printf("\n\tThere are no solutions.\n");
}


bool 
check_the_solution
( 
  double x1, double x2, bool is_solution_found, 
  double expected_x1, double expected_x2, bool is_solution
)
{
	if(is_solution_found == is_solution)
	{
		if(is_solution_found == false || (x1 == expected_x1 && x2 == expected_x2)) 
			return true;
	}
	return false;
}

int 
main()                 
{      
	double test[NUMBER_OF_TESTS][6] =
	{ 
		{1, -4, 4, 2, 2, true}, 
		{1, 3, -4, 1, -4, false}, 
		{1, -5, 9, 0, 0, true}
	};
	double failed_tests[NUMBER_OF_TESTS][4];
	int number_of_failed_tests;
	
	double *x;
	bool is_solution_found;
	
	printf("Testing has started...\n");
	
	x = malloc(2 * sizeof(double));
	number_of_failed_tests = 0;
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d", i + 1);
	
		is_solution_found = solve_equation(test[i][0], test[i][1], test[i][2], x);
		if
		(
			!(check_the_solution
			(
				x[0], x[1], is_solution_found,
				test[i][3], test[i][4], test[i][5]
			))
		)
		{
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2] = is_solution_found;
			failed_tests[number_of_failed_tests][3] = i;
			number_of_failed_tests++;
		}
	}	
	free(x);
	
	printf("\r\n\nTesting is completed.\nTotal tests completed: %d.\n%d tests passed, %d tests failed.\n\n",
		NUMBER_OF_TESTS, NUMBER_OF_TESTS - number_of_failed_tests, number_of_failed_tests);
	printf("Failed tests:");
	for(int i = 0; i < number_of_failed_tests; i++)
	{
		int k = failed_tests[i][3];
		output_solution
		( 
  			failed_tests[i][0], failed_tests[i][1], failed_tests[i][2],
  			test[k][0], test[k][1], test[k][2], 
  			test[k][3], test[k][4], test[k][5]
  		);
	}
	
	return 0;                   
}     
