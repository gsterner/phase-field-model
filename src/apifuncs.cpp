#include <stdio.h>
#include "grid.h"

extern "C"
{

  int g_func() {
    return 133;
  }

  void print_array(double *test_array, int array_size) 
  {
    int i;
    copyPointerToVector(test_array, array_size);
    for(i = 0; i < 10; i++)
      {
	printf("%f\n", test_array[i]);
      }
    return;
  }

  void print_matrix(double *matrix_p, int rows, int cols)
  {
    copyPointerToMatrix(matrix_p, rows, cols);
  }


}

