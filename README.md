Matrices managenemt basic documentation:

/////////////GENERALS//////////////

User can freely implement the given functions prototyped on "matrix_pro.h" directly into "main.c".

The functions prototyped on "matrix_pro.h" are declared in "matrix_pro.c" and imported to "main.c" via local library "matrix_pro.h" with the tag "#include "matrix_pro.h"".

The "makefile" file takes care of giving instructions to construct & compile the library specified previously ("matrix_pro.h").

/////////////STATEMENTS DESCRIPTION//////////////

Library "matrix_pro.h" has multiple statements defining functions which will be described here:

STATEMENT 1:

  typedef enum{false, true}bool;
  
JOB:
  Declares bool type.
  
  
STATEMENT 2:
  
  Matriz crear(int *matrix, int m, int n);
  
JOB:
  Equivalent to constructor method. Returns a struct type "Matriz" with the given parameters. It's implementation must be at first in "main.c" to avoid compilation errors.


STATEMENT 3:

  bool equals(Matriz M1, Matriz M2);

JOB:
  Compares 2 given matrices and retuns a bool data that changes depending the result of comparision. For equals returns "true", for non equals returns "false".
  

STATEMENT 4:
  
  void copy_int_array(int *a, int *b, int size);
  
JOB:
  Copies the values in pointer "a" to pointer "b" for "size" values. Does not return anything.
  
  
STATEMENT 5:
  void swap_numbers(int *n1, int *n2);
  
JOB:
  Swaps the values of pointers "n1" and "n2". Equivalent to call "copy_int_array()" with size 1;
  
STATEMENT 6:

  void transpose(Matriz matrix, Matriz result);

JOB:
  Copies the result of swapping columns for raws.
  
void printMatrix(Matriz M1);
void suma_matrix(Matriz M1, Matriz M2, Matriz result);
void resta_matrix(Matriz M1, Matriz M2, Matriz result);
void simetrica(Matriz M1);
bool diagonal(Matriz M1);
