#include <stdio.h>
#include <iostream>
#include "grid.h"
#include "physics.h"
using std::cout;
//using Grid::Grid;

void copyPointerToMatrixCpp(double *matrix_p, int rows, int cols)
{
  Grid grid = Grid(matrix_p, rows, cols);
  cout << "-------------" << std::endl;
  grid.printMatrix();
  cout << "-------------" << std::endl;
  grid.setAt(0,0,0.3333);
  grid.printMatrix();
  cout << "-------------" << std::endl;
  grid.copyMatrixToPointer(matrix_p);
  // cout << "laplace " << laplace(0.3,0.1,0.1,0.1,0.1) << std::endl;
}


extern "C"
{

  int g_func() {
    return 133;
  }

  void print_array(double *test_array, int array_size) 
  {
    int i;
    //Grid grid = Grid(); 
    //grid.copyPointerToVector(test_array, array_size);
    for(i = 0; i < 10; i++)
      {
	printf("%f\n", test_array[i]);
      }
    return;
  }

  void print_matrix(double *matrix_p, int rows, int cols)
  {   
    copyPointerToMatrixCpp(matrix_p, rows, cols);
  }


}

