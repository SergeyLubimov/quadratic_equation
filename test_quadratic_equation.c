#define NUMBER_OF_TESTS 3

#include <stdio.h>
#include <malloc.h>

#include "quadratic_equation.h"

void 
output_solution
( 
  COMPLEXNUM x1, COMPLEXNUM x2,
  double a, double b, double c, 
  COMPLEXNUM expected_x1, COMPLEXNUM expected_x2
)
{	
	printf("\n\t(a = %f, b = %f, d = %f)\n\tResult:", a, b, c);
	printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.", x1.re, x1.im, x2.re, x2.im);
	
	printf("\n\tExpected result:");
	printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.\n\n", expected_x1.re, expected_x1.im, 
							   expected_x2.re, expected_x2.im); 	
}

bool 
check_the_solution
( 
  COMPLEXNUM x1, COMPLEXNUM x2,
  COMPLEXNUM expected_x1, COMPLEXNUM expected_x2
)
{	
	if(abs(x1.re) - abs(expected_x1.re) < DBL_EPSILON && abs(x1.im) - abs(expected_x1.im) < DBL_EPSILON && 
	   abs(x2.re) - abs(expected_x2.re) < DBL_EPSILON && abs(x2.im - expected_x2.im) < DBL_EPSILON) 
		return true;	
	return false;
}

int 
main()                 
{      
	double coef_test[NUMBER_OF_TESTS][3] =
	{ 
		{1, -4, 4}, 
		{1, 3, -4},
		{1, -2, 10}
	};
	
	COMPLEXNUM expected_x[NUMBER_OF_TESTS][2] = 
	{
		{{2, 0}, {2, 0}},
		{{1, 0}, {-4, 0}},
		{{1, 3}, {1, -3}}
	};
	
	COMPLEXNUM failed_tests[NUMBER_OF_TESTS][3];
	int number_of_failed_tests;
	
	COMPLEXNUM *x;
	
	printf("Testing has started...\n");
	
	x = malloc(2 * sizeof(COMPLEXNUM));	
	
	number_of_failed_tests = 0;
	
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d    ", i + 1);		
	
		solve_equation(coef_test[i][0], coef_test[i][1], coef_test[i][2], x);
	
		if
		(
			!(check_the_solution
			(
				x[0], x[1],
				expected_x[i][0], expected_x[i][1]
			))
		)
		{
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2].re = i;
			number_of_failed_tests++;
		}
	}	
	free(x);
	
	printf("\r\n\nTesting is completed.\nTotal tests completed: %d.\n%d tests passed, %d tests failed.\n\n",
		NUMBER_OF_TESTS, NUMBER_OF_TESTS - number_of_failed_tests, number_of_failed_tests);
		
	if(number_of_failed_tests > 0)
		printf("Failed tests:");
		
	for(int i = 0; i < number_of_failed_tests; i++)
	{
		int k = failed_tests[i][2].re;
		output_solution
		( 
  			failed_tests[i][0], failed_tests[i][1],
  			coef_test[k][0], coef_test[k][1], coef_test[k][2], 
  			expected_x[k][0], expected_x[k][1]
  		);
	}
	
	return 0;                   
}     
