#include "matrix_pro.h"
#include <stdio.h>
#include <stdlib.h>

struct matrix_pro{
  int *matrix;
  int m;
  int n;
};

Matriz matrix(int *matrix, int m, int n){
  Matriz matriz = malloc(sizeof(struct matrix_pro));

  matriz->matrix = matrix;
  matriz->m = m;
  matriz->n = n;

  return matriz;
}

bool equals(Matriz M1, Matriz M2){
  int m = M1->m;
  int n = M1->n;
  int *mat1 = M1->matrix;
  int *mat2 = M2->matrix;
  for(int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      if(*(mat1+i*n+j)!=*(mat2+i*n+j))
        return false;
    }
  }
  return true;
}

void copy_int_array(int *a, int *b, int size){
  for(int i=0;i<size;i++){
    *b = *a;
    a++;
    b++;
  }
}

void swap_numbers(int *n1, int *n2){
  int temp;
  temp=*n1;
  *n1=*n2;
  *n2=temp;
}

void transpose_matrix(Matriz matrix, Matriz result){
  int m = matrix->m;
  int n = matrix->n;
  int *mat1 = matrix->matrix;
  int *resultado = result->matrix;
  copy_int_array(mat1, resultado, m*n);
  if(m!=n) return;
  for(int i=0,aux=1;i<m;i++,aux++){
    for(int j=aux;j<n;j++){
      int *a = resultado+i*n+j;//a->3
      int *b = resultado+j*n+i;//b->-7
      swap_numbers(a, b);
    }
  }
}

void print_matrix(Matriz M1){
  int *Matrix= M1->matrix;
  int m= M1->m;
  int n= M1->n;
  for (int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("%d\t", *(Matrix+i*n+j));
    }
    printf("\n");
  }
}

void matrix_adder(Matriz M1, Matriz M2, Matriz result){
  int *Matrix1= M1->matrix;
  int *Matrix2= M2->matrix;
  int *Matrix_r= result->matrix;
  int m= M1->m;
  int n= M1->n;
  for (int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      *(Matrix_r+i*n+j) = *(Matrix1+i*n+j) + *(Matrix2+i*n+j);
    }
  }
}

void matrix_substractor(Matriz M1, Matriz M2, Matriz result){
  int *Matrix1= M1->matrix;
  int *Matrix2= M2->matrix;
  int *Matrix_r= result->matrix;
  int m= M1->m;
  int n= M1->n;
  for (int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      *(Matrix_r+i*n+j) = *(Matrix1+i*n+j) - *(Matrix2+i*n+j);
    }
  }
}

bool is_symmetric(Matriz M1){
  Matriz transpuesta;
  int valid;
  transpose_matrix(M1,transpuesta);
  if(M1->m != M1->n){ return false;}
  return equals(M1, transpuesta);
}

bool is_diagonal(Matriz M1){
  int *Matrix= M1->matrix;
  int m= M1->m;
  int n= M1->n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(i!=j && *(Matrix+i*n+j) != 0){return false;}
    }
  }
  return true;
}

bool is_dentity_matrix(Matriz M1){
  int m = M1->m;
  int n = M1->n;
  Matriz M2;
  for(int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      if(i == j){ *(M2->matrix+i*n+j) = 1;}
      else {*(M2->matrix+i*n+j) = 0;}
    }
  }
  return equals(M1, M2);
}

bool is_triangular(Matriz M1){
  int *Matrix= M1->matrix;
  int m= M1->m;
  int n= M1->n;
  int valid1;
  int valid2;
  Matriz triangular1;
  Matriz triangular2;
  for(int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      if(i==j){
        *(triangular1->matrix+i*n+j)= *(Matrix+i*n+j);
        *(triangular2->matrix+i*n+j)= *(Matrix+i*n+j);
      } else if (i > j) {
        *(triangular1->matrix+i*n+j)= 0;
        *(triangular2->matrix+i*n+j)= *(Matrix+i*n+j);
      } else{
        *(triangular1->matrix+i*n+j)= *(Matrix+i*n+j);
        *(triangular2->matrix+i*n+j)= 0;
      }
    }
  }
  valid1= equals(M1, triangular1);
  valid2= equals(M1, triangular2);
  if(valid1 ==1){ return true;}
  else{ return false;}

}
