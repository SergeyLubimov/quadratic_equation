/*********************************************************************************

  test_quadratic_equation.c

  The quadratic_equation module provides a tool for solving quadratic equations.

  This file is intended for testing the quadratic_equation module. 
  It presents the main function for running tests presented in 
  the set_of_test.h. The function compares the solutions obtained 
  with the expected values (presented in the set_of_test.h), 
  and outputs the report to the console.


  Date: May 5, 2024
  Version: 1.0
  Modification: May 6, 2024

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
void output_solution(COMPLEXNUM, COMPLEXNUM, bool, double, double, double, COMPLEXNUM, COMPLEXNUM, bool);
bool check_the_solution(COMPLEXNUM, COMPLEXNUM, bool, COMPLEXNUM, COMPLEXNUM, bool);

/*
 * Performs testing of the quadratic_equation module.
 */
int 
main()                 
{      
//getting data from character constants defined in set_of_tests.h
	double tests[NUMBER_OF_TESTS][4] = SET_OF_TESTS;		
	COMPLEXNUM expected_x[NUMBER_OF_TESTS][2] = EXPECTED_RESULT;
	
	bool is_solution_found;
	
	COMPLEXNUM failed_tests[NUMBER_OF_TESTS][3];
	int number_of_failed_tests;
	
	COMPLEXNUM x[2];
	
	printf("Testing has started...\n");
	
	number_of_failed_tests = 0;
	
//performing testing
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d    ", i + 1);		
	
		is_solution_found = solve_equation(tests[i][0], tests[i][1], tests[i][2], x);
	
		if
		( 
//checking the correctness of the completed test
			!(check_the_solution
			(
				x[0], x[1], is_solution_found,
				expected_x[i][0], expected_x[i][1], tests[i][3]
			))
		)
		{
//saving failed tests for a report
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2].re = is_solution_found;
			failed_tests[number_of_failed_tests][2].im = i;
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
			int k = failed_tests[i][2].im;
			output_solution
			( 
  				failed_tests[i][0], failed_tests[i][1], failed_tests[i][2].re,
  				tests[k][0], tests[k][1], tests[k][2], 
  				expected_x[k][0], expected_x[k][1], tests[i][3]
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
  COMPLEXNUM x1, COMPLEXNUM x2, bool is_solution_found,
  double a, double b, double c, 
  COMPLEXNUM expected_x1, COMPLEXNUM expected_x2, bool is_solution
)
{	
	printf("\n\t(a = %f, b = %f, d = %f)\n\tResult:", a, b, c);
	if(is_solution_found) 
		printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.", x1.re, x1.im, x2.re, x2.im);
	else printf("\n\tError: the equation is not square.");
	
	printf("\n\tExpected result:");
	if(is_solution) 
		printf("\n\tx1 = %f + %fi,\n\tx2 = %f + %fi.\n\n", expected_x1.re, expected_x1.im, 
								   expected_x2.re, expected_x2.im); 
	else printf("\n\tAn error was expected."); 
}

/*
 * compares the test results with the expected results
 */ 
bool 
check_the_solution
( 
  COMPLEXNUM x1, COMPLEXNUM x2, bool is_solution_found, 
  COMPLEXNUM expected_x1, COMPLEXNUM expected_x2, bool is_solution
)
{	if(is_solution_found == is_solution)
	{
		if
		(is_solution_found == false || 	
			(
				abs(x1.re - expected_x1.re) < DBL_EPSILON && abs(x1.im - expected_x1.im) < DBL_EPSILON && 
	   			abs(x2.re - expected_x2.re) < DBL_EPSILON && abs(x2.im - expected_x2.im) < DBL_EPSILON
	   		)
	   	) 
			return true;	
	}
	return false;
}
