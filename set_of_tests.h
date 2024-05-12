#define NUMBER_OF_TESTS 7

/* Define the test suite in the following format:
  
 #define SET_OF_TESTS										       	  \
{ 													  \
		     |expected_x1  |  |expected_x2  |							  \
  Test 1	{a1, b1, c1, real, imaginary, real, imaginary, (is the equation quadratic, i.e. a != 0)}, \
		...											  \
  Test n	{an, bn, cn, real, imaginary, real, imaginary, (is the equation quadratic, i.e. a != 0)}  \
	
};

*/

#define SET_OF_TESTS					\
{ 							\
/*Test 1*/	{1, -4, 4, 2, 0, 2, 0, true}, 		\
/*Test 2*/	{1, 3, -4, 1, 0, -4, 0, true}, 		\
/*Test 3*/	{1, -2, 10, 1, 3, 1, -3, true},		\
/*Test 4*/	{4, 0, -16, 2, 0, -2, 0, true},		\
/*Test 5*/	{-4, 0, 16, -2, 0, 2, 0, true},		\
/*Test 6*/	{0, 0, 0, 0, 0, 0, 0, false},		\
/*Test 7*/	{4, 0, 16, 0, 2, 0, -2, true}		\
};
