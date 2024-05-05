compiler = gcc
compilation_flags = -Wall 

check: test_quadratic_equation
	@./test_quadratic_equation
	@rm -f test_quadratic_equation

test_quadratic_equation: test_quadratic_equation.c quadratic_equation.c complex_number/complex_number.c
	@$(compiler) $(compilation_flags) -o test_quadratic_equation test_quadratic_equation.c quadratic_equation.c complex_number/complex_number.c -lm	
	

