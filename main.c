#include "matrix_pro.h"
#include <stdio.h>

int main(void) {
  int m1[] = {1,2,3,4,5,6,7,8,9};
  int m2[] = {9,8,7,6,5,4,3,2,1};
  int result[] = {0,0,0,0,0,0,0,0,0};

  Matriz M1 = matrix(m1,3,3);
  Matriz M2 = matrix(m2,3,3);
  Matriz resultado = matrix(result,3,3);

  matrix_adder(M1, M2, resultado);
  printf("\n");
  print_matrix(resultado);

  transpose_matrix(M1,resultado);
  print_matrix(resultado);

  return 0;
}
