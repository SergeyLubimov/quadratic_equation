/*********************************************************************************

  test_quadratic_equation.c

  The quadratic_equation module provides a tool for solving quadratic equations.

  This file is intended for testing the quadratic_equation module. 
  It presents the main function for running tests presented in 
  the set_of_test.h file. The function compares the solutions obtained 
  with the expected values (presented in the set_of_test.h), 
  and outputs the report to the console.


  Date: April 29, 2024
  Version: 1.0

  Author: Lyubimov Sergey M.
*********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "quadratic_equation.h"
#include "set_of_tests.h"

/*
 * Prototypes of auxiliary functions. 
 * The definitions are provided at the end of this file.
 */
void output_solution(double x1, double x2, bool is_solution_found, double a, double b, double c, double expected_x1, double expected_x2, bool is_solution);
bool check_the_solution(double x1, double x2, bool is_solution_found, double expected_x1, double expected_x2, bool is_solution);

/*
 * Performs testing of the quadratic_equation module.
 */
int 
main()                 
{      
//performing testing
	double test[NUMBER_OF_TESTS][6] = SET_OF_TESTS;
	
	double failed_tests[NUMBER_OF_TESTS][4];
	int number_of_failed_tests;
	
	double x[2];
	bool is_solution_found;
	
	printf("Testing has started...\n");
	
	number_of_failed_tests = 0;
	for(int i = 0; i < NUMBER_OF_TESTS; i++)
	{
		printf("\rCurrent test: %d", i + 1);
	
		is_solution_found = solve_equation(test[i][0], test[i][1], test[i][2], x);
		if
		(
//checking the correctness of the completed test
			!(check_the_solution
			(
				x[0], x[1], is_solution_found,
				test[i][3], test[i][4], test[i][5]
			))
		)
		{
//saving failed tests for a report
			failed_tests[number_of_failed_tests][0] = x[0];
			failed_tests[number_of_failed_tests][1] = x[1];
			failed_tests[number_of_failed_tests][2] = is_solution_found;
			failed_tests[number_of_failed_tests][3] = i;
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
			int k = failed_tests[i][3];
			output_solution
			( 
  				failed_tests[i][0], failed_tests[i][1], failed_tests[i][2],
  				test[k][0], test[k][1], test[k][2], 
  				test[k][3], test[k][4], test[k][5]
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

/*
 * compares the test results with the expected results
 */ 
bool 
check_the_solution
( 
  double x1, double x2, bool is_solution_found, 
  double expected_x1, double expected_x2, bool is_solution
)
{
	if(is_solution_found == is_solution)
	{
		if(is_solution_found == false || (abs(x1 - expected_x1) < DBL_EPSILON && abs(x2 - expected_x2) < DBL_EPSILON)) 
			return true;
	}
	return false;
} 
