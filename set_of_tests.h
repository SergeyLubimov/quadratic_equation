#define NUMBER_OF_TESTS 3

/* Define the test suite in the following format:

#define SET_OF_COEFFICIENTS		\
{ 					\
  Test 1	{a1, b1, c1}, 		\
		...
  Test n	{an, bn, cn}		\
};

*/
   
#define SET_OF_COEFFICIENTS		\
{ 					\
/*Test 1*/	{1, -4, 4}, 		\
/*Test 2*/	{1, 3, -4},		\
/*Test 3*/	{1, -2, 10}		\
};



/* Define the expected test results in the following format:

#define EXPECTED_RESULT 				\
{							\
		 expected_x1 	    expected_x2		\
  Results 1	{{real, imaginary}, {real, imaginary}},	\
		...					\
  Results n	{{real, imaginary}, {real, imaginary}},	\		
};

*/
	
#define EXPECTED_RESULT 		\
{					\
/*Results 1*/	{{2, 0}, {2, 0}},	\
/*Results 2*/	{{1, 0}, {-4, 0}},	\
/*Results 3*/	{{1, 3}, {1, -3}}	\
};
	

