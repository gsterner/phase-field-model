#include <stdio.h>
#include <iostream>
#include "grid.h"
#include "physics.h"
using std::cout;
//using Grid::Grid;

void printInData(double *matrix_p, int rows, int cols, double delta_x, double delta_t, int time_steps)
{
  Grid grid = Grid(matrix_p, rows, cols);
  cout << "-------------" << std::endl;
  grid.printMatrix();
  cout << "-------------" << std::endl;
  cout << "delta_x " << delta_x << std::endl;
  cout << "delta_t " << delta_t << std::endl;
  cout << "time_steps " << time_steps << std::endl;

}

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

  void model_a_integration(double *matrix_p, 
			   int rows, 
			   int cols, 
			   double delta_x,
			   double delta_t,
			   int time_steps)
  {
    printInData(matrix_p, rows, cols, delta_x, delta_t, time_steps);
  }

}

