/*********************************************************************************

  test_quadratic_equation.c

  The quadratic_equation module provides a tool for solving quadratic equations.

  This file is intended for testing the quadratic_equation module. 
  It presents the main function for running tests presented in 
  the set_of_test.h file. The function compares the solutions obtained 
  with the expected values (presented in the set_of_test file.h), 
  and outputs the report to the console.


  Date: May 5, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/

#include "quadratic_equation.h"
#include "set_of_tests.h"

#include <stdio.h>
#include <float.h>

/*
 * Prototypes of auxiliary functions. 
 * The definitions are provided at the end of this file.
 */
void output_solution(COMPLEXNUM, COMPLEXNUM, double, double, double, COMPLEXNUM, COMPLEXNUM);
bool check_the_solution(COMPLEXNUM, COMPLEXNUM, COMPLEXNUM, COMPLEXNUM);

/*
 * Performs testing of the quadratic_equation module.
 */
int 
main()                 
{      
//getting data from character constants defined in set_of_tests.h
	double coef_test[NUMBER_OF_TESTS][3] = SET_OF_COEFFICIENTS;		
	COMPLEXNUM expected_x[NUMBER_OF_TESTS][2] = EXPECTED_RESULT;
	
	COMPLEXNUM failed_tests[NUMBER_OF_TESTS][3];
	int number_of_failed_tests;
	
	COMPLEXNUM x[2];
	
	printf("Testing has started...\n");
	
	number_of_failed_tests = 0;
	
//performing testing
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d    ", i + 1);		
	
		solve_equation(coef_test[i][0], coef_test[i][1], coef_test[i][2], x);
	
		if
		(
//checking the correctness of the completed test
			!(check_the_solution
			(
				x[0], x[1],
				expected_x[i][0], expected_x[i][1]
			))
		)
		{
//saving failed tests for a report
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2].re = i;
			number_of_failed_tests++;
		}
	}
	
//output of the test report
	printf("\r\n\nTesting is completed.\nTotal tests completed: %d.\n%d tests passed, %d tests failed.\n\n",
		NUMBER_OF_TESTS, NUMBER_OF_TESTS - number_of_failed_tests, number_of_failed_tests);
		
//output of a detailed report on failed tests		
	if(number_of_failed_tests > 0)
	{
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
	}
	return 0;                   
}    

/*
 * output details about a single test
 */
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

/*
 * compares the test results with the expected results
 */ 
bool 
check_the_solution
( 
  COMPLEXNUM x1, COMPLEXNUM x2,
  COMPLEXNUM expected_x1, COMPLEXNUM expected_x2
)
{	
	if(abs(x1.re) - abs(expected_x1.re) < DBL_EPSILON && abs(x1.im) - abs(expected_x1.im) < DBL_EPSILON && 
	   abs(x2.re) - abs(expected_x2.re) < DBL_EPSILON && abs(x2.im) - abs(expected_x2.im) < DBL_EPSILON) 
		return true;	
	return false;
}
