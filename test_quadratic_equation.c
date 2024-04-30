#define NUMBER_OF_TESTS 3

#include <stdio.h>
#include <malloc.h>

#include "quadratic_equation.h"

void 
output_solution
( 
  double r_x1, double i_x1, double r_x2, double i_x2,
  double a, double b, double c, 
  double expected_r_x1, double expected_i_x1, double expected_r_x2, double expected_i_x2
)
{	
	printf("\n\t(a = %f, b = %f, d = %f)\n\tResult:", a, b, c);
	printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.", r_x1, i_x1, r_x2, i_x2);
		
	printf("\n\tExpected result:");
	printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.\n\n", expected_r_x1, expected_i_x1,
							   expected_r_x2, expected_i_x2); 
}


bool 
check_the_solution
( 
  double r_x1, double i_x1, double r_x2, double i_x2, 
  double expected_r_x1, double expected_i_x1, double expected_r_x2, double expected_i_x2
)
{	
	if
	(
		r_x1 == expected_r_x1 && i_x1 == expected_i_x1 &&
		r_x2 == expected_r_x2 && i_x2 == expected_i_x2		
	) 
	{return true;}
	
	return false;	
}

int 
main()                 
{      
	double test[NUMBER_OF_TESTS][7] =
	{ 
		{1, -4, 4, 2, 0, 2, 0}, 
		{1, 3, -4, 1, 0, -4, 0}, 
		{1, -2, 10, 1, 3, 1, -3}
	};
	double failed_tests[NUMBER_OF_TESTS][5];
	int number_of_failed_tests;
	
	double *x;
		
	printf("Testing has started...\n");
	
	x = malloc(4 * sizeof(double));
	number_of_failed_tests = 0;
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d", i + 1);
	
		solve_equation(test[i][0], test[i][1], test[i][2], x);
		if
		(
			!(check_the_solution
			(
				x[0], x[1], x[2], x[3],
				test[i][3], test[i][4], test[i][5], test[i][6]
			))
		)
		{
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2] = x[2];
			failed_tests[number_of_failed_tests][3] = x[3];
			failed_tests[number_of_failed_tests][4] = i;
			number_of_failed_tests++;
		}
	}	
	free(x);
	
	printf("\r\n\nTesting is completed.\nTotal tests completed: %d.\n%d tests passed, %d tests failed.\n\n",
		NUMBER_OF_TESTS, NUMBER_OF_TESTS - number_of_failed_tests, number_of_failed_tests);
	printf("Failed tests:");
	for(int i = 0; i < number_of_failed_tests; i++)
	{
		int k = failed_tests[i][4];
		output_solution
		( 
  			failed_tests[i][0], failed_tests[i][1], failed_tests[i][2], failed_tests[i][3],
  			test[k][0], test[k][1], test[k][2], 
  			test[k][3], test[k][4], test[k][5], test[k][6]
  		);
	}
	
	return 0;                   
}     
