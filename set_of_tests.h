#define NUMBER_OF_TESTS 7

/* Define the test suite in the following format:
  
 #define SET_OF_TESTS								    	\
{ 											\
  Test 1	{a1, b1, c1, expected_x1, expected_x2, (is there a real solution)}, 	\
		...								 	\
  Test n	{an, bn, cn, expected_x1, expected_x2, (is there a real solution)} 	\
	
};

*/

#define SET_OF_TESTS  				\
{ 						\
		{1, -4, 4, 2, 2, true}, 	\
		{1, 3, -4, 1, -4, true}, 	\
		{1, -5, 9, 0, 0, false},	\
		{4, 0, -16, 2, -2, true},	\
		{-4, 0, 16, -2, 2, true},	\
		{0, 0, 0, 0, 0, false},		\
		{4, 0, 16, 0, 0, false}	  	\
}


