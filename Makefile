compiler = gcc
compilation_flags = -Wall 

compil: quadratic_equation.c 
	@$(compiler) -o quadratic_equation.o -c quadratic_equation.c 

check: test_quadratic_equation
	@./test_quadratic_equation
	@rm -f test_quadratic_equation

test_quadratic_equation: test_quadratic_equation.c quadratic_equation.c	
	@$(compiler) $(compilation_flags) -o test_quadratic_equation test_quadratic_equation.c quadratic_equation.c -lm	
