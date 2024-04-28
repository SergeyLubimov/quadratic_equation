
MakefileCC = gcc
CFLAGS = -Wall

check: test_quadratic_equation
	./test_quadratic_equation
	
test_quadratic_equation: test_quadratic_equation.c quadratic_equation.c
	$(CC) $(CFLAGS) -o test_quadratic_equation test_quadratic_equation.c quadratic_equation.c -lm
	

	
