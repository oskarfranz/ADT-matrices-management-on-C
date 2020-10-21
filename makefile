all:test
matrix_pro.o:matrix_pro.c
	gcc	-c	matrix_pro.c	-o	matrix_pro.o
libmatrix.a:matrix_pro.o
	ar	-rv	libmatrix.a	matrix_pro.o
test:libmatrix_pro.a
	gcc	-o	test	main.c	-lmatrix_pro
clean:
	rm -f libmatrix.a matrix_pro.o
