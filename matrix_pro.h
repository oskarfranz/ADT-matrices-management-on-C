typedef struct matrix_pro *Matriz;
Matriz matrix(int *matrix, int m, int n);
typedef enum{false, true}bool;

bool equals(Matriz M1, Matriz M2);
void copy_int_array(int *a, int *b, int size);
void swap_numbers(int *n1, int *n2);
void transpose_matrix(Matriz matrix, Matriz result);
void print_matrix(Matriz M1);
void matrix_adder(Matriz M1, Matriz M2, Matriz result);
void matrix_substractor(Matriz M1, Matriz M2, Matriz result);
bool is_symmetric(Matriz M1);
bool is_diagonal(Matriz M1);
bool is_dentity_matrix(Matriz M1);
bool is_triangular(Matriz M1);
